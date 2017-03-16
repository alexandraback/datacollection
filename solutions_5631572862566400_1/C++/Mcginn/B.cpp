#include<stdlib.h>
#include<time.h>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<set>
#include<queue>
#include<bitset>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long UL;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define sz(x) ((int)(x.size()))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int N = 1e3 + 7;
const int P = 1e7 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e7;
const double EPS = 1e-10;
int n, m, f[N], p[N], g[N];
bool v[N];
vi w[N];
void dfs(int u) {
	v[u] = true, g[u] = 1;
	for (int i = 0; i < sz(w[u]); ++i)
		if (!v[w[u][i]]) {
			dfs(w[u][i]);
			g[u] = max(g[u], 1 + g[w[u][i]]);
		}
}
int main() {
	freopen("C-large.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int _c = 1; _c <= T; ++_c) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			w[i].clear();
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &f[i]);
			w[f[i]].pb(i);
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j)
				v[j] = false;
			int x = i, y = 0;
			while (!v[x]) {
				v[x] = true, p[x] = y;
				if (v[f[x]]) {
					ans = max(ans, y - p[f[x]] + 1);
					break;
				}
				x = f[x], ++y;
			}
		}
		int ret = 0;
		for (int i = 1; i <= n; ++i) {
			v[i] = false;
		}
		for (int i = 1; i <= n; ++i)
			if (!v[i] && f[f[i]] == i) {
				v[i] = v[f[i]] = true;
				dfs(i);
				ret += g[i];
				dfs(f[i]);
				ret += g[f[i]];
			}
		printf("Case #%d: %d\n", _c, max(ans, ret));
	}
	return 0;
}
