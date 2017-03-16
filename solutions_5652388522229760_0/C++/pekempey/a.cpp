#include <bits/stdc++.h>
using namespace std;

long long solve(long long n) {
	if (n == 0) return -1;

	int st = 0;
	for (int i = 1;; i++) {
		int t = n * i;
		while (t > 0) {
			st |= 1 << (t % 10);
			t /= 10;
		}
		if (st == (1 << 10) - 1) return n * i;
	}
	return -1;
}

int main() {
	int T;
	cin >> T;
	for (int ii = 0; ii < T; ii++) {
		int n;
		cin >> n;
		long long ans = solve(n);

		if (ans != -1) {
			printf("Case #%d: %lld\n", ii + 1, ans);
		} else {
			printf("Case #%d: INSOMNIA\n", ii + 1);
		}
	}
}