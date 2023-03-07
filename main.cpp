#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int total_borrowed( int );
struct book
{
    int id[100] ;
    string name[100] ;
    int quantity[100] ;
    int len ;
    string prefix[50] ;
    book()
    {
        len = 0 ;
    }
    bool add_end( string n , int ids , int quan )
    {
        if(len == 100)
        {
            cout <<"You can not add another book ^_^ \n" ;
            return false ;
        }
        name[len] = n ;
        id[len] = ids ;
        quantity[len] = quan ;
        ++len ;
        return true ;
    }

    void print_id()
    {
        for(int j = 0 ; j < len ; j++){

            for( int i = 0 ; i < len ; i++)
            {
                if( id[j] < id[i])
                {
                    int t_id = id[j] ;
                    id[j] = id[i] ;
                    id[i] = t_id ;
                    string t_name = name[i] ;
                    name[i] = name[j] ;
                    name[j] = t_name ;
                    int t_quantatiy = quantity[i] ;
                    quantity[i] = quantity[j] ;
                    quantity[j] = t_quantatiy ;
                }
            }
        }
        for( int i = 0 ; i < len ; i++)
        {
            cout <<" id = " << id[i] <<" name = " << name[i] <<" total_quantity = " << quantity[i] << "\n" ;
        }
    }
    void print_name()
    {
        for(int j = 0 ; j < len ; j++){
            for( int i = 0 ; i < len ; i++)
            {
                if( name[j] < name[i])
                {
                    int t_id = id[j] ;
                    id[j] = id[i] ;
                    id[i] = t_id ;
                    string t_name = name[i] ;
                    name[i] = name[j] ;
                    name[j] = t_name ;
                    int t_quantatiy = quantity[i] ;
                    quantity[i] = quantity[j] ;
                    quantity[j] = t_quantatiy ;
                }
            }
        }
        for( int i = 0 ; i < len ; i++)
        {
            cout <<" id = " << id[i] <<" name = " << name[i] <<" total_quantity = " << quantity[i] << "\n" ;
        }

    }
    void search_for_prefix()
    {
        string str , new_str , str_temp ;
        int index = 0  ;
        cout <<"Enter Book's Name Prefix : " ;
        cin >> str ;
        int str_len = str.size();
        for( int i = 0 ; i < len ; i++){
            str_temp = name[i] ;
            new_str ="";
            for( int j = 0 ; j < str_len ; j++)
                {

                    new_str+=str_temp[j] ;
                }
            if( str == new_str)
            {
                prefix[index] = name[i] ;
                index ++ ;
            }
        }

        if( index == 0 )
        {
            cout <<"Not Book With Such prefix \n";
        }
        else
            for(int k = 0 ; k < index ; k++)
                cout << prefix[k] << endl;
    }


};

struct user
{
    int id ;
    int len ;
    int borrowed ;
    string name ;
    string borrow_book[10] ;
    user()
    {
        len = 0 ;
        borrowed = 0 ;
    }
};
struct Library_system
{
    book b1  ;
    user users[100] ;
    int new_ids[50] ;
    string borrowed_name[50] ;
    int len = 0 ;
    void print_borrow_book(string us , string brr_book[]);

    int show_menue()
    {
        int choice;
        choice = -1 ;
        while(choice == -1){
        cout <<"1-Add_Book\n" ;
        cout <<"2-Search_Book_By_Prefix\n";
        cout <<"3-Print_Who_Borrowed_Book_By_Name\n";
        cout <<"4-Print_Library_By_Id\n";
        cout <<"5-Print_Library_By_Name\n";
        cout <<"6-Add_User\n";
        cout <<"7-User_Borrow_Book\n";
        cout <<"8-User_Return_Book\n";
        cout <<"9-Print_User\n";
        cout <<"10-Print\n";
        cout <<"11-Exit\n\n";
        cout <<"Enter your choice [1 - 10] : " << endl;
        cin >> choice ;
        if(!(choice>=1 && choice <= 10))
            {
                cout <<"Invalid Choice !\n";
                choice = -1 ;
            }
    }
    return choice ;
    }

    // 2

    void Add_User()
    {
        string name ;
        int id ;
        cout <<"Enter User's Name , Id : \n " ;
        cin >> name  >> id ;
        users[len].name = name ;
        users[len].id = id ;
        len++;

    }
    int total_borrowed( int in)
    {
        int i = 0 ;
        while(users[in].borrow_book[i] !="" )
        {
            i++;
        }
        return i ;
    }
    void borrowed_names()
    {
        string name ;
        int k = 0 ;
        cout <<"Enter Book Name : \n " ;
        cin >> name ;
        for( int i = 0 ; i < len ; i++)
        {
            for( int j = 0 ; j < find_ids(i) ; j++){
                if( name == users[i].borrow_book[j]){
                    borrowed_name[k] = users[i].name ;
                    k++ ;
                    break ;
                }
            }
        }
        if( k == 0)
            cout <<"Invalid Book name \n " ;
        else
            for( int i = 0 ; i < k ; i++)
                cout << borrowed_name[i] <<"\n";
        cout <<"\n";
    }

    void Print_Library_By_Id()
    {
        b1.print_id() ;
    }

