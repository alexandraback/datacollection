#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=100100;
double p[maxn],f[maxn];
int main()
{
	
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int tests;
	scanf("%d",&tests);
	for (int test=1; test<=tests; test++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=1; i<=n; i++)
			scanf("%lf",&p[i]);
		
		f[0]=1;
		for (int i=1; i<=n; i++) f[i]=f[i-1]*p[i];
		
		double ans,res;
		ans=(m+2)*1.0;
		for (int i=0; i<=n; i++)
		{
			res=i+f[n-i]*(m-n+1+i)+(1-f[n-i])*(m-n+1+i+m+1);
			//printf("%.8lf\n",res);
			if (res<ans) ans=res;
		}
		printf("Case #%d: %.6lf\n",test,ans);
	}
}
