#include <iostream>
#include <cstdio>
using namespace std;

double P[101000],p,ans;
int T,cc,n,m;

int main()
{
	freopen("a.in","r",stdin);freopen("a.out","w",stdout);
	
	cc=1;
	for (scanf("%d",&T);T;T--,cc++)
	{
		scanf("%d%d",&n,&m);P[0]=1;m-=n;ans=1e100;
		for (int i=1;i<=n;i++) scanf("%lf",&p),P[i]=P[i-1]*p;
		for (int i=1;i<=n;i++)
		{
			ans=min(ans,(n-i)+(m+n-i+1)+(1-P[i])*(n+m+1));
		}
		printf("Case #%d: %.7f\n",cc,min(ans,double(n+m+2)));
	//	printf("Case #%d: %.7f\n",cc,min(double(n+m+2),P*(m+1)+(1-P)*(n+m+m+2)));	
	}
	
	return 0;	
}
