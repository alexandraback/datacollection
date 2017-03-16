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

void solve_naive() {
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

pii b[10010];
ll spend[10010], mn[10010];
int p[10010];

void solve() {
	scanf("%d %d %d", &E, &R, &n);
	forn(i, n) scanf("%d", &a[i]);
	forn(i, n) b[i] = pii(a[i], i), p[i] = n, mn[i] = 0;
	sort(b, b+n);
	reverse(b, b+n);
	set<int> ss;
	forn(ii, n) {
		int i = b[ii].second;
		set<int>::iterator it = ss.lower_bound(i);
		if (it == ss.end()) spend[i] = E;
		else {
			int j = *it;
			if (p[j] < i) {
				ll rest = E - ll(R) * (j-i);
				if (rest < 0) rest = 0;
				spend[i] = E - rest;
				mn[i] = max(E - ll(R) * (ll(j) - i), 0LL);
			}
			else {
				spend[i] = max(min(ll(R) *(ll(j) - i), ll(E)), 0LL);
				mn[i] = max(E - ll(R) *(ll(j) - i), 0LL);
			}
			p[j] = i;
		}
		if (spend[i]) ss.insert(i);
	}
	ll cur = E;
	ll ans = 0;
	// forn(i, n) printf(" %lld", spend[i]);
	// printf("\n");
	forn(i, n) {
		if (cur > mn[i])
			spend[i] = cur - mn[i];
		else
			spend[i] = 0;
		set<int>::iterator it = ss.lower_bound(i);
		if (it != ss.end()) {
			int j = *it;
			if (j != i) {
				ll rest = E - ll(R) * (j-i);
				if (rest < 0) rest = 0;
				spend[i] = cur - rest;
			}
		}
		// printf("cur = %lld, spend %lld\n", cur, spend[i]);
		ans += spend[i] * a[i];
		cur = min(cur - spend[i] + R, ll(E));
	}
	// printf("\n");
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