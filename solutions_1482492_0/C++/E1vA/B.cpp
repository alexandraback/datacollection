#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int n;
double d;
int A;
int T;
double a;
double x[1005];
double t[1005];

double solve(double a)
{
	if(n==1)
		return sqrt(2*d/a);
	else
	{
		double tt=(d-x[0])/((x[1]-x[0])/(t[1]));
		return max(sqrt(2*d/a),tt);
	}
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small.out","w",stdout);
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		scanf("%lf%d%d",&d,&n,&A);
		for(int i=0;i<n;i++)
			scanf("%lf%lf",&t[i],&x[i]);
		printf("Case #%d:\n",test);
		for(int i=0;i<A;i++)
		{
			scanf("%lf",&a);
			printf("%.10f\n",solve(a));
		}
	}
	return 0;
}

