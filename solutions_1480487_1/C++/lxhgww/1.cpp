#include<stdio.h>

double a[201];

int main()
{
	int t,p;
	int n;
	int i,j,k;
	double s;
	double h,l,m;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&n);
		s=0;
		for (i=1;i<=n;i++)
		{
			scanf("%lf",&a[i]);
			s=s+a[i];
		}
		printf("Case #%d:",p);
		for (i=1;i<=n;i++)
		{
			h=1.0;
			l=0.0;
			for (j=1;j<=30;j++)
			{
				m=(l+h)/2;
				double sum=0;
				for (k=1;k<=n;k++)
					if (a[k]<=a[i]+m*s)
					{
						sum=sum+(a[i]+m*s-a[k])/s;
					}
				if (sum>1.0) h=m;
				else l=m;
			}
			printf(" %.5lf",l*100);
		}
		printf("\n");
	}
	return 0;
}



