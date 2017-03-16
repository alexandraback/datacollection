#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int aa(int x) {
	return x < 0 ? -x : x;
}

int n, m, K, f[110][11][11][110];

void solve() {
	scanf("%d %d %d", &n, &m, &K);
	if (K < 5) {
		printf("%d\n", K);
		return;
	}
	if (m > n) swap(n, m);
	memset(f, 0x7f, sizeof(f));
	forn(jr, m) forn(jl, jr + 1)
		f[0][jl][jr][jr - jl + 1] = jr - jl + 1;

	int ans = n * m;
	for (int i = 1; i < n; i++) {
		forn(jr, m) forn(jl, jr + 1) forn(k, i * m + 1)
			if (f[i-1][jl][jr][k] < 10000) {
				forn(b, m) forn(a, b + 1) {
					int nk = k + b - a + 1;
					int addv = 1 + int(a != b);
					if (aa(jr - b) > 1) addv += aa(jr - b) - 1;
					if (aa(jl - a) > 1) addv += aa(jl - a) - 1;
					f[i][a][b][nk] = min(f[i][a][b][nk], f[i-1][jl][jr][k] + addv);
					if (nk >= K) ans = min(ans, f[i-1][jl][jr][k] + addv + b - a - int(b != a));
				}
			}
	}

	printf("%d\n", ans);
}

int main() {
	// 	solve();
	int tc;
	scanf("%d", &tc);
	for (int q = 1; q <= tc; q++) {
		printf("Case #%d: ", q);
		solve();
		fprintf(stderr, "Case %d done.\n", q);
	}
	return 0;
}
