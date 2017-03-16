#include <stdlib.h>
#include <stdio.h>

int main() {
	//freopen("D-small-attempt0.in", "r", stdin);
	//freopen("D-small-attempt0.out", "w", stdout);
	//freopen("D-large.in", "r", stdin);
	//freopen("D-large.out", "w", stdout);
	int t;
	int x, r, c;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d %d %d", &x, &r, &c);
		if (x == 1) {
			printf("Case #%d: GABRIEL\n", i);
		} else if (x == 2) {
			if (r * c % 2 == 0) {
				printf("Case #%d: GABRIEL\n", i);
			} else {
				printf("Case #%d: RICHARD\n", i);
			}
		} else if (x == 3) {
			if ((r >=2 && c>= 3 || r >= 3 && c >= 2) && (r * c % 3 == 0)) {
				printf("Case #%d: GABRIEL\n", i);
			} else {
				printf("Case #%d: RICHARD\n", i);
			}
		} else {
			if (r == 3 && c == 4 || r == 4 && c == 3 || r == 4 && c == 4) {
				printf("Case #%d: GABRIEL\n", i);
			} else {
				printf("Case #%d: RICHARD\n", i);
			}
		}
	}
	return 0;
}