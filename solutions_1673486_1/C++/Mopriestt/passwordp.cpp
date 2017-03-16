#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN=100001;
const double oo=10000000;

double pre[MAXN],ans=oo,P[MAXN],tmp;
int n,m,i,j,k,DAT,cas;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&DAT);
	for (cas=1;cas<=DAT;cas++)
	{
		scanf("%d%d",&n,&m);
		pre[0]=1;
		for (i=1;i<=n;i++)
		{
			scanf("%lf",&P[i]);
			pre[i]=pre[i-1]*P[i];
		}
		ans=m+2;
		m-=n;
		for (i=0;i<=n;i++)
		{
			tmp=pre[n-i]*(m+2*i+1)+(1-pre[n-i])*(2*i+2*m+n+2);
			if (tmp<ans) ans=tmp;
		}
		printf("Case #%d: %0.6lf\n",cas,ans);
	}
	return 0;
}
