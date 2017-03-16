#include <fstream>
#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <math.h>

using namespace std;

int main ()
{
     int x,tem,a[1000],cas=0,n,p,s,d,s1,s2,t,sp;
     ifstream file("C:/Users/Rahul/Desktop/B-large.in");
     ofstream ofile("C:/Users/Rahul/Desktop/output.txt");
     file>>tem;
     while(cas++!=tem)
     {
               file>>n>>s>>p;
               for(x=0;x<n;x++)
               {
                               file>>a[x];
               }
               s1=s2=sp=0;
               for(x=0;x<n;x++)
               {
                               if(a[x]>=2&&a[x]<=28)
                               {t=a[x]/3;
                               d=a[x]%3;
                               if(d==0)
                               {
                                       if(t>=p) s1++;
                                       if(t+1>=p) s2++;
                               }
                               else if(d==1)
                               {
                                       if(t+1>=p) 
                                       {
                                                  s1++;
                                                  s2++;
                                       }
                               }
                               else if(d==2)
                               {
                                       if(t+1>=p) s1++;
                                       if(t+2>=p) s2++;
                               }
                               }
                               else
                               {
                                   if(a[x]==1&&1>=p) sp++;
                                   else if(a[x]==0&&0>=p) sp++;
                                   else if((a[x]==29||a[x]==30)&&10>=p) sp++;
                               }
               }
               if(s2-s1>s) t=s;
               else t=s2-s1;
               //cout<<s1+sp+t<<endl;
               ofile<<"Case #"<<cas<<": "<<s1+sp+t<<endl;               
     }
     file.close();
     ofile.close();
     //system("pause");
     return 0;
}
