#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ifstream in ("C-large.in");
    ofstream out ("output.txt");
    int t,a,b;
    in>>t;
    for(int i=0;i<t;i++)
    {
         int n_digit=0,resto,div=10,rec,quoz,ris=0,cont;
         in>>a;
         in>>b;
         while(resto!=a)
         {
             resto=a%div;
             n_digit++;
             div=div*10;
         }
         for(int num=a;num<=b;num++)
         {
              div=10;
              resto=num%div;
              quoz=num/div;
              cont=1;
              while(resto!=num)
              {
                     rec=resto*(pow(10.0,n_digit-cont))+quoz;
                     if(rec==num)
                     {
                          break;
                     }
                     if(rec>num && rec <=b)
                     {
                          ris++;
                     }
                     div=div*10;
                     resto=num%div;
                     quoz=num/div;
                     cont++;
              }
         }
         out<<"Case #"<<i+1<<": "<<ris<<endl;
    }
}
