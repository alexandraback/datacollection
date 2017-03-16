#include <iostream>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef long long lint;
typedef unsigned long long ull;

const int INF = 1000000000;
const lint LINF = 1000000000000000000ll;
const double eps = 1e-8;

int a, b, c, r;
int pa[15][15], pb[15][15], used[15][15][15];

struct edge {
	edge(int src, int dest, int cap, int flow) : src(src), dest(dest), cap(cap), flow(flow)
	{

	}
	int src;
	int dest;
	int cap;
	int flow;
};

const int S = 201;
const int T = 202;
int n, d[1005], ptr[1005], q[1005];
vector<edge> e;
vector<int> g[1005];

void addedge(int src, int dest, int cap) {
	edge e1(src, dest, cap, 0);
	edge e2(dest, src, 0, 0);
	g[src].push_back(e.size());
	e.push_back(e1);
	g[dest].push_back(e.size());
	e.push_back(e2);
}

bool bfs() {
	int qh = 0, qt = 0;
	q[qt++] = S;
	memset(d, -1, sizeof(d));
	d[S] = 0;
	while (qh < qt && d[T] == -1) {
		int v = q[qh++];
		for (size_t i = 0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].dest;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[T] != -1;
}

int dfs(int v, int flow) {
	if (flow == 0)
		return 0;
	if (v == T)
		return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].dest;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id ^ 1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

int maxflow() {
	int flow = 0;
	while (true)
	{
		if (!bfs())
			break;
		memset(ptr, 0, sizeof(ptr));
		while (true)
		{
			int addf = dfs(S, INF);
			if (addf == 0)
				break;
			flow += addf;
		}
			
	}
	return flow;
}

struct comb
{
public:
	comb(int a, int b, int c): a(a), b(b), c(c)
	{
	}

	int a;
	int b;
	int c;
};

void solve()
{
	scanf("%d%d%d%d", &a, &b, &c, &r);

	for (int i = 0; i < 1005; i++)
		g[i].clear();
	e.clear();
	n = 203;
	
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
		{
			int p1 = i * 10 + j;

			for (int k = 0; k < c; k++)
			{
				int p2 = 100 + j * 10 + k;
				addedge(p1, p2, 1);
			}

			addedge(S, p1, r);
		}

	for (int i = 0; i < b; i++)
		for (int j = 0; j < c; j++)
		{
			int p2 = 100 + i * 10 + j;
			addedge(p2, T, r);
		}

	int anscnt = maxflow();

	vector<comb> ans;

	for (int i = 0; i < e.size(); i++)
		if (e[i].flow > 0 && e[i].src < 100 && e[i].dest >= 100 && e[i].dest < 200)
		{
			int ai = e[i].src / 10;
			int bi = e[i].src % 10;
			int ci = e[i].dest % 10;
			ans.pb(comb(ai, bi, ci));
		}

	printf("%d\n", anscnt);
	for (int i = 0; i < ans.size(); i++)
		printf("%d %d %d\n", ans[i].a + 1, ans[i].b + 1, ans[i].c + 1);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tn;
	scanf("%d", &tn);
	for (int i = 0; i < tn; i++)
	{
		printf("Case #%d: ", i + 1);
		solve();
	}

	return 0;
}
