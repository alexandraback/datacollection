#include<stdio.h>
int main()
{
  int T,test=1;
  double C,F,X,rate,time;
  scanf("%d",&T);
  while(T--)
    {
      scanf("%lf %lf %lf",&C,&F,&X);
      rate=2.0;
      time=0;
      while(X/rate>C/rate+X/(rate+F))
	{
	  time+=C/rate;
	  rate+=F;
	}
      time+=X/rate;
      printf("Case #%d: %lf\n",test++,time);
    }
  return 0;
}
