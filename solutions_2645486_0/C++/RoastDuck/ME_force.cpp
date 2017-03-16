#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int E,R,N,v[15],ans;

void dfs(int x, int e, int g)
{
	if (x>N)
	{
		ans=max(ans,g);
		return;
	}
	for (int i=0;i<=e;i++)
		dfs(x+1,min(E,e-i+R),g+i*v[x]);
}

int main()
{
	freopen("ME_force.in","r",stdin);
	freopen("ME_force.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++)
	{
		scanf("%d%d%d",&E,&R,&N);
		for (int i=1;i<=N;i++) scanf("%d",&v[i]);
		ans=0;
		dfs(1,E,0);
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}

