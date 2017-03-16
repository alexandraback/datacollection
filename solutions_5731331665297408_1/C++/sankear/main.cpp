#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define len(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || __WIN32__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define hash _hash
#define y0 yy0
#define y1 yy1
#define link _link

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 55;

int n;
vi ans, res;
bool used[N];
int p[N], a[N];
vi g[N];

inline bool cmp(int p1, int p2) {
	return a[p1] < a[p2];
}

int iter;

void dfs(int v) {
	++iter;
	if (iter > int(4e7)) {
		return;
	}
	if (sz(ans) == n && res >= ans) {
		return;
	}
	if (sz(res) == n) {
		ans = res;
		return;
	}
	for (int i = 0; i < sz(g[v]); ++i) {
		if (!used[g[v][i]]) {
			used[g[v][i]] = true;
			p[g[v][i]] = v;
			res.pb(a[g[v][i]]);
			dfs(g[v][i]);
			res.pop_back();
			used[g[v][i]] = false;
		}
	}
	if (p[v] != -1) {
		dfs(p[v]);
	}
}
	
inline void solve() {
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i) {
		g[i].clear();
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a;
		--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	for (int i = 0; i < n; ++i) {
		sort(g[i].begin(), g[i].end(), cmp);
		used[i] = false;
	}
	int best = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] < a[best]) {
			best = i;
		}
	}
	p[best] = -1;
	used[best] = true;
	ans.clear();
	res.clear();
	res.pb(a[best]);
	iter = 0;
	dfs(best);
	assert(sz(ans) == n);
	for (int i = 0; i < sz(ans); ++i) {
		printf("%d", ans[i]);
	}
	puts("");
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d: ", i + 1);
		solve();
		cerr << "TEST " << i << endl;
	}
	return 0;
}
