#include <cstdio>
#include <algorithm>
using namespace std;
double p[100001];

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T,t,i,n,m;
	double x,ans;
	scanf("%d",&T);
	for (t=1; t<=T; ++t)
	{
		scanf("%d%d",&m,&n);
		p[0]=1.0;
		for (i=1; i<=m; ++i)
		{
			scanf("%lf",&x);
			p[i]=p[i-1]*x;
		}
		ans=n+2;
		for (i=0; i<=m; ++i) ans=min(ans,(n+1)*(1-p[m-i])+n-m+1+i*2);
		printf("Case #%d: %.7f\n",t,ans);
	}
	return 0;
}
