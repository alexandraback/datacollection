#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define MAX_N 1000
#define INF (1<<30)

struct edge
{
	int s, e;
	bool operator < (const edge &a) const
	{
		return (e < a.e);
	}
};

char buff[MAX_N+5];

vector<string> names_left;
vector<string> names_right;

int get(vector<string> &names, const string &s)
{
	for (int i=0; i<names.size(); ++i)
		if (s == names[i])
			return i;
	names.push_back(s);
	return names.size()-1;
}

vector<vector<int>> edges;
bool was[MAX_N*2];
int p[MAX_N*2];

void push(int a, int b)
{
	/*int c = (a < b ? b : a);
	if (c >= edges_idx.size())
		edges_idx.resize(c+1);*/
	if (a >= edges.size())
		edges.resize(a+1);
	edges[a].push_back(b);
	//edges_idx[b].push_back(a);
}

bool dfs(int i)
{
	if (was[i])
		return false;
	was[i] = true;
	for (int j=0; j<edges[i].size(); ++j)
	{
		int t = edges[i][j];
		if (p[t] == -1 || dfs(p[t]))
		{
			p[t] = i;
			return true;
		}
	}
	return false;
}

int main()
{
	int T;
	int N;
	scanf("%d\n", &T);

	for (int t=0; t<T; ++t)
	{
		scanf("%d\n", &N);
		edges.clear();
		names_left.clear();
		names_right.clear();
		//edges_idx.clear();
		for (int i=0; i<N; ++i)
		{
			scanf("%s", buff);
			edge e;
			e.s = get(names_left, buff);
			scanf("%s\n", buff);
			e.e = get(names_right, buff);
			//printf("%d %d\n", e.s, e.e);
			//edges.push_back(e);
			push(e.s, e.e);
		}
		for (int i=0; i<N; ++i)
			p[i] = -1;
		/*for (int i=0; i<N; ++i)
		{
			e.e += names_left.size();
			push(e.s, e.e);
		}*/

		int total = 0;
		int used = 0;
		for (int i=0; i<names_left.size(); ++i)
		{
			memset(was, 0, sizeof(was));
			dfs(i);
			++total;
		}

		for (int i=0; i<names_right.size(); ++i)
		{
			++total;
			if (p[i] != -1)
				++used;
		}

		//printf("N:%d total:%d used:%d\n", N, total, used);
		int res = N - used - (total - used * 2);
		printf("Case #%d: %d\n", t+1, res);
	}
	return 0;
}
