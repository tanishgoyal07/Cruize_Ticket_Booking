#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

class display
{
    public:
    void heading()
    {
        cout<<"\t";
        cout<<"\n\n\t\t\t";
        for(int i=0;i<16;i++)
        {
            cout<<"-";
        }
        cout<<" CRUIZZER ";
        for(int i=0;i<16;i++)
        {
            cout<<"-";
        }
        cout<<"\n\n\t\t";
    }
    void pattern()
    {
        int r=4;
        int k=6;
        cout<<"\n";
        for(int i = 1; i <= r; ++i)
        {
            cout<<"\t\t\t\t\t";
            for(int j = 1; j <= i; ++j)
            {
                cout << " ~ ";
            }
            cout << "\n";
        }
        for(int i = r-1; i >= 1; --i)
        {
            cout<<"\t\t\t\t\t";
            for(int j = 1; j <= i; ++j)
            {
                cout << " ~ ";
            }
            cout << endl;
        }
        for(int i = k; i >= 3; --i)
        {
            cout<<"\t\t\t\t";
            for(int space = 0; space < k-i; ++space)
                cout << "  ";

            for(int j = i; j <= 2*i-1; ++j)
                cout << "* ";

            for(int j = 0; j < i-1; ++j)
                cout << "* ";

            cout << endl;
        }
        cout<<"\n\n\t\t\t\t\tOUR AIM:\n";
        cout<<"\n\t The Cruizzer presents easy and accessible services of cruise booking and travels for";
        cout<<"\n\t fun loving tourists. It provides several routes and destinations,filled with their";
        cout<<"\n\t own unique activities and entertainment. It helps the user to compare between multiple ";
        cout<<"\n\t options and fares and book tickets for the most suitable one."<<endl;
    }
};

class information
{
   public: 
   void Main()
    {
        cout<<"\n\n\t\t\t\t\tMAIN MENU:\n";
        cout << "\t\t\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
        cout << "\t\t\t|\t\t\t\t\t|" << endl; 
        cout << "\t\t\t|\tAbout Us         -> 1\t\t|" << endl;
        cout << "\t\t\t|\tBooking Tickets  -> 2\t\t|" << endl;
        cout << "\t\t\t|\tStar Alliance    -> 3\t\t|" << endl;
        cout << "\t\t\t|\tPackages         -> 4\t\t|" << endl;
        cout << "\t\t\t|\tContact Us       -> 5\t\t|" << endl;
        cout << "\t\t\t|\t\t\t\t\t|" << endl;
        cout << "\t\t\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;
        cout << "\n\t\t";
        for (int i=0;i<55;i++)
        {
            cout<<"-";
        }
        cout <<"\nSelect from the above : ";
    }
};

class about
{
    public:
    about()
    {
        ifstream about("about.txt");
        string s;
        if(about.is_open())
        {
            while(getline(about , s))
            {
                cout << "\t" << s << endl;  
            }
            about.close();
        }
    }
};

class booking
{
    public:
    string from , to , date , name , email , phone;
    int adult , child , traveller;
    double charge;
    void ticket_booking()
    {
        cout << "\n\tFill the Booking Details:" << endl;
        cout << "\nName: ";
        cin >> name;
        while(1)
        {
            cout << "\nContact Number: ";
            cin >> phone;
            if(phone.length()!=10)
            {
                cout << "\nInvalid Phone Number...Please Retry" << endl;
            }
            else
            {
                break;
            }
        }
        cout << "\nEmail Id: ";
        cin >> email;
        cout << "\nSource : ";
        cin >> from;
        cout << "\nDetination : ";
        cin >> to;
        cout << "\nDate (dd/mm/yyyy) : ";
        cin >> date;
        cout << "\nNumber of Travellers:" << endl;
        cout << "Adult: ";
        cin>> adult;
        cout<<"Child(below 12): ";
        cin >> child;
        traveller = adult + child;
        charge = cost();
        printReceipt();
    }

    double cost()
    {
        int adult_price = 5000;
        int child_price = 3800;
        double tax;
        double price; 
        if(traveller<5)
        {
            tax = 200;
        }
        else if(traveller>=5 && traveller<10)
        {
            tax = 160;
        }
        else
        {
            tax = 100;
        }
        price = (adult*adult_price) + (child*child_price) + (tax*traveller);
        return price;
    }

