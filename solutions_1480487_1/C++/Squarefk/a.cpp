#include <cstdio>

using namespace std;

int n,t,x,data[220];

double cabs(double k)
{
	if (k>=0) return k;
	return -k;
}

bool can(double now,int k)
{
	double xx=1.0*data[k]+now*x;
	double temp=1-now;
	for (int i=1;i<=n;++i)
		if ((i!=k)&&(1.0*data[i]<xx))
			temp-=(xx-1.0*data[i])/(1.0*x);
	if (temp>0) return false;
	return true;
}

int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&t);
	for (int tt=1;tt<=t;++tt)
	{
		scanf("%d",&n);
		x=0;
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&data[i]);
			x+=data[i];
		}
		printf("Case #%d:",tt);
		for (int i=1;i<=n;++i)
		{
			double l=0.0,r=100.0;
			while (cabs(l-r)>0.00000001)
			{
				double mid=(l+r)/2;
				if (can(mid/100,i)) r=mid;
				else l=mid;
			}
			printf(" %.6lf",r);
		}
		printf("\n");
	}
	return 0;
}
