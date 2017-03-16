#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define EPS 1e-8

using namespace std;

bool ok(double all,double pay,double pl,double lim)
{
	double now=2;
	all-=now*lim;
	while(all>-EPS)
	{
		lim-=pay/now;
		if(lim<-EPS) return false;
		if(pay>pl*lim+EPS) return false;
		all-=pl*lim-pay;
		now+=pl;
	}
	return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		double all,pay,pl;
		scanf("%lf %lf %lf",&pay,&pl,&all);
		double s=0,e=all;
		for(int i=0;i<100;i++)
		{
			double med=(s+e)/2;
			if(ok(all,pay,pl,med)) e=med;
			else s=med;
		}
		printf("Case #%d: %.7lf\n",t,s);
	}
	return 0;
}
