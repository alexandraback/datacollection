#include <stdio.h>

using namespace std;

long long x[20000000];
long long y[2000],z[2000];

int main()
{
	long long tc,t,e,r,n,i,j,k,p;
	scanf("%lld\n",&t);
	for (tc=0;tc<t;++tc)
	{
		scanf("%lld %lld %lld",&e,&r,&n);
		for (i=0;i<n;++i) scanf("%lld",x+i);
		long long *a=y,*b=z,*c;
		for (i=0;i<=e;++i) a[i]=0;
		p=e-r;
		for (i=n-1;i>=0;--i)
		{
			c=a;
			a=b;
			b=c;
			for (j=0;j<=e;++j)
			{
				a[j]=0;
				for (k=0;k<=j;++k) if (k*x[i]+b[(j+r-k>e)?e:j+r-k]>a[j]) a[j]=k*x[i]+b[(j+r-k>e)?e:j+r-k];
			}
		}
		printf("Case #%lld: %lld\n",tc+1,a[e]);
	}
	return 0;
}
