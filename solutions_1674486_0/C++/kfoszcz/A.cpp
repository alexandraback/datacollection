#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1001;

vector<int> G[MAXN];
bool visited[MAXN];

bool bad;

void DFS(int u)
{
	//printf("%d ", u);
	if (bad) return;
	visited[u] = true;
	int size = G[u].size();
	for (int i = 0; i < size; i++)
	{
		int v = G[u][i];
		if (!visited[v])
			DFS(v);
		else
		{	
			//printf("!!!");
			bad = true;
			return;
		}
	}
}

int main()
{
	int z;
	scanf("%d", &z);
	for (int nr = 1; nr <= z; nr++)
	{
		int n;
		scanf("%d", &n);
		// clear
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
			visited[i] = false;
		}
		int edges = 0;
		for (int i = 1; i <= n; i++)
		{
			int s;
			scanf("%d", &s);
			edges += s;
			while (s--)
			{
				int b;
				scanf("%d", &b);
				//G[b].push_back(i);
				G[i].push_back(b);
			}
		}
		bad = false;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				visited[j] = false;
			DFS(i);
			//printf("\n");
			if (bad) break;
		}
		if (!bad)
			printf("Case #%d: No\n", nr);
		else
			printf("Case #%d: Yes\n", nr);
	}
	return 0;
}
