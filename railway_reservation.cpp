#include<bits\stdc++.h>
#include<stdlib.h>
#include<sstream>
#include<windows.h>
using namespace std;
void login();
void forgot();
void signup();
void homepage();
void submain();
void status();
void book();
void cancel();
void greivance();
void feedback();
void book1(string, string, string );

class pasenger{
  protected :
      int pnr;
      std::string name,gen,age,train,srn;

  public :
    void getdata(string train,string srn,int i){
      cout<<"\nEnter passenger "<<i+1<<" name : ";
      cin>>name;
      cout<<"\nGender : (M/F) ";
      cin>>gen;
      cout<<"\nEnter age : ";
      cin>>age;
      this->train=train;
      this->srn=srn;
    }
    void genpnr(){
      ifstream pnrg("pnr.txt");
      while(pnrg>>pnr)
      {

      }
      pnr++;
      pnrg.close();
      ofstream pnrs("pnr.txt");
      pnrs<<pnr;
    }
    int getpnr()
    {
      return pnr;
    }
  };

void file(pasenger p){
  ofstream pas("pasdetails.txt",ios::app);
  pas.write((char *)&p,sizeof(p));
  pas.close();
}



int main()
{
  system("cls");
printf("\t\t=====================================================================================\n");
printf("\t\t|                                                                                   |\n");
printf("\t\t|                            -----------------------------                          |\n");
printf("\t\t|                           TRAIN TICKET RESERVATION SYSTEM                         |\n");
printf("\t\t|                            -----------------------------                          |\n");
printf("\t\t|                                                                                   |\n");
printf("\t\t|                                                                                   |\n");
printf("\t\t|                                                                                   |\n");
printf("\t\t|                                 BROUGHT TO YOU BY                                 |\n");
printf("\t\t|                                 | Ujjwal Kumar  |                                 |\n");
printf("\t\t|                                                                                   |\n");
printf("\t\t=====================================================================================\n\n\n");
cout<<"\t\tPress Enter to continue : ";
cin.get();
        submain();
        return 0;
}

void signup()
{
        system("cls");
        string reguser,pp,regpass,conpass,name,occupation,address,email,age,phone;
        getline(cin,pp);
        cout<<"Enter the username :";
        getline(cin,reguser);
        cout<<"\nEnter the password :";
        getline(cin,regpass);
        cout<<"\nConfirm password : ";
        getline(cin,conpass);
        if(conpass!=regpass)
        {
          cout<<"\nPassword does not match please confirm again\n";
          cout<<"\nConfirm password : ";
          cin>>conpass;
          }
          cout<<"\nEnter your full name : ";
          getline(cin,name);
          cout<<"\nEnter your age in years : ";
          getline(cin,age);
          cout<<"\nEnter your email : ";
          getline(cin,email);
          cout<<"\nEnter phone number : ";
          getline(cin,phone);
          cout<<"\nEnter your permanent address : ";
          getline(cin,address);
          cout<<"\nEnter occupation : ";
          getline(cin,occupation);

        ofstream reg("database.txt",ios::app);
        reg<<reguser<<","<<regpass<<","<<conpass<<","<<name<<","<<age<<","<<email<<","<<phone<<","<<address<<","<<occupation<<endl;
        system("cls");
        cout<<"\nRegistration Successful\n";
        cout<<"We are glad that you registered with us";
        cout<<"\n Please login with your details to enjoy exciting features of our system ";
        cin.get();
        cin.get();
        main();


        cout<<"\n\n";

}

void homepage()
{

        system("cls");
        cout<<"                     *************************\n\n";
        cout<<"                      Welcome to Homepage of our system                               \n\n";
        cout<<"      ********        MENU        ***********\n\n";
        int choice;
        cout<<"Select any of the option from the menu :\n \n";
        cout<<"Enter 1. To check Train Availability and booking tickets "<<endl;
        cout<<"Enter 2. To check PNR status "<<endl;
        cout<<"Enter 3. For tickets cancellation "<<endl;
        cout<<"Enter 4. For grievance registration "<<endl;
        cout<<"Enter 5. To fill Feedback form "<<endl;
        cout<<"Enter 6. To Return to main menu "<<endl;
        cout<<"Enter 7. To exit "<<endl<<endl;
        cout<<"\nEnter your choice : ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
        case 1:
                book();
                break;

        case 2:

                status();
                break;
        case 3:
                cancel();
                break;
        case 4:
                greivance();
                break;
        case 5:
                feedback();
                break;
       case 6:
                main();
                break;
       case 7:
                cout<<"Thanks for using this Railway Reservation System. \nThis program is created by Ujjwal Kumar.\n\n";
                cin.get();
                exit(0);
                break;

        default:

                cout<<"\nYou've made a wrong choice by mistake, please enter correct choice again!\n"<<endl;
                cin.get();
                cin.get();
                  system("cls");
                homepage();
        }
}



