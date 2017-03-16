#include<iostream>
#include<algorithm>
using namespace std;
double p[100010],pp[100010];
int T,a,b;
int main()
{
     freopen("A-large.in","r",stdin);
     freopen("A-large.out","w",stdout);

     cin>>T;
     for(int t=1;t<=T;t++)
     {
          cin>>a>>b;

          pp[0]=1;
          for(int i=1;i<=a;i++)
          {
               cin>>p[i];
               pp[i]=pp[i-1]*p[i];
               }

          double ans=(double)(b+2);
          for(int i=0;i<=a;i++)
          ans=min(ans,(double)(a+b-2*i+1)+(1-pp[i])*(double)(b+1));

          cout<<"Case #"<<t<<": ";
          printf("%lf\n",ans);
          }

     return 0;
     }
