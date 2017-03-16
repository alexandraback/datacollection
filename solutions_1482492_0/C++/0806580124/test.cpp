#include<iostream>
#include<cmath>
using namespace std;
#define eps 1e-8

double a,d,t[100],x[100];
double maxx(double a,double b)
{
	return a>b?a:b;
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,co=1,T,numa,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf%d%d",&d,&n,&numa);
		for(i=0;i<n;i++)
			scanf("%lf%lf",&t[i],&x[i]);
		printf("Case #%d:\n",co++);
		double mint;
		for(i=0;i<numa;i++)
		{
			scanf("%lf",&a);
			mint=sqrt(2*d/a);
			if (x[0]<=d)
			{
				double tt =(d-x[0])/((x[1]-x[0])/(t[1]-t[0]));
				printf("%lf\n",maxx(tt,mint));
			}
			else
			{
				printf("%lf\n",mint);
			}
		}
	}

	return 0;
}