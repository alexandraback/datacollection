#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int graph[1005];
vector<int> backedge[1005];
bool visited[1005];
bool now[1005];
int T[1005];

bool dfs(int n)
{
	if (visited[graph[n]])
	{
		return now[n];
	}
	visited[graph[n]] = true;
	now[graph[n]] = true;
	if (dfs(graph[n])) return true;
	now[graph[n]] = false;
	return false;
}

int getcycle(int n)
{
	int total = 1;
	T[n] = 0;
	int j = 1, i;
	for (i = graph[n]; T[i] == 0; T[i] = j++, i = graph[i]) total++;
	return j - T[i];
}

int getleng(int a)
{
	int ret = 0;

	for (auto next : backedge[a])
	{
		ret = max(ret, getleng(next));
	}
	return ret + 1;
}

int getpath(int a, int b)
{
	int ca = 0, cb = 0;
	for (int i : backedge[a])
	{
		if (i != b) ca = max(ca, getleng(i));
	}
	for (int i : backedge[b])
	{
		if (i != a) cb = max(cb, getleng(i));
	}
	return ca + cb + 2;
}

int main()
{
	freopen(R"(C:\Users\Unused\Downloads\C-small-attempt3.in)", "r", stdin);
	freopen(R"(C:\Users\Unused\Downloads\C-small.out)", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++)
	{
		printf("Case #%d: ", tt);

		int N;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			backedge[i].clear();
		}
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &graph[i]);
			backedge[graph[i]].push_back(i);
		}

		int ans = 0;
		for (int i = 1; i <= N; i++)
		{
			visited[i] = true;
			now[i] = true;
			if (dfs(i))
			{
				memset(::T, 0, sizeof(::T));
				ans = max(ans, getcycle(i));
			}
			visited[i] = false;
			now[i] = false;
		}

		int indivsum = 0;
		for (int i = 1; i <= N; i++)
		{
			int t = graph[i];
			if (i < t && graph[t] == i)
			{

				indivsum += getpath(i, t);
			}
		}

		printf("%d\n", max(ans, indivsum));
	}
}