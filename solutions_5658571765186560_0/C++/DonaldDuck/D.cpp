#include <iostream>
#include <stdio.h>
#include <cassert>
#include <algorithm>
#include <string.h>

using namespace std;

const int GABRIEL = 1;
const int RICHARD = 0;

int T;

int solve(int X, int R, int C) {
	if (X == 1) return GABRIEL;
	if (X >= 7) return RICHARD; // he gives Gabriel a X-omino with a hole
	if ((R*C)%X != 0) return RICHARD;
	switch (X) {
		case (2):
			return GABRIEL;
		case (3):
			if (min(R,C) >= 2) return GABRIEL;
			return RICHARD;
		case (4):
			if (min(R,C) >= 3 && max(R,C) >= 4) return GABRIEL;
			return RICHARD;
		case (5):
			if (min(R,C) >= 3) return GABRIEL;
			return RICHARD;
		case (6):
			if (max(R, C) >= 6 && min(R, C) >= 4) return GABRIEL;
			return RICHARD;
		default:
			assert(false);
	}
}

int main() {
	int X;
	int R;
	int C;
	cin >> T;
	for (int t=1; t<=T; t++) {
		cin >> X >> R >> C;
		if (solve(X, R, C) == GABRIEL) cout << "Case #" << t << ": GABRIEL\n";
		else cout << "Case #" << t << ": RICHARD\n";
	}
	return 0;
}
