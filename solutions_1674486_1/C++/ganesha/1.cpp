#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

map<int,vector<int> > graph;
int visited[1010];

bool dfs(int u)
{
	bool fpath = false;
	visited[u] = 1;
	vector<int> edges = graph[u];
	for (int i = 0; i < edges.size(); i++)
	{
		int v = edges[i];
		//printf("Edge %d\n",v);
		if (visited[v] == 0)
		{
			fpath = dfs(v);
			if (fpath) return true;
		}
		else 
			return true;
	}
	return fpath;
}

int main()
{
	int t,N,E,v;
	bool fpath = false;
	scanf("%d",&t);
	for (int tc = 1; tc <=t; tc++)
	{
		scanf("%d",&N);
		graph.clear();
		for (int i = 1; i <= N; i++)
		{
			scanf("%d",&E);
			for (int j = 1; j <= E; j++)
			{	
				scanf("%d",&v);
				graph[v].push_back(i);	
			}
		}
	

		for (int i = 1; i <= N; i++)
		{
			memset(visited,0,sizeof(visited));
			//printf("DFS: %d\n",i);
			fpath = dfs(i);
			if (fpath)
				break;
		}

		if (fpath)
			printf("Case #%d: Yes",tc);
		else
			printf("Case #%d: No",tc);
			
		printf("\n");
	}

	return 0;
}

