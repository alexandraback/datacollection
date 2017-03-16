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

int n;
bool can[100][100];
string a[100], ans, res;
int lst[100];
bool used[100];
vi g[100];

inline bool cmp(int p1, int p2) {
	return a[p1] < a[p2];
}

void dfs(int v) {
	res += a[v];
	vi sons = g[v];
	sort(sons.begin(), sons.begin(), cmp);
	for (int i = 0; i < sz(sons); ++i) {
		dfs(sons[i]);
	}
}

void gen(int pos) {
	if (pos >= n) {
		res = "";
		dfs(lst[0]);
		ans = min(ans, res);
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		for (int j = 0; j < pos; ++j) {
			if (can[i][lst[j]]) {
				g[lst[j]].pb(i);
				used[i] = true;
				lst[pos] = i;
				gen(pos + 1);
				used[i] = false;
				g[lst[j]].pop_back();
			}
		}
	}
}

inline void solve() {
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			can[i][j] = false;
		}
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		can[x][y] = can[y][x] = true;
	}
	ans = "";
	for (int i = 0; i < 6 * n; ++i) {
		ans.pb('9');
	}
	int pos = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] < a[pos]) {
			pos = i;
		}
	}
	lst[0] = pos;
	used[pos] = true;
	gen(1);
	used[pos] = false;
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cout << "Case #" << i + 1 << ": ";
		solve();
		cerr << "TEST " << i << endl;
	}
	return 0;
}
