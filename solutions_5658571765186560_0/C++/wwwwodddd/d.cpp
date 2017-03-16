#include <stdio.h>
#include <iostream>
using namespace std;
int t;
int main() {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		int r, c, x;
		scanf("%d%d%d", &x, &r, &c);
		int z = 0;
		if (r < c) {
			swap(r, c);
		}
		if (x == 4) {
			z = (r == 4 && c >= 3);
		} else if (x == 3) {
			z = (r * c % x == 0 && c > 1);
		} else {
			z = (r * c % x == 0);
		}
		printf("Case #%d: %s\n", tt, z ? "GABRIEL" : "RICHARD");
	}
	return 0;
}