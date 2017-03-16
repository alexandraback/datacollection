#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

int T;
long long p, q;
void solve() {
	scanf("%lld/%lld", &p, &q);
	long long gcd = __gcd(p, q);
	p /= gcd;
	q /= gcd;
	int answer = 0;
	long long t = q;
	while (!(q & 1)) {
		q >>= 1;
	}
	if (q != 1) {
		printf("impossible\n");
		return;
	}
	while (t >= 1) {
		if (p >= t) break;
		t >>= 1;
		answer ++;
	}
	printf("%d\n", answer);
}
int main() {
	// freopen("in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}