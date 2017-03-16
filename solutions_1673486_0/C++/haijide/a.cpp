#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double p[100005];
double w[100005];
double c[100005];

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.out","w",stdout);
	int t;
	int a,b;
	int i,j;
	int cs=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		scanf("%lf",&p[1]);
		w[1]=p[1];
		c[1]=1-p[1];
		for(i=2;i<=a;i++)
		{
			scanf("%lf",&p[i]);
			w[i]=w[i-1]*p[i];
			c[i]=c[i-1]+w[i-1]*(1-p[i]);
		}
		double a2=0,a3=0;
		double ans=10000000;
		for(i=0;i<a;i++)
		{
			a2=(b+1-a+2*i)*w[a-i]+(2*b-a+2+2*i)*c[a-i];
			if(ans>a2)
				ans=a2;
		}
		a3=b+2;
		if(ans>a3)
			ans=a3;
		printf("Case #%d: %.6lf\n",cs++,ans);
	}
	return 0;
}