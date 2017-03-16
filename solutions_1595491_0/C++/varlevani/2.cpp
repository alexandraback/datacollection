#include <stdio.h>
int t, n, s, p, rd;
int to[1000];
int main()
{
freopen("B-small.in","r",stdin);
freopen("B-small.out","w",stdout);
scanf("%d",&t);
for(int i=1;i<=t;i++)
   {
   printf("Case #%d: ",i);
   scanf("%d %d %d",&n,&s,&p);
   int rd = 0;
   for(int j=0;j<n;j++)
      {
      scanf("%d",&to[j]);
      if((to[j] + 2) / 3 >= p)
         rd++;
      else
         {
         if(s<=0) continue;
         bool ind = 1;
         for(int q1=0;(q1<=10) && ind;q1++)
            for(int q2=q1;(q2<=q1+2) && ind;q2++)
               for(int q3=q2;(q3<=q1+2) && ind;q3++)
                  if(q1 + q2 + q3 == to[j] && q3 >= p)
                     {
                     ind = 0;
                     rd++;
                     s--;
                     break;
                     }
         }
      }
   printf("%d\n",rd);
   }
return 0;
}