    void printReceipt()
    {
        ofstream outf("basic_ticket.txt"); 
        {
            outf << "------------------Cruizzer-----------------" << endl;
            outf << "-------------------Ticket-------------------" << endl;
            outf << "____________________________________________" << endl;
            outf << "\nName:\t\t\t" << name  << endl;
            outf << "Contact:\t\t" << phone  << endl;
            outf << "Email:\t\t\t" << email  << endl;
            outf << "\nSource:\t\t\t" << from << endl;
            outf << "Destination:\t" << to << endl;
            outf << "Date\t\t\t" << date << endl;
            outf << "\nTravellers" << endl;
            outf << "Adult :\t\t\t" << adult << endl;
            outf << "Child :\t\t\t" << child << endl;
            outf << "____________________________________________" << endl;
            outf << "Fare" << endl;
            outf << "Adult:\t\t\t" << "5000 + taxes" << endl;
            outf << "Child:\t\t\t" << "3800 + taxes" << endl;
            outf << "Total Charge:\t " << charge << endl;
            outf << "____________________________________________" << endl;
            outf << "------------------THANK YOU-----------------" << endl;
        }
        outf.close();
    }
    void printTicket()
    {
        cout << "\t\t\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
        cout << "\t\t\t|\t\t\tCruizzer\t\t\t|" << endl; 
        cout << "\t\t\t|\t\t\t\t\t\t\t|" << endl;
        cout << "\t\t\t|\tName         : " << name << "\t\t\t\t|" << endl;
        cout << "\t\t\t|\tContact      : " << phone << "\t\t\t|" << endl;
        cout << "\t\t\t|\tEmail        : " << email << "\t\t|" << endl;
        cout << "\t\t\t|\tSource       : " << from << "\t\t\t\t|" << endl;
        cout << "\t\t\t|\tDestination  : " << to << "\t\t\t\t|" << endl;
        cout << "\t\t\t|\tDate         : " << date << "\t\t\t|" << endl;
        cout << "\t\t\t|\tTravellers\t\t\t\t\t|" << endl;
        cout << "\t\t\t|\tAdult        : " << adult << "\t\t\t\t|" << endl;
        cout << "\t\t\t|\tChild        : " << child << "\t\t\t\t|" << endl;
        cout << "\t\t\t|\t\t\t\t\t\t\t|" << endl;
        cout << "\t\t\t|\tFare         :               \t\t\t|" << endl;
        cout << "\t\t\t|\tAdult        : 5000 + taxes\t\t\t|" << endl;
        cout << "\t\t\t|\tChild        : 3800 + taxes\t\t\t|" << endl;
        cout << "\t\t\t|\tTotal Charge : "<< charge << "\t\t\t\t|" << endl;
        cout << "\t\t\t|\t\t\t\t\t\t\t|" << endl;
        cout << "\t\t\t|\t\t-------THANK YOU-------\t\t\t|" << endl;
        cout << "\t\t\t|\t\t\t\t\t\t\t|" << endl;
        cout << "\t\t\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;
        cout << "\n\t\t";
    }
};

