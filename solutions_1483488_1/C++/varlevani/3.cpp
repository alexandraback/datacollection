#include <stdio.h>
int namy[100];
int t, A, B;
int main()
{
freopen("C-large.in","r",stdin);
freopen("C-large.out","w",stdout);
scanf("%d",&t);
for(int it=1;it<=t;it++)
   {
   printf("Case #%d: ",it);
   scanf("%d %d",&A, &B);
   int cr = 0;
   int a = A;
   int xar = 1;
   do {
   cr++;
   a/=10;
   xar *= 10;
   }while(a);
   xar /= 10;
   int pas = 0;
   for(int i=A;i<=B;i++)
      {
      a = i;
      for(int j=0;j<=cr;j++)
         {
         a = (a%10) * xar + (a/10);
         if(a > i && a <= B)
            {
            bool ind = 0;
            for(int ii=0;ii<j;ii++)
               if(namy[ii] == a)
                  {
                  ind = 1;
                  break;
                  }
            if(!ind)
               {
               pas++;
               }
            }
         namy[j] = a;
         }
      }
   printf("%d\n",pas);
   }
return 0;
}
