#include <cstdio>
#include <vector>

bool was[1000];
std::vector<int> edge[1000];

bool dfs(int x)
{
	was[x]=true;
	for (int i=0; i<edge[x].size(); ++i)
	{
		int t = edge[x][i];
		if (was[t])
			return true;
		if (dfs(t))
			return true;
	}
	return false;
}

void solve()
{
	int n;
	scanf("%d",&n);
	for (int i=0; i<n; ++i)
	{
		int m;
		scanf("%d",&m);
		edge[i].clear();
		edge[i].reserve(m);
		for(int j=0; j<m; ++j)
		{
			int x;
			scanf("%d",&x);
			--x;
			edge[i].push_back(x);
		}
	}
	for (int i=0; i<n; ++i)
	{
		memset(was,0,sizeof(was));
		if (dfs(i))
		{
			printf("Yes\n");
			return;
		}
	}
	printf("No\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	for (int i=1; i<=t; ++i)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}