class star_alliance : public booking
{
    public:
    void spcl_book()
    {
        int i,n,total;
        ifstream ptr;
        ptr.open("star_alliance.txt");
        string s;
        if(ptr.is_open())
        {
           while (getline(ptr,s))
           cout << s << endl;
        }
        cin>>i;
        system("CLS");
        cout << "\nFill out the necessary details:";
        cout << "\nName: ";
        cin >> name;
        while(1)
        {
            cout << "\nContact Number: ";
            cin >> phone;
            if(phone.length()!=10)
            {
                cout << "\nInvalid Phone Number...Please Retry" << endl;
            }
            else{
                break;
            }
        }
        cout << "\nEmail Id: ";
        cin >> email;
        cout << "\nDeparting port : ";
        cin >> from;
        cout << "\nDate (dd/mm/yyyy) : ";
        cin >> date;
        if(i==1)
        {
            cout<<"\nNumber of Nights: ";
            cin>>n;
            total=n*40000;
            cout<<"\n\t\t\t  ---- Deck is Successfully Booked for "<<n<<" Nights ----"<<endl;
            print_spcl(total,"Deck");
            spcl_ticket(total,"Deck");
        }
        else if(i==2)
        {
            cout<<"\nNumber of Nights: ";
            cin>>n;
            total=n*30000;
            cout<<"\n\t\t\t  ---- Lobby is Successfully Booked for "<<n<<" Nights ----"<<endl;
            print_spcl(total,"Lobby");
            spcl_ticket(total,"Lobby");
        }
        else if(i==3)
        {
            cout<<"\nNumber of Nights: ";
            cin>>n;
            total=n*35000;
            cout<<"\n\t\t\t  ---- Pool is Successfully Booked for " << n << " Nights ----"<<endl;
            print_spcl(total,"Pool");
            spcl_ticket(total,"Pool");

        }
        else if(i==4)
        {
            cout<<"\nNumber of Days: ";
            cin>>n;
            total=n*25000;
            cout<<"\t\t\t  ---- Front Deck is Successfully Booked for "<<n<<" Days ----"<<endl;
            print_spcl(total,"Front_Deck");
            spcl_ticket(total,"Front_Deck");
        }
        else if(i==5)
        {
            cout<<"\nNumber of Persons: ";
            cin>>n;
            total=n*3500;
            cout<<"\t\t\t  ---- Lounge is Successfully Booked for "<<n<<" Persons ----"<<endl;
            print_spcl(total,"Lounge");
            spcl_ticket(total,"Lounge");
        }
    }
    void spcl_ticket(int total , string s)
    {
        cout << "\t\t\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
        cout << "\t\t\t|\t\t\tCruizzer\t\t\t|" << endl; 
        cout << "\t\t\t|\t\t\t\t\t\t\t|" << endl;
        cout << "\t\t\t|\tName         : " << name << "\t\t\t\t|" << endl;
        cout << "\t\t\t|\tContact      : " << phone << "\t\t\t|" << endl;
        cout << "\t\t\t|\tEmail        : " << email << "\t\t|" << endl;
        cout << "\t\t\t|\tPort         : " << from << "\t\t\t\t|" << endl;
        cout << "\t\t\t|\tDate         : " << date << "\t\t\t|" << endl;
        cout << "\t\t\t|\tTotal Charge : "<< total << "\t\t\t\t|" << endl;
        cout << "\t\t\t|\t\t\t\t\t\t\t|" << endl;
        cout << "\t\t\t|\t\tYour " << s << " is booked\t\t\t|" << endl;
        cout << "\t\t\t|\t\t-------THANK YOU-------\t\t\t|" << endl;
        cout << "\t\t\t|\t\t\t\t\t\t\t|" << endl;
        cout << "\t\t\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;
        cout << "\n\t\t";
    }

    void print_spcl(int total,string s)
    {
        ofstream outf("star_ticket.txt"); 
        {
            outf << "------------------Cruizzer-----------------" << endl;
            outf << "-------------------Ticket-------------------" << endl;
            outf << "____________________________________________" << endl;
            outf << "Your " << s << " is booked" << endl;
            outf << "\nName:\t\t\t" << name  << endl;
            outf << "Contact:\t\t" << phone  << endl;
            outf << "Email:\t\t\t" << email  << endl;
            outf << "\nPort:\t\t\t" << from << endl;
            outf << "Date\t\t\t" << date << endl;
            outf << "____________________________________________" << endl;
            outf << "Total Charge:\t " << total << endl;
            outf << "____________________________________________" << endl;
            outf << "------------------THANK YOU-----------------" << endl;
        }
        outf.close();
    }
};

