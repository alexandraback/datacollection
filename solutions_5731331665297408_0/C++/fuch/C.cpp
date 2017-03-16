#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

bool go[100][100];
char zip[100][100];
int n;

bool visited[100];
bool used[100];

void init()
{
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", zip[i]);
	}
	memset(go, 0, sizeof(go));
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		go[u][v] = go[v][u] = true;
	}
}

int dfs(int node)
{
	int cnt = 1;
	used[node] = true;
	for (int i = 0; i < n; ++i)
	{
		if (!used[i] && !visited[i] && go[node][i]) cnt += dfs(i);
	}
	return cnt;
}

void solve()
{
	int start = 0;
	for (int i = 1; i < n; ++i)
	{
		if (strcmp(zip[i], zip[start]) < 0) start = i;
	}

    std::vector<int> link;
    link.push_back(start);
    int num_visited = 1;
    memset(visited, 0, sizeof(visited));
    visited[start] = true;

    printf("%s", zip[start]);
    while (num_visited < n)
	{
		memset(used, 0, sizeof(used));
		int num_used = 0;
		int bound = -1;
		while (num_used + num_visited < n)
		{
			++bound;
            num_used += dfs(link[bound]) - 1;
		}

		int next = -1, root_bound = -1;
		for (int i = bound; i < (int)link.size(); ++i)
		{
            for (int j = 0; j < n; ++j)
			{
				if (!go[link[i]][j] || visited[j]) continue;
				if (next < 0 || strcmp(zip[j], zip[next]) <= 0)
				{
					next = j;
					root_bound = i;
				}
			}
		}

//		printf("link:");
//		for (int i = 0; i < (int)link.size(); ++i) printf(" %d", link[i]);
//		puts("");
//		printf("bound=%d root_bound=%d next=%d\n", bound, root_bound, next);

		link.resize(root_bound + 1);
		visited[next] = true;
		link.push_back(next);

		printf("%s", zip[next]);
		++num_visited;
	}
	puts("");
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int cs = 1; cs <= t; ++cs)
	{
		init();
		printf("Case #%d: ", cs);
		solve();
	}
	return 0;
}
