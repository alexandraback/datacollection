#include <stdio.h>

long long Reverse(long long x) {
	long long y = 0;
	while (x) {
		y = y * 10 + x % 10;
		x /= 10;
	}
	return y;
}

bool IsGood(long long n) {
	if (n < 10 || n % 10 != 1) {
		return false;
	}
	int cnt = 1;
	int cnt0 = 1;
	bool ok = true;
	long long x = n / 10;
	while (x) {
		if (ok && x % 10 == 0) {
			cnt0++;
		} else {
			ok = false;
		}
		x /= 10;
		cnt++;
	}
	return cnt0 >= cnt / 2;
}

void Solve() {
	long long n;
	scanf("%lld", &n);
	int ans = 0;
	while (n > 0) {
		if (IsGood(n)) {
			long long y = Reverse(n);
			if (y < n) {
				n = y;
			} else {
				n--;
			}
		} else {
			n--;
		}
		ans++;
	}
	printf("%d\n", ans);
}

int main() {
	int nt;
	scanf("%d", &nt);
	for (int i=1; i<=nt; i++) {
		printf("Case #%d: ", i);
		Solve();
	}
	return 0;
}