void login()
{
        int count;
        string user,pass,u,p,cp,nm,em,ph,addrs,occ,ag;
        system("cls");
        cout<<"Please enter the following details"<<endl;
        cout<<"USERNAME : ";
        cin>>user;
        cout<<"PASSWORD : ";
        cin>>pass;
        ifstream input("database.txt");
        string line;
        while(getline(input,line))
        {
          stringstream ss(line);
          getline(ss,u,',');
          getline(ss,p,',');
          getline(ss,cp,',');
          getline(ss,nm,',');
          getline(ss,ag,',');
          getline(ss,em,',');
          getline(ss,ph,',');
          getline(ss,addrs,',');
          getline(ss,occ);
                if(u==user && p==pass)
                {
                        count=1;
                        system("cls");

                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHello "<<user<<"\nLOGIN SUCCESS\nWe're glad that you're here.\nThanks for logging in!\n";
                //cin.get();
                //cin.get();
                Sleep(2000);
                system("cls");
                homepage();
        }
        else
        {
                system("cls");
                cout<<"\nLOGIN ERROR\nPlease check your username and password again!\n\n";
                cin.get();
                cin.get();
                main();
        }
}
void submain()
{
        int choice;
        system("cls");
        cout<<"\n\n WELCOME TO THE MENU OF OUR SYSTEM\n\n\n";
                cout<<"Select any of the option ->\n";
                cout<<"Type 1 for LOGIN"<<endl;
                cout<<"Type 2 if you FORGOT ACCOUNT details "<<endl;
                cout<<"Type 3 for New user SIGNUP "<<endl;
                cout<<"Type 4 to EXIT "<<endl;
                cout<<"\nEnter your choice : ";
                cin>>choice;
                cout<<endl;
                switch(choice)
                {
                case 1:
                        login();
                        break;

                case 2:

                        forgot();
                        break;
                case 4:

                        cout<<"Thanks for using this Railway Reservation System. \nThis program is created by roll numbers 02,07,12,17,22,27,32 (CSE).\n\n";
                        cin.get();
                        exit(0);
                        break;
                case 3:
                        signup();
                        break;
                default:
                        system("cls");
                        cout<<"\nYou've made a wrong choice by mistake, please enter correct choice again!\n"<<endl;
                        submain();
                }
}
void forgot()
{
        int ch;
        system("cls");
        cout<<"Forgot anything? We're here for help\n\n";
        cout<<"Type 1. to Search your id by username"<<endl;
        cout<<"Type 2. to Search your id by password"<<endl;
        cout<<"Type 3. for Main menu\n\n"<<endl;
        cout<<"Enter your choice : \n";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\nEnter your remembered username :";
                        cin>>searchuser;
                        ifstream searchu("database.txt");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                        break;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\n Account found\n";
                                cout<<"\nYour password is "<<sp<<endl;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                system("cls");
                                cout<<"\nSorry, Your userID is not found in our database\n\n";
                                cout<<"\n Try again by filling correct details\n";
                                cin.get();
                                cin.get();
                                forgot();
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nEnter the remembered password :";
                        cin>>searchpass;

                        ifstream searchp("database.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                        break;
                                }
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\nYour password is found in the database \n";
                                cout<<"\nYour Id username is : "<<su2<<endl;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                system("cls");
                                cout<<"Sorry, We cannot found your password in our database \n\n";
                                cout<<"\n Please try again by filling correct details \n";
                                cin.get();
                                cin.get();
                                forgot();
                        }
                        break;
                }
                case 3:
                {
                        cin.get();
                        system("cls");
                        main();
                        break;
                }
                default:
                        system("cls");
                        cout<<"\nSorry, You entered wrong choice. Kindly try again\n"<<endl;
                        forgot();
        }
}
void book()
{
   system("cls");
   cout<<"                      *************************\n\n";
   cout<<"                   Welcome to Booking page of our system            \n\n";
   cout<<"*******            Booking Interface       ********\n\n";

//    cout<<"Locations currently in our train database: \n";
//         FILE * fp;
//     fp = fopen("trainsdetails.txt","r");
//     char files[100];
//     while(!feof(fp)){
//         fgets(files,100,fp);
//         puts(files);
//     }
//     fclose(fp);


   string bs,ds;
   cout<<"\nEnter your boarding station : ";
   cin>>bs;
   cout<<"\n\nEnter your destination station : ";
   cin>>ds;
/*   cout<<"\n\nEnter your travel date : ";
   cin>>date;
   */
   system("cls");
   cout<<"\n\n Trains list for given stations is \n\n ";
    string train,fare,src,des,srn;
   ifstream input("trainsdetails.txt");
   string line;
   cout<<"Serial No "<<"\tTrain Name "<<"\tFare for 1 person\n";
   while(getline(input,line))
   {
     stringstream ss(line);
     getline(ss,srn,',');
     getline(ss,train,',');
     getline(ss,fare,',');
     getline(ss,src,',');
     getline(ss,des,',');
     if((src==bs || src==ds) && (des==ds || des==bs))
        cout<<"  "<<srn<<"\t\t"<<train<<"\t   "<<fare<<endl;
  }
        string ch;
        cout<<"\n\nEnter serial no. of the train to book seat(s) \n ";
        cin>>ch;
        book1(ch, bs, ds);
}

