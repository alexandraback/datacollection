#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

#define sqr(x) ((x)*(x))

long long func(long long n, long long r, long long t) {
	if (n == 0) return t;
	long long sub = t / n - n * 2 + 1 - r * 2;
	if (t % n == 0)
		return sub;
	if (sub < 0)
		return -1;
	if (sub >= 0)
		return 1;
}

long long calc(long long r, long long t) {
	long long right = (long long)sqrt(t) + 1;
	long long left = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (func(mid, r, t) >= 0)
			left = mid + 1;
		else right = mid - 1;
	}
	return right;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w+", stdout);
	int T;
	long long r, t;
	scanf("%d", &T);
	for (int tcase = 1; tcase <= T; ++ tcase) {
		scanf("%lld%lld", &r, &t);
		printf("Case #%d: %lld\n", tcase, calc(r, t));
	}
	return 0;
}
