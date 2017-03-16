#include<algorithm>
#include<fstream>
#include<iostream>
#include<sstream>
#include<cstring>
using namespace std;


int main(int argc,char* argv[])
{
   string input_file;
   input_file = argv[1];
   ifstream inf;
   inf.open(input_file.c_str());
   int test_cases;
   inf >> test_cases;
   for(int i=0;i<test_cases;i++)
   {
      int x,r,c;
      inf >> x;
      inf >> r;
      inf >> c;
      bool flag = true;
      if(x>=7)
      { 
         flag = false;
      }
      else if(x>r and x>c)
      {
         flag = false;
      }
      else if(r*c%x!=0)
      {
         flag = false;
      }
      else if (((x+1)/2) > min(r,c))
      {
         flag = false;
      }
      else if(x == 1 || x==2 || x==3)
      {
         flag = true;
      }
      else if(x == 4)
      { 
         flag = min(r,c)>2;
      }
      else if(x == 5)
      { 
         flag = not(min(r,c)==3 and max(r,c) == 5);
      }
      else if(x==6)
      {
         flag = min(r,c)>3;
      }

      if(flag == true)
      {
         cout<<"Case #"<<i+1<<": "<<"GABRIEL"<<endl;   
      }
      else
      {
         cout<<"Case #"<<i+1<<": "<<"RICHARD"<<endl;
      }
   }
   return 0;
}
