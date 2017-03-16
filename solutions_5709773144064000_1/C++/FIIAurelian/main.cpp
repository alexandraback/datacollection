#include<cstdio>
#define min(a,b) a<b?a:b
using namespace std;
int T,testNo,i;
double C,F,X,SOL,last,clicksPerSec,cnt;
int main()
{
   freopen("test.in","r",stdin);
   freopen("test.out","w",stdout);
   for(scanf("%d",&T);T;--T)
   {
       testNo++;
       scanf("%lf%lf%lf",&C,&F,&X);
       last = 0;
       clicksPerSec = 2.0;
       SOL = X/clicksPerSec;
       for(i=1;i<=(int)X+1;i++)
       {
           last += C/clicksPerSec;
           clicksPerSec += F;
           cnt = last + X/clicksPerSec;
           SOL=min(SOL,cnt);
       }
       printf("Case #%d: %.7lf\n",testNo,SOL);
   }
   return 0;
}
