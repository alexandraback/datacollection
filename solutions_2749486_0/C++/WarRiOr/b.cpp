#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
ifstream readf("asmall.in");
ofstream writef("asmall.out");
int x=0,y=0;
int c;
int main()
{ 
    int ox=0,oy=0;
    void n();
    void s();
    void e();
    void w();
    int t;
  readf>>t;

  for(int T=1;T<=t;T++)
  {ox=0;oy=0;
  readf>>ox;
  readf>>oy;
  x=ox;
  y=oy;
  c=1;
  writef<<"Case #"<<T<<": ";
   
              while(x)
              {  
                 if(x>=c)
                 {
                        e();
                writef<<"E";
                   continue;          
                 }
                 if(x<c)
                  {w();
                  writef<<"W";
                 continue;
                  
                  }
              }      
             while(y!=0)
              { //cout<<"#";
                if(y>=c)
                 { //cout<<"$";
                       n();
                 writef<<"N";
               continue;
                 }
                 if(y<c)
                 { //cout<<"&";
                        s();
                 writef<<"S";
                 continue;
                 }
               //getch();
              }     
  writef<<endl;
   }
  
  
}


  void n()
  {   y=y-c;
      c++;
  }
    void s()
     {   y=y+c;
         c++;
    }
    void e()
    { x=x-c;
      c++;
    }
    void w()
   {
         x=x+c;
         c++;
   }
