#include <stdio.h>

int Reverse(int x) {
	int y = 0;
	while (x) {
		y = y * 10 + x % 10;
		x /= 10;
	}
	return y;
}

int a[1000001];

void Solve0() {
	int n = 1000000;
	a[0] = 0;
	for (int i=1; i<=n; i++) {
		a[i] = -1;
	}
	for (int i=1; i<=n; i++) {
		if (a[i] == -1 || a[i] > a[i-1] + 1) {
			a[i] = a[i-1] + 1;
		}
		if (i >= 10) {
			int y = Reverse(i);
			if (y > i) {
				if (a[y] == -1 || a[y] > a[i] + 1) {
					a[y] = a[i] + 1;
				}
			}
		}
	}
	// for (int i=1; i<=n; i++) {
	// 	printf("%d %d\n", i, a[i]);
	// }
}

void Solve() {
	int n;
	scanf("%d", &n);
	printf("%d\n", a[n]);
}

int main() {
	int nt;
	Solve0();
	scanf("%d", &nt);
	for (int i=1; i<=nt; i++) {
		printf("Case #%d: ", i);
		Solve();
	}
	return 0;
}
