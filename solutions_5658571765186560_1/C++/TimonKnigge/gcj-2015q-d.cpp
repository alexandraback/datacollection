#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

bool canfill(int X, int R, int C) {
	if (R == 1 && C == 1 && X == 1) return true;
	if (R > C) swap(R, C);
	if ((R * C) % X != 0) return false;
	if (X >= 7) return false;
	if (X < 3) return true;
	if (X >= 3 && R == 1) return false;
	if (X == 3) return true;
	if (C < X) return false;
	if (X == 4) {
		if (R == 2) return false;
		return true;
	}
	if (X == 5) {
		if (R == 2) return false;
		if (R == 3 && C == 5) return false;
		return true;
	}
	if (X == 6) {
		if (R == 2)  return false;
		if (R == 3) return false;
		return true;
	}
}

int main() {

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int X, R, C;
		cin >> X >> R >> C;

		cout << "Case #" << t << ": " << (canfill(X, R, C) ? "GABRIEL" : "RICHARD") << endl;
	}

	return 0;
}