#include <stdio.h>

void solve(int count) {
	long long int r, t, result, needed;
	scanf("%lld %lld", &r, &t);
	result = 0LL;
	while (true) {
		needed = 2 * r + 1;
		if (needed > t)
			break;
		t -= needed;
		result++;
		r += 2;
	}
	printf("Case #%d: %lld\n", count, result);
	return;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		solve(i);
	}
	return 0;
}

