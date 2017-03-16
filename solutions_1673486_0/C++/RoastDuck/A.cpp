#include<cstdio>
#include<algorithm>
using namespace std;

int N,M,i,T,t;
double now,ans,a[100001];

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	for (;T>0;T--)
	{
		scanf("%d%d",&N,&M);
		for (i=1;i<=N;i++)
			scanf("%lf",&a[i]);
		now=1;
		ans=M+2;
		for (i=1;i<=N;i++)
		{
			ans=min(ans,now*(N-i+1+M-i+1+1)+(1-now)*(N-i+1+M-i+1+1+M+1));
			now*=a[i];
		}
		ans=min(ans,now*(N-i+1+M-i+1+1)+(1-now)*(N-i+1+M-i+1+1+M+1));
		printf("Case #%d: %.6lf\n",++t,ans);
	}
	return 0;
}
