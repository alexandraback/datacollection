#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int t, cc, x, r, c;
	scanf("%d", &t);
	for (cc = 0; cc < t; cc++) {
		scanf("%d %d %d", &x, &r, &c);
		bool pos = false;
		if (x < 7 && x <= max(r, c) && (r * c) % x == 0) {
			if (x >= 2 * min(r, c) - 1 && x >= 3 && !(min(r, c) == 2 && max(r, c) == 3))
				pos = false;
			else pos = true;
		}
		printf("Case #%d: %s\n", cc + 1, pos ? "GABRIEL" : "RICHARD");
	}
	return 0;
}
