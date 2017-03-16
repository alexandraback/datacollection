#include <stdio.h>
#include <algorithm>
using namespace std;
double C,F,X;
//C: cost of a farm
//F: production of the farm
//X: target
double solve(double earn, double spent)
{
	//find best time
	//1. wait
	double ret = (X)/earn;
	//2. buy one more farm... if total spent money < target money
	if (spent + C < X)	
		ret = min(ret, solve(earn+F,spent+C) + C/earn);
	return ret;
}
int main()
{
	int T;scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		scanf("%lf %lf %lf",&C,&F,&X);
		printf("Case #%d: %.7lf\n",kase,solve(2.0,0.0));
	}
	return 0;
}