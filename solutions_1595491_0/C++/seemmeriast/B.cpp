#include<iostream>
#include<algorithm>
using namespace std;
int T;
int main()
{
     freopen("B-small-attempt0.in","r",stdin);
     freopen("B-small-attempt0.out","w",stdout);

     cin>>T;
     for(int t=1;t<=T;t++)
     {
          int n,s,p;
          cin>>n>>s>>p;

          int a=0,b=0,c=0;
          for(int i=0;i<n;i++)
          {
               int x;
               cin>>x;

               if(p==0)
               a++;
               else if(p==1)
               {
                    if(x>=1)
                    a++;
                    else
                    c++;
                    }
               else
               {
                    if(x>=3*p-2)
                    a++;
                    else if(x>=3*p-4)
                    b++;
                    else
                    c++;
                    }
               }

          cout<<"Case #"<<t<<": "<<a+min(b,s)<<endl;
          }

     return 0;
     }
