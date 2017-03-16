#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct fuck{
       double v,l;
       };
fuck arr[105];
double x[105];
double map[105][105];
double di[105][105];
int t,l,r,n;
int a,b,c,d;
double best;
int i;
char cc;
int main()
{
    freopen("C-small-attempt0(1).in","r",stdin);
    freopen("B-large(1).out","w",stdout);
    cin>>t;
    int cas=0;
    while (t--)
    {
          cas++;
          cin>>n;
          for (a=1;a<=n;a++)
          {
              cin>>cc>>arr[a].v>>arr[a].l;
              x[a]=arr[a].l;
          }
          double shijian=0;
          int judge=0;
          while (true)
          {
                shijian+=1;
                for (a=1;a<=n;a++) x[a]+=arr[a].v;
                for (a=1;a<=n;a++)
                {
                    int temp=0;
                    for (b=1;b<=n;b++) if (x[a]-x[b]>=-5 && x[a]-x[b]<=5) temp++;
                    if (temp>=3) {judge=1; break;} 
                }
                if (judge==1 || shijian>=150000) break;
                }
          judge=0;
          int now=0;
          while (true)
          {
                shijian-=0.000001;
                now++;
                for (a=1;a<=n;a++) x[a]-=arr[a].v*0.00001;
                for (a=1;a<=n;a++)
                {
                    int temp=0;
                    for (b=1;b<=n;b++) if (x[a]-x[b]>=-5 && x[a]-x[b]<=5) temp++;
                    if (temp>=3) {judge=1; break;} 
                }
                if (judge==1 || shijian<=149999) break;
          }
          printf("Case #%d: ",cas);
          if (shijian>=149800.99999) cout<<"Possible"<<endl; else printf("%.5lf\n",shijian);
    }
}
