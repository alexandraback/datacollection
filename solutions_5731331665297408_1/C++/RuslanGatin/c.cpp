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

int ni() { int a; scanf("%d", &a); return a; }
double nf() { double a; scanf("%lf", &a); return a; }
char sbuf[100005]; string ns() { scanf("%s", sbuf); return sbuf; }
long long nll() { long long a; scanf("%lld", &a); return a; }

void prepare()
{
	freopen("input.txt", "r", stdin);
	freopen("c-small.in", "r", stdin);
	freopen("c-small.out", "w", stdout);
	freopen("c-large.in", "r", stdin);
	freopen("c-large.out", "w", stdout);
}

const int maxn = 55;

struct Edge
{
	int a, b, id, del;
};

vector<Edge> e;
vector<int> g[maxn];
string zip[maxn];
int T;
set<string> se, used;
vector<pii> stack;
string res;
int us[maxn];
int n, m;
int foreverDel[maxn];

void init()
{
	e.clear();
	for (int i = 0; i < maxn; i++)
		g[i].clear();
	T = 0;
	se.clear();
	used.clear();
	stack.clear();
	res = "";
	_(us, 0);
	_(foreverDel, 0);
}

void adde(int a, int b)
{
	Edge t;
	t.a = a;
	t.b = b;
	t.id = sz(e);
	g[a].pb(t.id);
	e.pb(t);

	swap(t.a, t.b);
	t.id++;
	g[b].pb(t.id);
	e.pb(t);
}

int dfs2(int id, int start)
{
	if (us[id] == T || foreverDel[id])
		return 0;
	us[id] = T;
	int res = 1;
	for (int i = 0; i < sz(g[id]); i++)
		res += dfs2(e[g[id][i]].b, start);
	return res;
}

bool check(int id)
{
	int r = 0;
	us[id] = 0;
	fi(n)
	{
		if (foreverDel[i])
			r++;
	}
	return dfs2(id, id) == n - r;
}

void delEdge(int id)
{
	e[id].del++;
	e[id ^ 1].del++;
}

void udelEdge(int id)
{
	e[id].del--;
	e[id ^ 1].del--;
}

int start;
void dfs(int id, int reb)
{
	stack.push_back(mp(id, reb));
	used.insert(zip[id]);
	res += zip[id];
	fi(sz(g[id]))
	{
		int to = e[g[id][i]].b;
		se.insert(zip[to]);
	}
	for (set<string>::iterator it = used.begin(); it != used.end(); ++it)
		se.erase(*it);
	if (se.empty())
	{
		if (reb >= 0)
		{
			delEdge(reb);
			stack.pop_back();
		}
		return;
	}
	for (set<string>::iterator it = se.begin(); it != se.end(); ++it)
	{
		for (int si = sz(stack) - 1; si >= 0; si--)
		{
			int v = stack[si].first;
			fi(sz(g[v]))
			{
				int to = e[g[v][i]].b;
				if (zip[to] == *it)
				{
					T++;
					fd(j, sz(stack) - 1, si + 1)
					{
						delEdge(stack[j].second);
						foreverDel[stack[j].first]++;
					}
					if (check(start))
					{
						stack.erase(stack.begin() + si + 1, stack.end());
						dfs(to, g[v][i]);
						return;
					}
					else
					{
						fd(j, sz(stack) - 1, si + 1)
						{
							udelEdge(stack[j].second);
							foreverDel[stack[j].first]--;
						}
					}
				}
			}
		}
	}
	if (reb >= 0)
	{
		delEdge(reb);
		stack.pop_back();
	}
}

void read()
{
	init();
	n = ni();
	m = ni();
	fi(n)
		zip[i] = ns();
	fi(m)
	{
		int a = ni(), b = ni();
		a--;
		b--;
		adde(a, b);
	}
}

void solve(int test_num)
{
	//cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	int mn = -1;
	fi(n)
	{
		if (mn < 0 || zip[i] < zip[mn])
			mn = i;
	}
	start = mn;
	dfs(mn, -1);
	printf("%s\n", res.c_str());
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