#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <list>
#include <map>
#include <set>

#include <algorithm>

using namespace std;

bool dfs(const vector< vector<int> >& graph, set<int>& visited, int start)
{
	int n = graph.size();

	for(int j = 0; j < graph[start].size(); j++)
	{
		if(visited.find(graph[start][j]) != visited.end())
		{
			return true;
		}
		else
		{
			visited.insert(graph[start][j]);

			if(dfs(graph, visited, graph[start][j]))
			{
				return true;
			}
		}
	}

	return false;
}

int main(int argc, char **argv)
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		int N;
		scanf("%d", &N);
		vector< vector<int> > graph(N);

		int Msum = 0;
		for(int i = 0; i < N; i++)
		{
			int M;
			scanf("%d", &M);
			graph[i] = vector<int>(M);

			for(int j = 0; j < M; j++)
			{
				scanf("%d", &graph[i][j]);
				graph[i][j]--;
			}

			Msum += M;
		}

		int i;
		for(i = 0; i < N; i++)
		{
			if(dfs(graph, set<int>(), i))
			{
				printf("Case #%d: Yes\n", t);

				break;
			}
		}

		if(i == N)
		{
			printf("Case #%d: No\n", t);
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}