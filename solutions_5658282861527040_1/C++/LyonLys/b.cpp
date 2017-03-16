#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL a, b, c;

inline LL getLow(const LL &x, int l) { return x & (1ll << l) - 1; }
inline LL getHigh(const LL &x, int l) { return x & ~((1ll << l) - 1); }

LL dfs(const LL &x, const LL &y, const int p) {
	if (x >= a || y >= b) return 0;
	//cout << x << ' ' << y << ' ' << p << endl;
	if (p < 0) return (x & y) < c;
	if ((x & y) >= c) return 0;
	if (((x & y) | (1ll << p + 1) - 1) < c) {
		LL t1, t2;
		if (getHigh(a, p + 1) == x) t1 = getLow(a, p + 1);
		else t1 = 1ll << p + 1;
		if (getHigh(b, p + 1) == y) t2 = getLow(b, p + 1);
		else t2 = 1ll << p + 1;
		return t1 * t2;
	}
	LL sum = 0;
	for (LL i = 0; i < 2; ++i) {
		for (LL j = 0; j < 2; ++j) {
			sum += dfs(x | i << p, y | j << p, p - 1);
		}
	}
	return sum;
}

int run() {
	int _;
	cin >> _;
	for (int cas = 1; cas <= _; ++cas) {
		cin >> a >> b >> c;
		cout << "Case #" << cas << ": " << dfs(0, 0, 30) << endl;
	}
	return 0;
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	ios::sync_with_stdio(0);
	return run();
}
