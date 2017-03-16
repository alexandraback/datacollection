#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <cassert>

typedef long long LL;
const int maxint = 0x7f7f7f7f, mod = 1000000007;
const double eps = 1e-8, pi = acos(-1.0);

using namespace std;

const int maxn = 1001 + 10;
int n, a[maxn], b[maxn];

int read() {
	double x;
	scanf("%lf", &x);
	x *= 100000;
	return (int)floor(x + eps);
}

int cal1() {
	deque<int> dq;
	for (int i = 1; i <= n; ++i) dq.push_back(b[i]);
	int ret = 0;
	for (int i = n; i >= 1; --i) {
		if (dq.back() > a[i]) {
			++ret;
			dq.pop_back();
		} else dq.pop_front();
	}
	return n - ret;
}

bool check(int l1, int r1, int l2, int r2) {
	for (int i = l1, j = l2; i <= r1; ++i, ++j) {
		if (a[i] < b[j]) return false;
	}
	return true;
}

int cal2() {
	for (int d = 1; d <= n; ++d) {
		if (check(d, n, 1, n - d + 1)) return n - d + 1;		
	}
	return 0;
}

int main() {
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt <= tests; ++tt) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) a[i] = read();
		for (int i = 1; i <= n; ++i) b[i] = read();
		sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + n);
		printf("Case #%d: %d %d\n", tt, cal2(), cal1());
	}
	return 0;
}
