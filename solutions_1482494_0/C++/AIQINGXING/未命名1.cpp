#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct fuck{
       int l,r,vis;
       };
fuck fir[1050];
double temp;
int t,l,r,n;
int a,b,c,d;
double best;
int cmp(fuck i,fuck j)
{
    if (i.r>j.r) return 0;
    if (i.r<j.r) return 1;
    if (i.l>j.l) return 0;
    if (i.l<j.l) return 1;
}
int main()
{
    freopen("B-small-attempt3.in","r",stdin);
    freopen("B-small-attempt3.out","w",stdout);
    cin>>t;
    int cas=0;
    while (t--)
    {
          cas++;
          cin>>n;
          for (a=1;a<=n;a++)
          {
              cin>>fir[a].l>>fir[a].r;
              fir[a].vis=0;
          }
          sort(fir+1,fir+1+n,cmp);
          int head=0,now=0,judge=0,sum=0;;
          for (head=1;head<=n;head++)
          {
              if (now>=fir[head].r)
              {
                 sum++;
                 if (fir[head].vis==0) now+=2; else now+=1;
                 continue;
              }
              while (now<fir[head].r)
              {
                    int pre=now;
                    for (a=n;a>=head;a--)
                    if (now>=fir[a].l && fir[a].vis==0)
                    {
                       fir[a].vis=1;
                       now+=1;
                       sum++;
                       break;
                    }
                    if (pre==now) {judge=1; break;}
              }
              if (judge==1) break;
              sum++;
              if (fir[head].vis==0) now+=2; else now+=1;
          }
          printf("Case #%d: ",cas);
          if (judge==1) cout<<"Too Bad"<<endl; else cout<<sum<<endl;
    }
    return 0;
}          
