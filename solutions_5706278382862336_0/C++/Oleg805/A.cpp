#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;

#pragma comment(linker,"/STACK:100000000")

long long gcd(long long x, long long y) {
	return y == 0 ? x : gcd(y, x % y);
}

void solve(int T) {
	long long p, q;
	scanf("%lld/%lld", &p, &q);
	printf("Case #%d: ", T);
	int ans = 0;
	while (p < q) {
		if (q % 2 == 1) {
			printf("impossible\n");
			return;
		}
		q /= 2;
		ans++;
	}
	long long g = gcd(p, q);
	q /= g;
	while (q % 2 == 0) {
		q /= 2;
	}
	if (q > 1) {
		printf("impossible\n");
	} else {
		printf("%d\n", ans);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		solve(i + 1);
	}
	return 0;
}