#include <stdio.h>
#include <algorithm>

using namespace std;


int main()
{
	long long tc,t,r=0;
	scanf("%lld\n",&t);
	for (tc=0;tc<t;++tc)
	{
		int n,k,i,j,a,b;
		double x[1010],y[1010];
		scanf("%d",&n);
		for (i=0;i<n;++i) scanf("%lf",x+i);
		for (i=0;i<n;++i) scanf("%lf",y+i);
		sort(x,x+n);
		sort(y,y+n);
		b=0;
		for (i=j=n-1;i>=0;--i)
		{
			if (x[i]>y[j]) ++b; else --j;
		}
		a=0;
		k=0;
		for (i=j=n-1;i>=k;--j)
		{
			if (x[i]>y[j]) { ++a; --i; } else { ++k; }
		}
		printf("Case #%lld: %d %d\n",tc+1,a,b);
	}
	return 0;
}
