#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<int> g[1005];
int N;

bool bfs(int n)
{
	bool visited[1005] = {false};
	queue<int> que;

	visited[n] = true;
	que.push(n);

	while (que.empty() == false)
	{
		int t = que.front();
		que.pop();

		for (int i = 0; i < g[t].size(); i++)
		{
			int next = g[t][i];
			if (visited[next]) return true;
			visited[next] = true;
			que.push(next);
		}
	}
	return false;
}

int main()
{
	int TT;
	scanf("%d",&TT);
	for (int tt = 1; tt <= TT; tt++)
	{
		printf("Case #%d: ", tt);
		scanf("%d",&N);
		for (int i = 1; i <= N; i++)
		{
			g[i].clear();
			int x;
			scanf("%d",&x);
			while (x--)
			{
				int tmp;
				scanf("%d",&tmp);
				g[i].push_back(tmp);
			}
		}

		bool wrong = false;
		for (int i = 1; i <= N; i++)
		{
			if (bfs(i))
			{
				wrong = true;
				break;
			}
		}

		printf(wrong ? "Yes\n" : "No\n");
	}
	return 0;
}