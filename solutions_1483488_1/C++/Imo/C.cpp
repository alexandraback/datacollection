#include <stdio.h>
#include <string.h>

int A, B;
int case_x;

int input() {
	scanf("%d%d", &A, &B);
}

void solve() {
	char s[8];
	int c = 0;
	for (int x = A; x <= B; x++) {
		int l = 0, p = 1;
		while (p * 10 < x) l++, p *= 10;
		int y = x;
		int z[l];
		for (int i = 0; i < l; i++) {
			int head = y % 10;
			z[i] = y = y / 10 + head * p;
			if (y < A || B < y) continue;
			for (int j = 0; j < i; j++) if (z[j] == y) goto cont;
			if (x != y) c++;
cont:;
		}
	}
	printf("Case #%d: %d\n", case_x, c / 2);
}

int main() {
	int case_n;
	scanf("%d", &case_n);
	for (case_x = 1; case_x <= case_n; case_x++) {
		input();
		solve();
	}
}
