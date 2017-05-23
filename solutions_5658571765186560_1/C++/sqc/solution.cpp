#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
	//freopen("D-small-attempt0.in", "r", stdin);
	//freopen("D-small-attempt0.out", "w", stdout);
	//freopen("D-large.in", "r", stdin);
	//freopen("D-large.out", "w", stdout);
	int t;
	int x, r, c;
	int maxEdge, minEdge;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d %d %d", &x, &r, &c);
		maxEdge = max(r, c);
		minEdge = min(r, c);
		if (r * c % x != 0) {
			printf("Case #%d: RICHARD\n", i);
			continue;
		}

		if (x == 1) {
			printf("Case #%d: GABRIEL\n", i);
		} else if (x == 2) {
			printf("Case #%d: GABRIEL\n", i);			
		} else if (x>=3 && x <= 5) {
			if (maxEdge >= x && minEdge >= x - 1) {
				printf("Case #%d: GABRIEL\n", i);
			} else {
				printf("Case #%d: RICHARD\n", i);
			}
		} else if (x == 6) {
			if (maxEdge >= 6 && minEdge >= 4) {
				printf("Case #%d: GABRIEL\n", i);
			} else {
				printf("Case #%d: RICHARD\n", i);
			}
		} else {
			printf("Case #%d: RICHARD\n", i);
		}
	}
	return 0;
}