void book1(string ch, string bs, string ds)
{
  system("cls");
  int no,i,fare;
  string train,srn,f;
  ifstream input("trainsdetails.txt");
  string line;
  while(getline(input,line))
  {
    stringstream ss(line);
    getline(ss,srn,',');
    getline(ss,train,',');
    getline(ss,f,',');
    if(srn==ch)
      break;

  }
  cout<<"How many tickets you want to book : ";
  cin>>no;
  int pnrfinal;
  for(i=0;i<no;i++)
  {
    pasenger p;
    p.getdata(train,srn,i);
    p.genpnr();
        pnrfinal=p.getpnr();

  fare=stoi(f);
  fare=fare*(i+1);

  file(p);

}
char c;
cout<<"Please confirm booking by [y/n] \n";
cin>>c;
if(c=='y')
{system("cls");
cout<<"*************************\n\n";
cout<<"                 Welcome to Payment page of our system                               \n\n";
cout<<"*******        Payment Interface       ******\n\n";
int payment, flag=0;
while(payment!=fare)
{
cout<<"\nTotal fare of "<<no<<" ticket(s) is Rs. "<<fare<<endl;
cout<<"\nEnter amount to pay the total fare and confirm your booking : Rs. ";
cin>>payment;
if(payment==fare)
        flag=1;
// cout<<"\n\nPress any key to confirm the payment\n\n";
// cin.get();
// cin.get();
if(flag)
{
        system("cls");
        // cout<<bs<<" "<<ds<<endl;
        // cout<<"\n*----------------------\nTicket Reservation Successful\n*----------------------\n\n";
        printf("\t\t=====================================================================================\n");
        printf("\t\t|                           --------------------------------                        |\n");
        printf("\t\t|                                    Railway Ticket                                 |\n");
        printf("\t\t|                          Wishing you a happy and safe journey                     |\n");
        printf("\t\t|                            -----------------------------                          |\n");
        printf("\t\t|                                                          PNR - %d               |\n", pnrfinal);
        cout<<"\t\t|                       "<<bs<<"         -------->         "<<ds<<"                  |\n";
        printf("\t\t|                                                                                   |\n");
        printf("\t\t|                             Passenger(s) Permitted - %d                            |\n", no);
        printf("\t\t|                                                                                   |\n");
        printf("\t\t|                                  Fare - Rs. %d.00                               |\n", fare);
        printf("\t\t|                                                                                   |\n");
        printf("\t\t=====================================================================================\n\n\n");

        cout<<"\n\nSave this ticket for future reference...\n";
        cout<<"\nRedirecting to homepage in 5 seconds...\n";
        Sleep(5000);
        homepage();
}
else
{
        system("cls");
        cout<<"\nPayment was not successful! Please make sure you are paying the correct fare.\n";
}
}
}
else if(c=='n')
homepage();
else
{cout<<"You entered wrong input you are redirected to main menu";
cin.get();
}

}

