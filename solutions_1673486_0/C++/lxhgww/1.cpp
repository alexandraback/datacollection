#include<stdio.h>

double a[100001];

int main()
{
	int t,p;
	int n,m;
	int i,j;
	double mm;
	double s1;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%d",&n,&m);
		for (i=1;i<=n;i++)
			scanf("%lf",&a[i]);
		mm=m+2;
		s1=1;
		for (i=1;i<=n;i++)
			s1=s1*a[i];
		if (s1*(m-n+1)+(1-s1)*(m-n+1+m+1)<mm) mm=s1*(m-n+1)+(1-s1)*(m-n+1+m+1);
		for (i=n-1;i>=0;i--)
		{
			s1=s1/a[i+1];
			if (s1*(n-i+m-i+1)+(1-s1)*(n-i+m-i+1+m+1)<mm) mm=s1*(n-i+m-i+1)+(1-s1)*(n-i+m-i+1+m+1);
		}
		printf("Case #%d: %.6lf\n",p,mm);
	}
	return 0;
}
