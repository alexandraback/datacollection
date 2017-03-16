//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <ios>
#include <iomanip>
#include <ctime>
#include <numeric>
#include <functional>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>
#include <cstdarg>
using namespace std;

inline int read() {
	static int r;
	static char c;
	r = 0, c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') r = r * 10 + (c - '0'), c = getchar();
	return r;
}

typedef long long ll;
#define pair(x, y) make_pair(x, y)
#define runtime() ((double)clock() / CLOCKS_PER_SEC)

#define N 10000
int T, n, R, e, a[N + 1], tc = 0;

ll deal(int l,int r, int s, int t) {
	int m = 0, p = -1;
	for (int i = l; i <= r; ++i)
		if (a[i] >= m) m = a[i], p = i;
	
	ll ls = p - l, rs = r - p;
	ll cur = min((ll)e, s + (ll)R * ls);
	ll use = min(cur, cur + (ll)R + (ll)R * rs - t);
	
	ll ret = (ll)a[p] * use;
	if (l < p) ret += deal(l, p - 1, s, max(use, t + use - R - rs * R));
	if (p < r) ret += deal(p + 1, r, min((ll)e, cur - use + R), t);
	return ret;
}

int main() {
#ifdef KANARI
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &e, &R, &n);
		for (int i = 1; i <= n; ++i) scanf("%d", a + i);
		
		ll ans = deal(1, n, e, 0);
		
		cout << "Case #" << ++tc << ": " << ans << endl;
	}
	
	return 0;
}

