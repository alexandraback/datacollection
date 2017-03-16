#include <iostream>
#include <vector>
#include <cctype>
#include <cmath>
#include <cstdint>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int X, R, C;
		cin >> X >> R >> C;
		if (C < R) {
			int temp = C;
			C = R;
			R = temp;
		}
		if (X > 6) {
			cout << "Case #" << t << ": RICHARD" << endl;
		} else if (R > 1 && R+C-1 <= X) {
			cout << "Case #" << t << ": RICHARD" << endl;
		} else if (R*C % X != 0) {
			cout << "Case #" << t << ": RICHARD" << endl;
		} else if (R <= (X-1)/2) {
			cout << "Case #" << t << ": RICHARD" << endl;
		} else if (R > X) {
			cout << "Case #" << t << ": GABRIEL" << endl;
		} else if (X < 4) {
			cout << "Case #" << t << ": GABRIEL" << endl;
		} else if (X == 4 && R == 2) {
			cout << "Case #" << t << ": RICHARD" << endl;
		} else if (X == 6 && R == 3) {
			cout << "Case #" << t << ": RICHARD" << endl;
		} else {
			cout << "Case #" << t << ": GABRIEL" << endl;
		}
	}
	return 0;
}
