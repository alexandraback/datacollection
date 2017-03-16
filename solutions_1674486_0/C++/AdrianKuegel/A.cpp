#include <stdio.h>
#include <assert.h>
#include <vector>
#include <string.h>

using namespace std;

typedef vector<int> VI;
VI adj[10000];
char visit[10000];

bool dfs(int cur)
{
	//printf("here with cur = %d %d\n", cur, adj[cur].size());
	if (visit[cur])
	{
		return true;
	}
	visit[cur] = 1;
	for (VI::iterator it=adj[cur].begin(); it!=adj[cur].end(); ++it)
		if (dfs(*it))
			return true;
	return false;
}


int main() {
	int n, tc;
	scanf("%d", &tc);
	for (int scen=1; scen<=tc; ++scen)
	{
		scanf("%d", &n);
		for (int i=0; i<n; i++)
		{
			adj[i].clear();
			int a, m;
			scanf("%d", &m);
			while(m--)
			{
				scanf("%d", &a);
				--a;
				assert(a != i && a >= 0 && a < n);
				adj[i].push_back(a);
			}
		}
		bool found = false;
		for (int source=0; source<n; ++source)
		{
			memset(visit, 0, sizeof(visit));
			//printf("trying source = %d\n", source);
			if (dfs(source))
			{
				found = true;
				break;
			}
		}
		printf("Case #%d: ", scen);
		puts(found?"Yes":"No");
	}
	int t;
	assert(scanf("%d", &t) != 1);
	return 0;
}
