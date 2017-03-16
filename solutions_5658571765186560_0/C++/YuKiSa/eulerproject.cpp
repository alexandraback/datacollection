#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int a[1005];


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);

	int t; scanf("%d", &t);
	for (int k = 0; k < t; k++) {
		int x, r, c;
		scanf("%d %d %d", &x, &r, &c);
		printf("Case #%d: ", k + 1);
		if (x == 1) printf("GABRIEL");
		else if (x == 2) {
			if (r*c % 2 == 0) printf("GABRIEL");
			else printf("RICHARD");
		}
		else if (x == 3) {
			if (r*c % 3 != 0 || r == 1 || c == 1) printf("RICHARD");
			else printf("GABRIEL");
		}
		else {
			if (r*c % 4 != 0 || r == 1 || c == 1 || r == 2 || c == 2) printf("RICHARD");
			else printf("GABRIEL");
		}
		printf("\n");
	}

	return 0;
}