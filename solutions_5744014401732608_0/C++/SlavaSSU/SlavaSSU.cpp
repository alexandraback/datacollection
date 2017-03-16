#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:640000000")

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <bitset>
#ifdef _DEBUG
#include <unordered_set>
#include <unordered_map>
#endif

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define forn1(i, n) for(int i = 1; i <= (int)(n); i++)
#define forr(i, l, r) for(int i = int(l); i <= int(r); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)((a).size())
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define y1 __y1
#define sqr(x) ((x) * (x))

typedef long long li;
typedef double ld;
typedef unsigned int uint;
typedef unsigned long long uli;
typedef pair<int, int> pt;

inline void read(int&);
inline void read(li&);
inline void read(ld&);
inline void read(char&);
inline void read(string&);
template <typename T1, typename T2> inline void read(T1&, T2&);
template <typename T1, typename T2, typename T3> inline void read(T1&, T2&, T3&);
template <typename T1, typename T2, typename T3, typename T4> inline void read(T1&, T2&, T3&, T4&);

inline void read(string &s) {
	static char buf[int(1e6) + 10];
	assert(scanf("%s", buf) == 1);
	s = string(buf);
	return;
}

const int INF = (int)(1e9);
const li INF64 = (li)(INF)* (li)(INF);
const ld eps = 1e-9;
const ld pi = ld(3.1415926535897932384626433832795);

inline bool in(int i, int j, int n, int m) {
	return i >= 1 && i <= n && j >= 1 && j <= m;
}

inline int myrand() {
	return (rand() ^ (rand() << 15));
}

inline li randL() {
	return myrand() * 1LL * myrand() + myrand();
}

const int dx[] = { 0, -1, 1, 0 };
const int dy[] = { -1, 0, 0, 1 };

const int N = 11;

int m, n;

inline void gen() {
	return;
}

inline bool read() {
	if (!(cin >> n >> m)) return false;
	return true;
}

bool g[N][N];
bool ok = false;
bool used[N];
int dp[N * N][N];

inline int calcWays() {
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	for (int cnt = 0; cnt < N * 5; cnt++) forn(v, n) {
		int cur = dp[cnt][v];
		if (cur == 0) continue;
		forn(to, n) if (g[v][to]) {
			dp[cnt + 1][to] += cur;
		}
	}

	int ans = 0;
	forn(cnt, 5 * N) ans += dp[cnt][n - 1];
	return ans;
}

void rec(int u, int v) {
	//cerr << "u v == " << u << ' ' << v << endl;
	if (ok) return;
	if (u == n - 1) {
		/*cerr << "finish state G == " << endl;
		forn(i, n) {
			forn(j, n) cerr << g[i][j] << ' '; cerr << endl;
		}*/
		int cnt = calcWays();
		if (cnt == m) {
			puts("POSSIBLE");
			forn(i, n) {
				forn(j, n) printf("%d", int(g[i][j]));
				puts("");
			}

			ok = true;
		}

		return;
	}

	if (v == n) {
		rec(u + 1, 0);
		return;
	}

	rec(u, v + 1);
	if (!g[v][u] && u != v) {
		g[u][v] = true;
		rec(u, v + 1);
		g[u][v] = false;
	}
}

inline void solve() {
	ok = false;
	memset(g, false, sizeof(g));
	//rec(0, 0);
	int all = n * (n - 1) / 2;
	vector<pt> e;
	forn(i, n) for (int j = i + 1; j < n; j++) e.push_back(mp(i, j));
	forn(mask, (1 << all)) {
		memset(g, false, sizeof g);
		forn(i, all) if (mask & (1 << i)) {
			int u = e[i].x, v = e[i].y;
			g[u][v] = true;
		}

		if (calcWays() == m) {
			puts("POSSIBLE");
			forn(i, n) {
				forn(j, n) printf("%d", int(g[i][j]));
				puts("");
			}

			ok = true;
			return;
		}
	}

	if (!ok) puts("IMPOSSIBLE");
	return;
}

int main() {
#ifdef _DEBUG
	assert(freopen("input.txt", "rt", stdin));
	assert(freopen("output.txt", "wt", stdout));
#endif

	cout << setprecision(10) << fixed;
	cerr << setprecision(10) << fixed;

	//srand(int(time(NULL)));

	int T = 1;
	assert(scanf("%d", &T) == 1);

	forn(i, T) {
		cerr << "TEST == " << i + 1 << endl;
		cout << "Case #" << i + 1 << ": ";
		assert(read());
		solve();
	}

#ifdef _DEBUG
	cerr << "TIME == " << clock() << " ms" << endl;
#endif
	return 0;
}