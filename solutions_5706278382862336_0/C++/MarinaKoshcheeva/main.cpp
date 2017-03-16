#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 60;

long long p, q;
long long pow2[MAXN];

long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

long long get_nearest_pow2(long long x) {
	for (int i = MAXN - 1; i >= 0; --i)
		if (x > pow2[i])
			return i + 1;
	return 0;
}

void solve(int test_id) {
	cout << "Case #" << test_id << ": ";
	scanf("%lld/%lld\n", &p, &q);

	long long d = gcd(p, q);
	p /= d;
	q /= d;

	int r = get_nearest_pow2(q);
	if (q != pow2[r] || p == 0 || p > q) {
		cout << "impossible" << endl;
		return;
	}
	if (r == 0) {
		if (p == 1)
			cout << 0 << endl;
		else
			cout << "impossible" << endl;
		return;
	}

	int res = -1;
	for (int k = 1; k < MAXN; ++k) {
		if (p >= pow2[r - k]) {
			p -= pow2[r - k];
			res = k;
			break;
		}
	}

	int t = get_nearest_pow2(p);
	if (t + r > 40) {
		cout << "impossible" << endl;
	}
	else {
		cout << res << endl;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	pow2[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		pow2[i] = pow2[i - 1] << 1;

	int t;
	scanf("%d\n", &t);
	for (int test_id = 1; test_id <= t; ++test_id)
		solve(test_id);
	return 0;
}
