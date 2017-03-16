#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int N = 10010;
double p[N],ans,tp[N];
int n,m;
double contype()
 {
   double ans ;
   double pos = 1;
   tp[0] = 1;
   for(int i = 1 ;i <= n;i++)
    {
        tp[i] =p[i]*tp[i-1];
    }
    ans = tp[n]*(m-n+1) + (1 - tp[n]) * (m-n+2+m);
    return ans;
 }
double backtype()
 {
     double ans = 9999999989,like;
     for(int i = 1;i <= n;i++)
      {
          int pos  = n - i;
          ans = min(ans,tp[pos]*(i+i+m-n+1) +(1-tp[pos])*(i+i+m-n+1+m+1));
      }
     return ans;
 }
double enter()
 {

     return m+2;

 }
int main()
 {
     int t;
     freopen("A-small-attempt0.in","r",stdin);
     freopen("t.txt","w",stdout);
     scanf("%d",&t);
     for(int w = 1 ; w <= t;w++)
      {
          scanf("%d%d",&n,&m);
          for(int i = 1; i <= n;i++)
            scanf("%lf",p+i);
          printf("Case #%d: ",w);
          ans = contype();
          ans = min(ans,backtype());
          ans = min(ans,enter());
          printf("%.6lf\n",ans);
      }
    return 0;
 }