void cancel()
{
  system("cls");
  int x;
  cout<<"*************************\n\n";
  cout<<"                 Welcome to Ticket cancellation page of our system                               \n\n";
  cout<<"*******        Ticket cancellation Interface       ******\n\n";
  cout<<"\nPlease enter your pnr no. for cancellation : ";
  cin>>x;
  pasenger p;
     int f=0;
     ifstream fout("pasdetails.txt",ios::binary|ios::app);
     ofstream fin("pasdetails1.txt",ios::binary|ios::app);
     fout.read((char *)&p,sizeof(p));//reading old file
     while(fout)
     {
       if(p.getpnr()!=x)//checking pnr
        fin.write((char *)&p,sizeof(p));
        else
       {
           cout<<"Your Above ticket is being deleted:\n"<<"Amount refunded: Rs 200\n";
           f++;
       }
       fout.read((char *)&p,sizeof(p));
     }
     if(f==0)//if f==0,pnr not found
      cout<<"\nTicket not found\n";
     fout.close();
     fin.close();
     remove("pasdetails.txt");//deleting old file
     rename("pasdetails1.txt","pasdetails.txt");//renaming new file
     cin.get();
     cin.get();
     homepage();

}
void status()
{
        int x;
        cout<<"\nPlease enter your pnr no. for checking status : ";
        cin>>x;
  pasenger p;
     int f=0;
     ifstream fout("pasdetails.txt",ios::binary|ios::app);
     fout.read((char *)&p,sizeof(p));//reading old file
     while(fout)
     {
       if(p.getpnr()==x)//checking pnr
          f++;

       fout.read((char *)&p,sizeof(p));
     }
     if(f==0)//if f==0,pnr not found
      cout<<"\nTicket status : Cancelled\n";
      else
      cout<<"\nTicket status: Confirmed!\n";
      fout.close();
     cin.get();
     cin.get();
     homepage();
}
void greivance()
{
          system("cls");
    cout<<"***************************************************************************************************\n\n";
    cout<<"                              Welcome to Grievance Registration Page                               \n\n";
    cout<<"*********                        Let us see how we can help you!                       ************\n\n";
    string gr;
    int t;
    cout<<"Select the type of grievance \n";
    cout<<"1. If your seat got confirmed but still TTE does not allot seat to you \n";
    cout<<"2. No refund of money on cancellation of train \n";
    cout<<"3. Unlearned train compartment and washroom \n";
    cout<<"4. Demand of bribery by the railway officials \n";
    cout<<"5. Not getting refund after the Cancellation of ticket \n";
    cout<<"6. Theft incidents in the compartment \n";
    cout<<"7. Others \n";
    cin>>t;
    string refno ="RE";
    system("cls");
    cout<<"      *************************\n";
    cout<<" Grievance Registration             Reference number:"<<refno<<t<<"\n \n";
    string pp;
    getline(cin,pp);
    switch(t)
    {
        case 1:
            cout<<"Kindly write down your problem briefly in this section \n";
            getline(cin,gr);
            break;
        case 2:
            cout<<"Our system takes full responsibility regarding the revenue and assures fair work \n";
            cout<<"Kindly write down all the necessary details regarding the pending transaction or refund \n";
            getline(cin,gr);
            break;
        case 3:
            cout<<"Our Railway system always welcomes suggestions and complains regarding the services \n";
            cout<<"Kindly write down your problem briefly \n";
            getline(cin,gr);
            break;
        case 4:
            cout<<"Taking and giving bribe is an illegal activity, Our Railway System is strictly against such offences \n";
            cout<<"Kindly write down your problem briefly here\n";
            getline(cin,gr);
            break;
        case 5:
            cout<<"Our system takes full responsibility regarding cancellation of tickets \n";
            cout<<"Kindly write down all the necessary details regarding the pending transaction or refund \n";
            getline(cin,gr);
            break;
        case 6:
            cout<<"We are highly against Crimes and ill-practices followed by people \n";
            cout<<"We assure you that our Department will assist you in every possible way if something untoward has happened \n";
            cout<<"Kindly write down your problem briefly \n";
            getline(cin,gr);
            break;
        case 7:
            cout<<"Kindly write down your problem briefly in this section \n";
            getline(cin,gr);
            break;
    }
    cout<<"--> Your Grievance has been registered! \n";
    cout<<"--> Reference Number:"<<refno<<t<<"\n";
    cout<<"--> You will be notified via mail soon \n";
    ofstream fout;
    ifstream fin;
      fin.open("fbNg.txt");
      fout.open ("fbNg.txt",ios::app);
   if(fin.is_open())
      fout<<"Reference Number:"<<refno<<t<<"\n"<<gr<<"\n\n";
      fin.close();
      fout.close();
    cout<<"\n\nRedirecting to homepage in 5 seconds...\n";
    Sleep(5000);
    homepage();
}

