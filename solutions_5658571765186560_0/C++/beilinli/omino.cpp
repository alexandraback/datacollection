#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	freopen(	"D-small-attempt0.in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int X, R, C;
		cin >> X >> R >> C;

		if (X == 1) printf("Case #%d: GABRIEL\n", t); // can fill in
		else if (X == 2) {
			if ((R * C) % 2 == 0) printf("Case #%d: GABRIEL\n", t);
			else printf("Case #%d: RICHARD\n", t);
		} else if (X == 3) {
			if (R == 3 && C > 1) printf("Case #%d: GABRIEL\n", t);
			else if (R > 1 && C == 3) printf("Case #%d: GABRIEL\n", t);
			else printf("Case #%d: RICHARD\n", t);
		} else {
			if (R * C > 9) printf("Case #%d: GABRIEL\n", t);
			else printf("Case #%d: RICHARD\n", t);
		}
	}
	return 0;
}
