#include <stdio.h>
int n, t;
int s[1000000];
double pas[1000000];
int main()
{
freopen("A-small-attempt0.in","r",stdin);
freopen("A-small.out","w",stdout);
scanf("%d\n",&t);
for(int it=1;it<=t;it++)
   {
   printf("Case #%d: ", it);
   scanf("%d",&n);
   int jami = 0;
   for(int i=0;i<n;i++)
      {
      scanf("%d",&s[i]);
      jami += s[i];
      }
   for(int i=0;i<n;i++)
      {
      double st = 0.;
      double fin = 1.;
      for(int j=0;j<100;j++)
         {
         double k = (st + fin) / 2.;
         double qq = s[i] + k * jami;
         double sxvap = 0.;
         for(int i1=0;i1<n;i1++)
            {
            if(i1 == i || s[i1] >= qq) continue;
            sxvap += (qq - s[i1]) / jami;
            }
         if(sxvap + k >= 1.)
            fin = k;
         else
            st = k;
         }
      pas[i] = st;
      }
   for(int i=0;i<n;i++)
      {
      if(i) printf(" ");
      printf("%.6lf",pas[i] * 100.);
      }
   printf("\n");
   }
return 0;
}