class packages
{
    public:
    void display_package()
    {
        string s;
        int x,y;
        ifstream ptr;
        ptr.open("package.txt");
        if(ptr.is_open())
        {
            while(getline(ptr,s))
            cout<<s<<endl;
        }
        cin>>x;
        system("CLS");
        if(x==1)
        {
            ifstream p1;
            p1.open("family.txt");
            if(p1.is_open())
            {
                while(getline(p1,s))
                cout<<s<<endl;
            }
            cin>>y;
            system("CLS");
            if(y==1)
            {
                cout<<"\nYour Family booking package 1 is confirmed:\nTotal Price: 1,99,990/-"<<endl;
            }
            else if(y==2)
            {
                cout<<"\nYour Family booking package 2 is confirmed:\nTotal Price: 1,75,000/-"<<endl;
            }
        }
        else if(x==2)
        {
            ifstream p2;
            p2.open("couple.txt");
            if(p2.is_open())
            {
                while(getline(p2,s))
                cout<<s<<endl;
            }
            cin>>y;
            system("CLS");
            if(y==1)
            {
                cout<<"\nYour Couple special package 1 is confirmed:\nTotal Price: 1,45,000/-"<<endl;
            }
            else if(y==2)
            {
                cout<<"\nYour Couple special package 2 is confirmed:\nTotal Price: 2,75,000/-"<<endl;
            }
        }
        else if(x==3)
        {
            ifstream p3;
            p3.open("corporate.txt");
            if(p3.is_open())
            {
                while(getline(p3,s))
                cout<<s<<endl;
            }
            cin>>y;
            system("CLS");
            if(y==1)
            {
                cout<<"\nYour Corporate special package 1 is confirmed:\nTotal Price: 2,07,000/-"<<endl;
            }
            else if(y==2)
            {
                cout<<"\nYour Corporate special package 2 is confirmed:\nTotal Price: 3,45,000/-"<<endl;
            }
        }
    }
};

class contact_us : public booking
{
    public:
    void contact()
    {
        string s;
        string x;
        ifstream ptr;
        ptr.open("contact.txt");
        if(ptr.is_open())
        {
            while(getline(ptr,s))
            cout << s << endl;
        }
        cin >> x;
        if(x=="Yes" || x=="yes")
        {
            system("CLS");
            enquiry();
        }
    }

    void enquiry()
    {
        string country , topic , send ;
        cout << "\nFill the Enquiry Form:";
        cout << "\nName: ";
        cin >> name;
        while(1)
        {
            cout << "\nContact Number: ";
            cin >> phone;
            if(phone.length()!=10)
            {
                cout << "\nInvalid Phone Number...Please Retry" << endl;
            }
            else
            {
                break;
            }
        }
        cout << "\nEmail Id: ";
        cin >> email;
        cout << "\nCountry: ";
        cin >> country;
        cout << "\nSelect Topic: ";
        cin >> topic;
        cout << "\nType SEND to send us a query: ";
        cin >> send;
        if(send=="SEND" || send=="send" || send=="Send")
        {
            string y = "start https://mail.google.com/mail/u/0/#inbox?compose=new";
            system(y.c_str());
        }
    }
};

int main()
{
    system("color 7C");
    display D;
    D.heading();
    D.pattern();
    information B;
    char tm='0';
    char home='*';
    int choice;
    while(tm!='#')
    {
        if(home=='*')
        {
            B.Main();
            cin >> choice;
            system("CLS");
            if(choice==1)
            {
                about ab;
                cout << "\nPress * for Main Menu / # for program termination : ";
                cin >> home;
                system("CLS");
            }
            else if(choice==2)
            {
                booking bk;
                bk.ticket_booking();
                cout << "\nYour ticket is successfully booked" << endl;
                cout << "Press any number for ticket print ";
                cin >> choice;
                bk.printTicket();
                cout << "\nPress * for Main Menu / # for program termination : ";
                cin >> home;
                system("CLS");
            }
            else if(choice==3)
            {
                star_alliance star;
                star.spcl_book();
                cout << "\nPress * for Main Menu / # for program termination : ";
                cin >> home;
                system("CLS");
            }
            else if(choice==4)
            {
                packages pkg;
                pkg.display_package();
                cout << "\nPress * for Main Menu / # for program termination : ";
                cin >> home;
                system("CLS");
            }
            else if(choice==5)
            {
                contact_us cu;
                cu.contact();
                cout << "\nPress * for Main Menu / # for program termination : ";
                cin >> home;
                system("CLS");
            }
            else
            {
                cout << "Invalid Choice...." << endl;
                cout << "\nPress * for Main Menu / # for program termination : ";
                cin >> home;
                system("CLS");
            }
        }
        else if(home=='#')
        {
            cout << "\n------------Thank You for choosing CRUIZZERR------------" << endl;
            tm='#';
        }
        else
        {
            cout << "\nINVALID CHOICE......";
            cout << "\nTerminating the program.....";
            cout << "\n------------Thank You for choosing CRUIZZER------------" << endl;
            tm='#';
        }
    }
    return 0;
}
