#include <iostream>
using namespace std;

bool calc(int X, int R, int C) {
    if (X == 1)
	return true;
    if (X == 2) {
	return R * C % 2 == 0;
    }
    if (X == 3) {
	return R > 1 && C > 1 && R * C % 3 == 0;
    }
    if (X == 4) {
	return R > 2 && C > 2 && R * C % 4 == 0;
    }
    return false;
}

string solve(int X, int R, int C) {
    return calc(X, R, C) ? "GABRIEL" : "RICHARD";
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
	int X, R, C;
	cin >> X >> R >> C;
	cout << "Case #" << t << ": " << solve(X, R, C) << endl;
    }
}
