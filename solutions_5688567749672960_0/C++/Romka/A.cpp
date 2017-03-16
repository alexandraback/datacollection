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


int d[1000010];

ll rev(ll N) {
	ll res = 0;
	while (N > 0) {
		res = res * 10 + N % 10;
		N /= 10;
	}
	return res;
}

ll get(ll N) {
	if (N < 20) return N;
	ll c = 1, res = 1;
	int cd = 1;
	int nd = 0;
	ll ld = 0;
	for (ll q=N; q>0; q/=10) nd++, ld=q;
	if (nd == 2) {
		return (N/10 + 10) + 1 + N % 10 - 1;
	}
	ll next = 19;
	cd++;
	while (cd < nd) {
		res += next - c;
		c = next;
		next = next * 10 + 9;
		c = rev(c);
		res++;
		c += 9;
		res += 9;
		cd++;
	}
	// fprintf(stderr, "after: %lld\n", c);
	if (ld > 1) {
		c += ld;
		res += ld;
		c = rev(c);
		res++;
	}
	return res + N - c;
}

void solve() {
	ll N;
	cin >> N;
	if (N == 1000000) cout << d[999999] + 1 << endl;
	else cout << d[N] << endl;
	return;
	ll res = get(N);
	if (N % 10 != 0) res = min(res, get(rev(N)) + 1);
	cout << res << endl;
}

void fillAll() {
	memset(d, 0xff, sizeof(d));
	d[1] = 1;
	vector<int> q;
	q.pb(1);
	size_t qb = 0;
	while (qb < q.size()) {
		int x = q[qb++];
		int z = rev(x);
		if (z < 1e6 && d[z] == -1) {
			d[z] = d[x] + 1;
			q.pb(z);
		}
		z = x + 1;
		if (z < 1e6 && d[z] == -1) {
			d[z] = d[x] + 1;
			q.pb(z);
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	fillAll();
	for (int q = 1; q <= tc; q++) {
		printf("Case #%d: ", q);
		solve();
	}
	return 0;
}
