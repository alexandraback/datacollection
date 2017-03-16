#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double ZERO=1e-8;
int T,a,n;
double ans[2001],t0,x0,t1,x1,ac[2001],d;

void init()
{
	scanf("%lf %d %d",&d,&n,&a);
	scanf("%lf %lf",&t0,&x0);
	if (n==2) scanf("%lf %lf",&t1,&x1);
	for (int i=1;i<=a;i++)	scanf("%lf",&ac[i]);
}


double work(double g)
{
	if (n==1)
	{
		return sqrt(d*2/g);
	}
	else
	{
		double v=(x1-x0)/(t1-t0);
		double delta=v*v+2*g*x0;
		double t=(v+sqrt(delta))/g;

		if (x0+v*t>d-ZERO) return sqrt(d*2/g);
		return t0+(d-x0)/v;
	}
}

int main()
{
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		init();
		for (int i=1;i<=a;i++)	ans[i]=work(ac[i]);

		printf("Case #%d:\n",t);	
		for (int i=1;i<=a;i++)
			printf("%.7f\n",ans[i]);

	}
	return 0;
}