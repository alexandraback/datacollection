#include <stdio.h>
#include <math.h>
#include <algorithm>
#define MAXL 100050

using namespace std;

int a,b;
double pr[MAXL];
double fwd[MAXL],bac[MAXL];

int main(void)
{
   int t,cas=1;
   scanf("%d",&t);
   while(t--) {
      scanf("%d %d",&b,&a);
      for(int i=0;i<b;i++)
         scanf("%lf",pr+i);
      fwd[0]=pr[0];
      for(int i=1;i<b;i++)
         fwd[i]=fwd[i-1]*pr[i];
      bac[b-1]=pr[b-1];
      for(int i=b-2;i>=0;i--)
         bac[i]=bac[i+1]*pr[i];
      // enter
      double sol=1.0+a+1;
      // delete
      int r=a-b;
      for(int d=0;d<=b;d++) {
         int p=b-d;
         double pp=(p?fwd[p-1]:1.0);
         //double pq=(d?bac[p]:1.0);
         //double cur=(1-pq)*(d+1+a+1)+
         double cur=d+pp*(d+r+1)+(1.0-pp)*(d+r+1+a+1);
         //printf("<%.4lf %.4lf>\n",pp,cur);
         sol=min(sol,cur);
      }
      printf("Case #%d: %.9lf\n",cas++,sol);
   }
   return 0;
}
