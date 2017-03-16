#include <stdio.h>

int x, r, c;

bool solve() {
	if ((r*c)%x) return false;
	if (x == 1 || x == 2) return true;
	if (x == 3) return r*c > 3;
	return r*c > 8;
}

int main() {
	freopen("qual\\D-small-attempt1.in", "r", stdin);
	freopen("qual\\D-small.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int N=1; N<=T; ++N) {
		scanf("%d%d%d", &x, &r, &c);
		printf("Case #%d: ", N);
		puts(solve() ? "GABRIEL" : "RICHARD");
	}
	return 0;
}