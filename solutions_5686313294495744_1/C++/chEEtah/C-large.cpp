#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;

char a[100], b[100];
map<string, int> dict[2];
int sizeDict[2];

int x[1000], y[1000];

int lookup(int k, string s)
{
	if (dict[k].count(s)) return dict[k][s];
	sizeDict[k]++;
	dict[k][s] = sizeDict[k] - 1;
	return sizeDict[k] - 1;
}

class Graph
{
	public:

	std::vector< std::vector<int> > to, c, f;

	Graph(int n = 0) : to(n), c(n), f(n) { }
	Graph(const Graph &g) : to(g.to), c(g.c), f(g.f) {}
	
	void addArc(int src, int dst, int capacity)
	{
		to[src].push_back(dst);
		c[src].push_back(capacity);
		f[src].push_back(0);

		to[dst].push_back(src);
		c[dst].push_back(0);
		f[dst].push_back(0);
	}

	std::vector<int> pre;
	std::vector<int> val;
	void bfs(int src)
	{
		pre.assign(to.size(), -1);
		val.assign(to.size(), -1);
		std::queue<int> Q;
		Q.push(src);
		while(!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			for(int i = 0; i < to[u].size(); i++)
			{
				int v = to[u][i];
				if (pre[v] != -1) continue;
				if (c[u][i] == f[u][i]) continue;
				pre[v] = u;
				int rest = c[u][i] - f[u][i];
				if (u == src) val[v] = rest; else val[v] = std::min(rest, val[u]);
				Q.push(v);
			}
		}
	}

	// successive BFS (Ford Fulkerson)
	int maxFlow(int src, int dst)
	{
		while(1)
		{
			bfs(src);
			if (pre[dst] == -1) break; 
			int v = dst;
			int delta = val[dst];
			while(v != src)
			{
				int u = pre[v];
				for(int i = 0; i < to[v].size(); i++)
				if (to[v][i] == u)
				{
					f[v][i] -= delta;
					break;
				}
				for(int i = 0; i < to[u].size(); i++)
				if (to[u][i] == v)
				{
					f[u][i] += delta;
					break;
				}
				v = u;					
			}
		}
		int res = 0;
		for(int i = 0; i < to[src].size(); i++) res += f[src][i];
		return res;
	}
};


int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		dict[0].clear();
		sizeDict[0] = 0;
		dict[1].clear();
		sizeDict[1] = 0;

		int n;
		scanf("%d", &n);

		for(int i = 0; i < n; i++)
		{
			scanf("%s %s", a, b);
			x[i] = lookup(0, a);
			y[i] = lookup(1, b);
		}

		Graph g(sizeDict[0] + sizeDict[1] + 2);
		// 0 -- src
		// 1..sizeDict[0]
		// sizeDict[0] + 1 .. sizeDict[0] + sizeDict[1]
		// sizeDict[0] + sizeDict[1] + 1 -- dst
		int src = 0, dst = sizeDict[0] + sizeDict[1] + 1;
		for(int i = 0; i < sizeDict[0]; i++) g.addArc(src, i + 1, 1);
		for(int i = 0; i < sizeDict[1]; i++) g.addArc(sizeDict[0] + 1 + i, dst, 1);
		for(int i = 0; i < n; i++) g.addArc(x[i] + 1, sizeDict[0] + 1 + y[i], 1);

		int res = sizeDict[0] + sizeDict[1] - g.maxFlow(src, dst);

		printf("%d\n", n - res);
	}
	return 0;
}