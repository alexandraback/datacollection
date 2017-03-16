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

void up(ll& x, ll y) {
	if (x < y) x = y;
}

int E, R, n, a[10010];
ll f[110][15010];

void solve() {
	scanf("%d %d %d", &E, &R, &n);
	forn(i, n) scanf("%d", &a[i]);
	f[0][E] = 0;
	forn(i, n) {
		forn(k, E+1) f[i+1][k] = 0;
		forn(j, E+1) {
			// printf("f[%d][%d] = %lld\n", i, j, f[i][j]);
			forn(k, j+1) {
				up(f[i+1][min(j-k+R, E)], f[i][j] + a[i] * k);
			}
			up(f[i+1][min(j + R, E)], f[i][j]);
		}
	}
	ll ans = 0;
	forn(j, E+1)
		up(ans, f[n][j]);
	cout << ans << endl;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int q = 1; q <= tc; q++) {
		printf("Case #%d: ", q);
		solve();
		fprintf(stderr, "Case %d done.\n", q);
	}
	return 0;
}