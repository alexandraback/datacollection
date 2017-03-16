#include <bits/stdc++.h>
using namespace std;
int X, R, C;
bool can() {
	if ((R * C) % X) return false;
	if (X > 6) return false;
	if (X <= 2) return true;
	if (R > C) swap(R, C);
	if (R == 1) return false;
	// 6 >= X >= 3, R >= 2, R <= C now
	if (X == 3) return true;
	if (X == 4) {
		return R > 2;
	}
	if (R == 2) return false;
	// R >= 3 now
	if (X == 5) {
		if (R == 3 && C == 5) return false;
		return true;
	}
	// X == 6
	return R > 3;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		scanf("%d%d%d", &X, &R, &C);
		printf("Case #%d: %s\n", cn, can() ? "GABRIEL" : "RICHARD");
	}
}

