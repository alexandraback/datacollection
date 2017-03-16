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

int n, m, K, f[2][35][35][1010];

void solve() {
	scanf("%d %d %d", &n, &m, &K);
	fprintf(stderr, "Now processing: %d %d %d\n", n, m, K);
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
		int fl = i & 1;
		forn(jr, m) forn(jl, jr + 1) forn(k, (i + 1) * m + 1) f[fl][jl][jr][k] = 0x7f7f7f7f;
		int lk = min(i * m + 1, K + 1);
		forn(jr, m) forn(jl, jr + 1) {
			// int d = (jr - jl + 1) / 2;
			// if (aa(jl - (m / 2 - d)) > 5) continue;
			// if (aa(jr - (m / 2 + d)) > 5) break;
			forn(k, lk)
			if (f[fl ^ 1][jl][jr][k] < 10000) {
				if ((n - i) * m + k < K) continue;
				for (int b = jl; b < m; b++) {
					int la = jl, ra = min(b, jr);
					if (b > jr) la = 0;
					for (int a = la; a <= ra; a++) {
						int nk = k + b - a + 1;
						int addv = 1 + int(a != b);
						if (aa(jr - b) > 1) addv += aa(jr - b) - 1;
						if (aa(jl - a) > 1) addv += aa(jl - a) - 1;
						f[fl][a][b][nk] = min(f[fl][a][b][nk], f[fl ^ 1][jl][jr][k] + addv);
						if (nk >= K) ans = min(ans, f[fl ^ 1][jl][jr][k] + addv + b - a - int(b != a));
					}
				}
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
