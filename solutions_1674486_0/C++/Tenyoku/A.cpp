#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

bool used[1001];
bool now[1001];
vector<int> G[1001];
int n;
bool dfs(int i)
{
	now[i] = 1;
	for(int j=0; j<G[i].size(); ++j)
	{
		if(now[G[i][j]]) return 1;
		else if(dfs(G[i][j])) return 1;
	}
	return 0;
}

int main()
{
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("out.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cnt=1; cnt<=T; ++cnt)
	{
		scanf("%d", &n);
		memset(used, 0, sizeof(used));
		for(int i=1; i<=n; ++i)
		{
			int m;
			scanf("%d", &m);
			G[i].clear();
			while(m-->0)
			{
				int tmp;
				scanf("%d", &tmp);
				G[i].push_back(tmp);
				used[tmp] = 1;
			}
		}
		bool yn = 0;
		for(int i=1; i<=n; ++i)
			if(!used[i])
			{
				memset(now, 0, sizeof(now));
				if(dfs(i))
				{
					yn = 1;
					break;
				}
			}
		printf("Case #%d: %s\n", cnt, (yn?"Yes":"No"));
	}
	return 0;
}
