#include<stdio.h>
#include<math.h>
int main()
{
  int T,r,t,i;
  double ans;
  scanf("%d",&T);
  for(i=1;i<=T;i++)
    {
      scanf("%d %d",&r,&t);
      ans=(-(2*r-1)+sqrt(4*r*r+1-4*r+8*t))/4;
      printf("Case #%d: %d\n",i,(int)floor(ans));
    }
  return 0;
}
