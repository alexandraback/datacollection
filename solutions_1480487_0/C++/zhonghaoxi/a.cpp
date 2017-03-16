#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const double eps=1e-8;

int n;

double s[1000];

double p[1000];

bool check(double now,double su)
{
	double sum=su;
	double ans=0;
	for (int a=1;a<=n;a++)
	{
		p[a]=(now-s[a])/sum;
		ans+=p[a];
	}
	if (ans>=1.0+eps) return false;
	else return true;
}

int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int t;
	scanf("%d",&t);
	for (int a=1;a<=t;a++)
	{
		printf("Case #%d:",a);
		scanf("%d",&n);
		double sum=0;
		double l=0;
		for (int b=1;b<=n;b++)
		{
			scanf("%lf",&s[b]);
			sum+=s[b];
			l=max(l,s[b]);
		}
		double r=sum;
		for (int b=1;b<=1000;b++)
		{
			double m=(l+r)/2.0;
			if (check(m,sum)) l=m;
			else r=m;
		}
		check(l,sum);
		for (int b=1;b<=n;b++)
			p[b]*=100.0;
		for (int b=1;b<=n;b++)
			printf(" %lf",p[b]);
		printf("\n");
	}

	return 0;
}
