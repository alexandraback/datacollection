#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

bool adj[1001][1001];
bool bad;
int cnt[1001];
int n;
void dfs(int now)
{
	if(cnt[now] == 1)
	{
		bad = 1;
		return;
	}
	cnt[now] = 1;
	for(int i=1;i<=n;i++)
	{
		if(adj[now][i])
		{
			dfs(i);
		}
	}
}

int main()
{
	int ncas;
	scanf("%d",&ncas);
	for(int t=1;t<=ncas;t++)
	{
		int m;
		bad = 0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				adj[i][j] = 0;
		}

		for(int i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(int j=0;j<m;j++)
			{
				int k;
				scanf("%d",&k);
				if(k ==0) continue;
				adj[i][k] = 1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				///printf("%d ",adj[i][j]);
			}
			//puts("");
		}
	
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) cnt[j] = 0;
			dfs(i);
			if(bad) break;
		}
		

		printf("Case #%d: %s",t,(bad)?"Yes":"No");
		printf("\n");
	}
	return 0;
}
