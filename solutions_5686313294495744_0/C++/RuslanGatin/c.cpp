#define _CRT_SECURE_NO_DEPRECATE
#pragma comment (linker, "/stack:256000000")

#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <bitset>
#include <map>
#include <memory.h>
#undef NDEBUG
#include <cassert>
#include <ctime>

using namespace std;

#define fo(a,b,c) for (int a = (b); a < (c); a++)
#define fr(a,b) fo(a, 0, (b))
#define fi(n) fr(i, (n))
#define fj(n) fr(j, (n))
#define fk(n) fr(k, (n))
#define fd(a,b,c) for (int a = (b); a >= (c); a--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define _(a,b) memset((a), (b), sizeof(a))
#define __(a) memset((a), 0, sizeof(a))
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long lint;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> pii;

const int INF = 1000000000;
const lint LINF = 4000000000000000000LL;
const double eps = 1e-9;

int ni() { int a; scanf( "%d", &a ); return a; }
double nf() { double a; scanf( "%lf", &a ); return a; }
char sbuf[100005]; string ns() { scanf( "%s", sbuf ); return sbuf; }
long long nll() { long long a; scanf( "%lld", &a ); return a; }

void prepare()
{
	freopen("input.txt", "r", stdin);
	freopen("c-small.in", "r", stdin);
	freopen("c-small.out", "w", stdout);
	//freopen("-large.in", "r", stdin);
	//freopen("-large.out", "w", stdout);
}

const int maxn = 4010;

int n;
vector<int> g[maxn];
pair<string, string> w[maxn];
map<string, int> ma[2];
int mt[maxn];
int used[maxn];
int tt;
map<string, int> ca;

struct Edge
{
	int a, b, id;
	int flow, cap;
	Edge(){}
	Edge(int a, int b, int c, int _id): a(a), b(b), cap(c), flow(0), id(_id)
	{
	}
};

vector < Edge > e;
int d[maxn], ptr[maxn];
queue < int > q;
int vCount;
int S, T, SS, TT;


bool bfs()
{
	memset(d, -1, sizeof(d[0]) * vCount);
	d[SS] = 0;
	q.push(SS);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i = 0; i < sz(g[v]); i ++)
		{
			Edge &t = e[g[v][i]];
			if (d[t.b] < 0 && t.flow < t.cap)
			{
				d[t.b] = d[v] + 1;
				q.push(t.b);
			}
		}
	}
	return d[TT] >= 0;
}

int dfs(int v, int flow)
{
	if (flow == 0 || v == TT)
		return flow;
	for (; ptr[v] < sz(g[v]); ptr[v] ++)
	{
		Edge &t = e[g[v][ptr[v]]];
		if (d[t.b] == d[v] + 1)
		{
			int cur = dfs(t.b, min(flow, t.cap - t.flow));
			if (cur)
			{
				t.flow += cur;
				e[t.id ^ 1].flow -= cur;
				return cur;
			}
		}
	}
	return 0;
}

int dinic()
{
	int ret = 0, add;
	while (bfs())
	{
		memset(ptr, 0, sizeof(ptr[0]) * vCount);
		while (1)
		{
			add = dfs(SS, INF);
			if (add == 0)
				break;
			ret += add;
		}
	}
	return ret;
}

void adde(int a, int b, int cap)
{
	int id = sz(e);
	g[a].pb(id);
	e.pb(Edge(a, b, cap, id));

	id = sz(e);
	g[b].pb(id);
	e.pb(Edge(b, a, 0, id));
}

void read()
{
	n = ni();
	fi(n)
	{
		w[i].first = ns();
		w[i].second = ns();
	}
}

int getId(string &s, int ld)
{
	int cc = sz(ma[ld]);
	if (ma[ld].find(s) == ma[ld].end())
		ma[ld][s] = cc;
	return ma[ld][s];
}

bool dfs(int id)
{
	if (used[id] == tt)
		return false;
	used[id] = tt;
	for (int i = 0; i <sz(g[id]); i++)
	{
		int to = g[id][i];
		if (mt[to] < 0 || dfs(mt[to]))
		{
			mt[to] = id;
			return true;
		}
	}
	return false;
}

bool check()
{
	//fi(sz(e))
	//{
	//	if (i % 2 == 0)
	//	//if (e[i].flow > 0)
	//		printf("%d %d %d\n", e[i].a, e[i].b, e[i].flow);
	//}
	fi(sz(g[SS]))
	{
		if (e[g[SS][i]].flow == 0)
			return false;
	}
	fi(sz(g[TT]))
	{
		int id = g[TT][i];
		if (e[id ^ 1].flow == 0)
			return false;
	}
	return true;
}

int go()
{
	int lb = 0, rb = n + 1;
	while (rb - lb > 1)
	{
		int mid = (rb + lb) >> 1;
		fi(sz(e))
			e[i].flow = 0;
		e.back().cap = mid;
		e[e.back().id ^ 1].cap = mid;
		int d = dinic();
		if (check())
			rb = mid;
		else
			lb = mid;
	}
	return rb;
}

void solve(int test_num)
{
	//cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	fi(maxn)
		g[i].clear();
	ma[0].clear();
	ma[1].clear();
	ca.clear();

	e.clear();
	vCount = 0;

	fi(n)
		getId(w[i].first, 0);
	int nLeft = sz(ma[0]);
	fi(n)
		getId(w[i].second, 1);
	int nRight = sz(ma[1]);
	S = nLeft * 2 + nRight * 2;
	T = S + 1;
	SS = T + 1;
	TT = SS + 1;
	vCount = TT + 1;

	fi(n)
	{
		int a = getId(w[i].first, 0);
		int b = getId(w[i].second, 1);
		adde(a + nLeft, b + nLeft * 2, 1);
	}
	fi(nLeft)
	{
		int a = i;
		int b = i + nLeft;
		adde(a, b, INF);
		adde(S, a, INF);
		adde(a, TT, 1);
		adde(SS, b, 1);
	}
	fi(nRight)
	{
		int a = i + nLeft * 2;
		int b = i + nLeft * 2 + nRight;
		adde(a, b, INF);
		adde(b, T, INF);
		adde(a, TT, 1);
		adde(SS, b, 1);
	}
	adde(T, S, INF);
	
	printf("%d\n", n - go());
}

int main()
{
	prepare();
	int number_of_tests;
	scanf("%d\n", &number_of_tests);
	fi(number_of_tests)
	{
		read();
		solve(i + 1);
	}
	return 0;
}