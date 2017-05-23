#include<stdio.h>
#include<math.h>
#define MAX 1000000007
int main()
{
 int t,l;
 double i,j,k,m;
 double c,f,x;
 scanf("%d",&t);
 for(l=0;l<t;l++)
 {
  scanf("%lf%lf%lf",&c,&f,&x);
  i=2.0;k=0;
  for(j=x/(i+f)+c/i;(x/i)>j;j=x/(i+f)+c/i)
  {
   k+=c/i;
   i+=f;
  }
  k+=x/i;
  printf("Case #%d: %.7lf\n",l+1,k);
 }
 return 0;
}