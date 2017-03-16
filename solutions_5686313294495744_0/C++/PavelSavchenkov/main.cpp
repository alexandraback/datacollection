#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"


const int MAXN = 1e5 + 10;
const int INF = 1e9;

struct Edge {
	int v, to, flow, cap, cost;
};

int dist[MAXN];
int Q[MAXN];
int ql, qr;
int prev[MAXN];

struct Graph {
	vector<Edge> es;
	vvi g;
	int n;

	Graph(int n = 0) : n(n) {
		g.resize(n);
	}

	int addE(int a, int b, int cap, int cost) {
		int ret = sz(es);

		g[a].pb(sz(es));
		es.pb(Edge{ a, b, 0, cap, cost });

		g[b].pb(sz(es));
		es.pb(Edge{ b, a, 0, 0, -cost });

		return ret;
	}

	void change(int id, int new_cap) {
		es[id].cap = new_cap;
		// printf("change %d\n", new_cap);
	}

	int add_flow() {
		forn(v, n) {
			dist[v] = INF;
			prev[v] = -1;
		}
		dist[0] = 0;

		ql = qr = 0;
		Q[qr++] = 0;
		while (ql != qr) {
			int v = Q[ql++];
			for (int id : g[v]) {
				if  (es[id].cap > es[id].flow && dist[es[id].to] > dist[v] + es[id].cost) {
					Q[qr++] = es[id].to;
					prev[es[id].to] = id;
					dist[es[id].to] = dist[v] + es[id].cost;
				}
			}
		}

		if  (prev[n - 1] == -1) {
			return false;
		}

		int v = n - 1;
		int add = INF;
		while (v) {
			int id = prev[v];
			add = min(add, es[id].cap - es[id].flow);
			v = es[id].v;
		}

		v = n - 1;
		while (v) {
			int id = prev[v];
			es[id].flow += add;
			es[id ^ 1].flow -= add;
			v = es[id].v;
		}

		return add;
	}

	int min_cost() {
		int f = 0;
		while (1) {
			int cur = add_flow();
			if  (!cur) {
				break;
			}
			f += cur;
		}

		int cost = 0;
		forn(v, n) {
			for (int id : g[v]) {
				if  (es[id].flow > 0) {
					cost += es[id].flow * es[id].cost;
				}
				es[id].flow = 0;
			}
		}

		// printf("flow = %d, cost = %d\n", f, cost);

		return cost;
	}
};

vector<string> s;
vector<string> t;
vii a;
int n;

bool read() {
	if  (scanf("%d\n", &n) < 1) {
		return false;
	}
	static char S[MAXN];
	static char T[MAXN];
	s.clear();
	t.clear();
	forn(i, n) {
		scanf("%s %s\n", S, T);
		s.pb(string(S));
		t.pb(string(T));
	}
	return true;
}

vector<string> left, right;

void compress() {
	a.resize(n);

	left.clear();
	forn(i, n) {
		left.pb(s[i]);
	}
	sort(all(left));
	left.resize(unique(all(left)) - left.begin());
	forn(i, n) {
		a[i].fst = lower_bound(all(left), s[i]) - left.begin();
	}

	right.clear();
	forn(i, n) {
		right.pb(t[i]);
	}
	sort(all(right));
	right.resize(unique(all(right)) - right.begin());
	forn(i, n) {
		a[i].snd = lower_bound(all(right), t[i]) - right.begin();
	}
}

int solve() {
	compress();

	Graph g(2 + sz(left) + sz(right) + 1);
	int id_change = g.addE(0, 1, 0, 0);
	forn(i, sz(left)) {
		g.addE(1, 2 + i, 1, -1);
		g.addE(1, 2 + i, INF, 0);
	}

	forn(k, n) {
		int i = a[k].fst;
		int j = a[k].snd;
		g.addE(2 + i, 2 + sz(left) + j, 1, 0);
	}

	forn(j, sz(right)) {
		g.addE(2 + sz(left) + j, 2 + sz(left) + sz(right), 1, -1);
		g.addE(2 + sz(left) + j, 2 + sz(left) + sz(right), INF, 0);
	}

	int L = -1;
	int R = n + 1;
	while (L != R - 1) {
		int M = (L + R) / 2;
		g.change(id_change, M);
		if  (-g.min_cost() == sz(left) + sz(right)) {
			R = M;
		} else {
			L = M;
		}
	}

	return n - R;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	freopen(FILE_NAME ".out", "w", stdout);
#endif

	int T;
	scanf("%d\n", &T);
	forn(tt, T) {
		assert(read());
		printf("Case #%d: %d\n", tt + 1, solve());
		// break;
	}

	return 0;
}
