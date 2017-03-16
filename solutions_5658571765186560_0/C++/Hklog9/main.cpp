#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
	freopen("out", "w", stdout);
	int Case, ans = 0, loop = 0;
	int X, R, C;
	scanf("%d", &Case);
	loop = Case;

	while (Case--) {
		ans = 1;
		cin >> X >> R >> C;
		if (X >= 7) {
			ans = 0;
		} else if (X > R && X > C) {
			ans = 0;
		} else if ((R * C) % X != 0) {
			ans = 0;
		} else if ((X + 1) / 2 > min(R, C)) {
			ans = 0;
		} else if (X == 1 || X == 2 || X == 3) {
			ans = 1;
		} else if (X == 4) {
			ans = min(R, C) > 2;
		} else if (X == 5) {
			ans = !(min(R, C) == 3 && max(R, C) == 5);
		} else if (X == 6) {
			ans = min(R, C) > 3;
		}
		printf("Case #%d: %s\n", loop - Case, (ans) ? "GABRIEL" : "RICHARD");
	}
	return 0;
}
