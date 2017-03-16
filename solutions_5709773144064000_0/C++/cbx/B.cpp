#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
bool buy(double c,double f,double x,double i)
{
	double no=x/i;
	double yes=c/i+x/(i+f);
	const static double eps=1e-7;
	return yes<=no+eps;
}
int main()
{
	int t,ti;
	scanf("%d",&t);
	for (ti=1;ti<=t;ti++)
	{
		double c,f,x;
		scanf("%lf%lf%lf",&c,&f,&x);
		double i=2;
		double t=0;
		while (buy(c,f,x,i))
		{
			t+=c/i;
			i+=f;
		}
		t+=x/i;
		printf("Case #%d: %f\n",ti,t);
	}
	return 0;
}
