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

ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

int solve() {
	ll p, q;
	scanf("%lld/%lld", &p, &q);
	ll d = gcd(p, q);
	p /= d;
	q /= d;

	if ((q & (q - 1)) != 0) {
		return -1;
	}

	int ans = 0;
	for (; q > 1; q>>=1) ans++;
	while (p > 1) {
		p >>= 1;
		ans--;
	}

	return ans;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int q = 1; q <= tc; q++) {
		printf("Case #%d: ", q);
		int z = solve();
		if (z == -1) printf("impossible\n");
		else printf("%d\n", z);
		fprintf(stderr, "Case %d done.\n", q);
	}
	return 0;
}
