#include <stdio.h>
#include <algorithm>

int R, C, M, l;
int od;
void ol(int d) {
	int i = 0;
	if (l == 0) {
		putchar('c');
		i++;
	}
	for (; i < d; i++) putchar('.');
	for (int i = d; i < C; i++) putchar('*');
	putchar('\n');
	l++;
	if (d > C) puts("Error");
	od += d;
}

void solve() {
	l = 0;
	od = 0;
	scanf("%d%d%d", &R, &C, &M);
	int E = R * C - M;
	if (M == R * C - 1 || R == 1 || C == 1 || (E >= C * 2 && E % C != 1)) {
		for (int i = 0; i < R; i++) {
			int s = std::min(E, C);
			ol(s);
			E -= s;
		}
	}
	else if (E >= C * 2) {
		if (E / C > 2 && C > 2) {
			for (int i = 0; i < E / C - 1; i++) ol(C);
			ol(C - 1);
			ol(2);
			for (int i = E / C + 1; i < R; i++) ol(0);
		}
		else if (C > 3) {
			for (int i = 0; i < 2; i++) ol(C - 1);
			ol(3);
			for (int i = 3; i < R; i++) ol(0);
		}
	}
	else if (E >= 4) {
		if (E % 2 == 0) {
			int l = E / 2;
			for (int i = 0; i < 2; i++) ol(E / 2);
			for (int i = 2; i < R; i++) ol(0);
		}
		else if (E >= 9 && R > 2) {
			ol(E / 2 - 1);
			ol(E / 2 - 1);
			ol(3);
			for (int i = 3; i < R; i++) ol(0);
		}
	}
	if (l == 0) {
		puts("Impossible");
	}
	else {
		if (od + M != R * C) puts("Error");
		if (l != R) puts("Error");
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int c = 1; c <= T; c++) {
		printf("Case #%d:\n", c);
		solve();
	}
}