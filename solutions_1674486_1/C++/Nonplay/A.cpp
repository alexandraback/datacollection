#include <cstdlib>
#include <cstdio>
#include <list>
#include <cstring>

using namespace std;

const int MAX_NODES = 1000+1;

list<int> adj[MAX_NODES];
bool isLeaf[MAX_NODES];
bool visited[MAX_NODES];
int nodes;

void read_input()
{
	int elems, q;
	scanf("%d", &nodes);
	for (int n = 1; n <= nodes; n++)
	{
		adj[n].clear();
		isLeaf[n] = false;
	}
	
	for (int n = 1; n <= nodes; n++)
	{
		scanf("%d", &elems);
		if (elems == 0) isLeaf[n] = true;
		for (int i = 0; i < elems; i++)
		{
			scanf("%d", &q);
			// Inverto archi
			adj[q].push_back(n);
//			printf("adding %d - %d\n", q, n);
		}
	}
}

bool dfs(int n)
{
	if (visited[n]) return true;
	visited[n] = true;
	
	for (list<int>::iterator pos = adj[n].begin(); pos != adj[n].end(); ++pos)
		if (dfs(*pos)) return true;
	return false;
}

bool isDiamondPath() 
{
	for (int n = 1; n <= nodes; n++)
		if (isLeaf[n]) 
		{
			memset(visited, 0, sizeof(visited));
			if (dfs(n))
				return true;
		}
	return false;
}

int main()
{
	int cases;
	scanf("%d", &cases);
	for (int c = 1; c <= cases; c++) 
	{
		read_input();
		if (isDiamondPath()) 
			printf("Case #%d: Yes\n", c);
		else
			printf("Case #%d: No\n", c);
	}
	return 0;
}

