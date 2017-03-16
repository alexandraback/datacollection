#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

int itc;

template<typename T>
T powi(T a, unsigned int b) {
	T c = 1;
	while (b != 0) {
		if (b&1) c = c*a;
		a = a*a;
		b >>= 1;
	}
	return c;
}

void solve() {
	int k, c, s;
	cin >> k >> c >> s;
	if (k > c*s) {
		puts(" IMPOSSIBLE");
		return;
	}
	if (k == 1) {
		puts(" 1");
		return;
	}
	for (int a = 0; a < k; a += c) {
		int n = min(c, k-a);
		ll b = (powi((ll)k, n)-1)/(k-1);
		printf(" %lld", (a+n-1)*b-(b-n)/(k-1)+1);
	}
	puts("");
}

int main() {
	cin.sync_with_stdio(false);
	int ntc;
	cin >> ntc;
	for (itc = 1; itc <= ntc; itc++) {
		printf("Case #%d:", itc);
		solve();
	}
}
