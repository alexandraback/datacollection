#include <iostream>
#include <vector>

using namespace std;
vector<int> vec[1001];
int T,n,m,mi;
int vis[1001];
bool ans = false;

void dfs(int k)
{
	if (vis[k] == 1) 
	{
		ans = true; return;
	}
	vis[k] = 1;
	for (int i = 0;i < vec[k].size() && (!ans);++i)
	{
		int v = vec[k][i];
		dfs(v);
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	scanf("%d",&T);
	
	for (int ca = 1;ca <= T;++ca)
	{
		printf("Case #%d: ",ca);
		scanf("%d",&n);
		for (int i = 1;i <= n;++i)
		{
			scanf("%d",&m);
			for (int j = 0;j < m;++j)
			{
				scanf("%d",&mi);
				vec[i].push_back(mi);
			}
		}

		for (int i = 1;i <= n;++i)
		{
			memset(vis,0,sizeof(vis));
			dfs(i);
			if (ans)
				break;
		}

		if (ans)
			printf("Yes\n");
		else
			printf("No\n");
		for (int i = 0;i <= n;++i) vec[i].clear();
		ans = false;
	}

	return 0;
}