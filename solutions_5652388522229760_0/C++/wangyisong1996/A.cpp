#include <stdio.h>

void solve(int x) {
	if (x == 0) {
		puts("INSOMNIA");
		return;
	}
	int visit = 1023;
	for (int t = x; ; t += x) {
		int tmp = t;
		while (tmp) {
			visit &= ~(1 << (tmp % 10));
			tmp /= 10;
		}
		if (!visit) {
			printf("%d\n", t);
			break;
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		int x;
		scanf("%d", &x);
		printf("Case #%d: ", i);
		solve(x);
	}
}