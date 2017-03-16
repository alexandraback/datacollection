#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	while (a != 0 && b != 0) {
		if (a > b) {
			a %= b;
		} else {
			b %= a;
		}
	}
	return a + b;
}

bool ispow2(ll a) {
	while (a % 2 == 0) {
		a /= 2;
	}
	return a == 1LL;
}

void solve() {
	long long p, q;
	scanf("%lld/%lld", &p, &q);
	long long g = gcd(p, q);
	p /= g, q /= g;
	if (ispow2(q)) {
		int ans = 0;
		while (q != 1LL) {
			ans++;
			if (p * 2 >= q) {
				break;
			}
			q /= 2;
		}
		printf("%d", ans);
	} else {
		printf("impossible");
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d: ", i + 1);
		solve();
		printf("\n");
	}
	return 0;
}