    void sort_ids(int x)
    {
      //  cout << find_ids(x) << endl ;

        for( int i = 0 ; i < find_ids(x) ; i++)
        {
            for( int j = i + 1 ; j < find_ids(x) ; j++)
            {
                if( new_ids[i] > new_ids[j])
                {
                 //   cout <<"Inner if ! " << endl;
                    int t = new_ids[i] ;
                    new_ids[i] = new_ids[j] ;
                    new_ids[j] = t ;
                   // cout << "new_ids[i] = " << new_ids[i] << endl;
                    //cout << "new_ids[j] = " << new_ids[j] << endl;
                   // swap(new_ids[i] , new_ids[j]) ;
                }
            }
        }

        for( int i = 0 ; i < find_ids(x) ; i++)
            cout << new_ids[i] << "   " ;

        cout <<"\n";


    }
    void Return_Book()
    {
        int val = 0  , p = -1 , t;
        string user_name , book_name ;
        cout <<"Enter user name , book name\n " ;
        cin >> user_name >> book_name ;
        for( int i = 0 ; i < len ; i++)
        {
            if( user_name == users[i].name)
                p = i ;
        }
        if( p == -1){
            cout <<"User " << user_name << "Not Borrow  " << book_name <<"\n" ;
            return ;
        }
        else
        {
            for( int j = 0 ; j < find_ids(p) ; j++)
            {
                if( users[p].borrow_book[j] == book_name){
                    t = j ;
                    val++ ; // for save j
                    break ;
                    //users[p].borrow_book[j] == "" ;

                }
            }

        if( val == 0 ){
            cout << book_name << " Not Borrowed With " << users[p].name <<"\n" ;
            return ;
        }
        else
        {
            for( int k = t ; k < find_ids(p) - 1 ; k++)
            {
                users[p].borrow_book[k] = users[p].borrow_book[k+1] ;
                new_ids[k] = new_ids[k+1] ;


            }

            users[p].borrow_book[find_ids(p)-1]="";

        }
        }


    }
   void  print_new_ids(int x)
    {
       /* for(int i = 0 ; i < find_ids(x) ; i++)
            cout << new_ids[i] <<" " ;
        cout <<"\n" ; */
        int s = find_ids(x) ;
        cout <<"s = " << s << endl;
        cout <<"Before sorting : " << endl;
        for( int i = 0 ; i < find_ids(x) ; i++)
            cout << new_ids[i] << "   " ;

        sort( new_ids , new_ids + s) ;

        for( int i = 0 ; i < find_ids(x) ; i++)
            cout << new_ids[i] << "   " ;

        cout <<"\n";
    }

    void Print_User()
    {
        for(int i = 0 ; i < len ; i++ ){
          cout <<" User = " << users[i].name <<" Id = " << users[i].id <<" Borrowed_book = " << total_borrowed(i)  << " Borrowed Book Ids = "   ;
          sort_ids(i) ;
        }
    }

    void User_Borrow_Book()
    {
        string name , book_name;
      //  int counter = 0 ;
        cout <<"Enter user'name , book_name : \n ";
        cin >> name >> book_name ;
        for( int i = 0 ; i <  len ; i ++)
        {
            int s = 0 ;

            if(name == users[i].name)
            {
                bool v = true ;
                int k = 0 ;
                while(v){

                    if(users[i].borrow_book[k] ==""){
                        users[i].borrow_book[k] =book_name ;
                        v = false ;
                    }
                    k++;
                    s++;
                }
            }
            if( s != 0)
                break ;
            if(i == len -1 && s == 0 )
                cout <<"This user is not found to add book for him \n " ;

        }

    }

    int Size_of_borrow_book( int i)
    {
        bool b = true ;
        int z = 0 , k = 0 ;
        while(b)
        {
            if(users[i].borrow_book[k] !=""){
                z++;
                k++;
            }
            else
                b= false ;
        }
        return z ;
    }

/*    void print_borrow_book(string us , string brr_book[])
    {
        for( int i = 0 ; i < Size_of_borrow_book(i) ; i++ )
            cout << brr_book[i] << "   " ;
        cout << "\n";

    }*/
   void PRINT()
    {

        for( int i = 0 ; i < len ; i++ )
        {
        bool b ;
        b= true ;
        int k = 0 ;
        while(b)
        {
            if(users[i].borrow_book[k] != "")
                cout << users[i].borrow_book[k] << "   " ;
            else
                b= false ;
            k++;
        }
        cout <<"\n" ;

    }
    }





    int find_ids( int p )
    {
        int r = 0 ;
        int k = 0 ;
      //  int res = Size_of_borrow_book(p) ;
       // for( int i = p ; i < res  ; i++)
        //{
            for( int j = 0 ; j <b1.len ; j++)
            {
                if(users[p].borrow_book[k] == b1.name[j])
                {
                    new_ids[r] = b1.id[j];
                    r++ ;
                    k++ ;
                    j = -1 ;
                }
           //     if( k  )
             //       k++;

            }

        return r ;
    }
    void Add_Book()
    {
        string name;
        int id , quantity ;
        cout <<"Enter book's Name , Id , Quantity \n";
        cin >> name >> id >> quantity ;
        bool ele ;
        ele = b1.add_end(name , id , quantity) ;
        if( ele == false)
            return ;
        cout <<"Book your added successfully ^_^\n";
    }



    void Print_Library_By_Name()
    {
        b1.print_name() ;
    }

    // 3
    void run()
    {
        while(true)
        {
            int choice = show_menue() ;
            if(choice == 1)
                Add_Book();
            else if(choice == 2)
                b1.search_for_prefix() ;

            else if(choice == 3)
                borrowed_names() ;

            else if( choice == 4)
               Print_Library_By_Id();

            else if(choice == 5)
                Print_Library_By_Name() ;

            else if(choice == 6)
                Add_User();

            else if(choice == 7)
                User_Borrow_Book() ;

            else if( choice == 8)
                Return_Book() ;

            else if(choice == 9)
                Print_User();

            else if( choice == 10)
                PRINT() ;
            else
                break ;
        /*






            else if(choice == 9)
              //  Print_User();

*/
        }
    }
};
int main()
{

    Library_system Library ;
    Library.run();

    return 0;
}