void feedback()
{
    system("cls");
     cout<<"***************************************************************************************************\n\n";
    cout<<"                                  Welcome to Feedback Form Page                                     \n\n";
    cout<<"*********                        Your Feedbacks are always Welcomed!                    ************\n\n";
    string fb;
    int t;
    cout<<"Select the type of Feedback that you wish to fill \n";
    cout<<"1. Feedback for our App \n";
    cout<<"2. Feedback for your journey using our services \n";
    cout<<"3. Feedback related to a Station \n";
    cout<<"4. Feedback for our System \n";
    cout<<"5. Others \n";
    cin>>t;
    string fno ="FB";
    system("cls");
    cout<<"**************************************************************\n";
    cout<<"       Feedback Form               Form number:"<<fno<<t<<"\n \n";
    string pp;
    getline(cin,pp);
    switch(t)
    {
        case 1:
            cout<<"Did you find any problem while using our App? \n";
            Sleep(1000);
            cout<<"Or Do you have a suggestion to enhance the User experience?\n";
            Sleep(1000);
            cout<<"Kindly write down your Feedback \n";
            getline(cin,fb);
            break;
        case 2:
            cout<<"How was your journey? \n";
            Sleep(1000);
            cout<<"Did you experience some difficulty during your journey? \n";
            Sleep(1000);
            cout<<"Or do you have a suggestion to enhance the experience of the train journey? \n";
            Sleep(1000);
            cout<<"Kindly write down your Feedback \n";
            cout<<"Kindly write down all the necessary details as well \n";
            getline(cin,fb);
            break;
        case 3:
            cout<<"Have you experienced some irrational activity going on? \n";
            Sleep(1000);
            cout<<"Or do you have a suggestion to enhance our services? \n";
            Sleep(1000);
            cout<<"Our Railway system always welcomes suggestions and complains regarding the services \n";
            cout<<"Kindly write down your feedback briefly here \n";
            getline(cin,fb);
            break;
        case 4:
            cout<<"Have you experienced some irrational activity going on? \n";
            Sleep(1000);
            cout<<"Or do you have a suggestion to enhance our services? \n";
            Sleep(1000);
            cout<<"Kindly write down your feedback here\n";
            getline(cin,fb);
            break;
        case 5:
            cout<<"Your suggestions and complaints are always taken care of by our Officials \n";
            cout<<"Kindly write down your Feedback briefly \n";
            getline(cin,fb);
            break;
    }
    cout<<"--> Your Feedback has been registered! \n";
    cout<<"--> Reference Number:"<<fno<<t<<"\n";
    cout<<"--> Thank you for your time. \n";
   ofstream fout;
   ifstream fin;
      fin.open("fb.txt");
      fout.open ("fb.txt",ios::app);
   if(fin.is_open())
      fout<<"Reference Number:"<<fno<<t<<"\n"<<fb<<"\n\n";
      fin.close();
      fout.close();
    cout<<"\n\nRedirecting to homepage in 5 seconds...\n";
    Sleep(5000);
    homepage();
}
