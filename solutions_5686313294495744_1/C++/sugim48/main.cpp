#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

struct flow_network {
	int n;
	struct edge { int v; ll c; int rev; };
	vector< vector<edge> > G;
	flow_network(int _n) : n(_n), G(_n) {}
	void add_edge(int u, int v, ll c) {
		edge e = {v, c, (int)G[v].size()}, _e = {u, 0, (int)G[u].size()};
		G[u].push_back(e); G[v].push_back(_e);
	}
	ll dfs(int u, int t, ll f, vector<bool>& vis) {
		if (u == t) return f;
		vis[u] = true;
		for (int i = 0; i < G[u].size(); i++) {
			edge& e = G[u][i];
			if (vis[e.v] || e.c == 0) continue;
			ll d = min(e.c, dfs(e.v, t, min(f, e.c), vis));
			if (d == 0) continue;
			e.c -= d;
			G[e.v][e.rev].c += d;
			return d;
		}
		return 0;
	}
	ll max_flow(int s, int t) {
		ll res = 0;
		for (;;) {
			vector<bool> vis(n);
			ll f = dfs(s, t, LLONG_MAX, vis);
			if (f == 0) return res;
			res += f;
		}
	}
};

int main() {
	int T; cin >> T;
	for (int _t = 1; _t <= T; _t++) {
		int N; cin >> N;
		vector<string> s(N), t(N);
		for (int i = 0; i < N; i++)
			cin >> s[i] >> t[i];
		vector<string> S = s, T = t;
		sort(S.begin(), S.end());
		sort(T.begin(), T.end());
		S.erase(unique(S.begin(), S.end()), S.end());
		T.erase(unique(T.begin(), T.end()), T.end());
		int n1 = S.size(), n2 = T.size();
		vector<int> a(N), b(N);
		for (int i = 0; i < N; i++) {
			a[i] = lower_bound(S.begin(), S.end(), s[i]) - S.begin();
			b[i] = lower_bound(T.begin(), T.end(), t[i]) - T.begin();
		}
		flow_network fn(n1 + n2 + 2);
		for (int u = 0; u < n1; u++)
			fn.add_edge(n1 + n2, u, 1);
		for (int u = 0; u < n2; u++)
			fn.add_edge(n1 + u, n1 + n2 + 1, 1);
		for (int i = 0; i < N; i++)
			fn.add_edge(a[i], n1 + b[i], 1);
		int x = fn.max_flow(n1 + n2, n1 + n2 + 1);
		printf("Case #%d: %d\n", _t, N - (n1 + n2 - x));
	}
}
