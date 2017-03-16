/*
 * By: Ehsan
 *
 * Contact info: ehsan7069[at]gmail[dot]com
 */

#include <iostream>

using namespace std;

int x, r, c;

bool ans; // Richard wins ...

void input () {
	cin >> x >> r >> c;
	return;
}

bool solve() {
	if ((r * c) % x)
		return true;
	// x >= 1
	if (x == 1)
		return false;
	// x >= 2
	if (x == 2)
		return false;
	// x >= 3
	if ((r == 1) || (c == 1))
		return true;
	if (x == 3)
		return false;
	// x >= 4
	if ((r < x) && (c < x))
		return true;
	if (x == 4) {
		if ((r == 2) || (c == 2))
			return true;
		return false;
	}
	// x >= 5

	// x >= 7
	return true;
}

void output (int t) {
	cout << "Case #" << t + 1 << ": ";
	if (ans)
		cout << "RICHARD" << endl;
	else
		cout << "GABRIEL" << endl;
	return;
}

int main () {
	int T;
	cin >> T;
	for (int t = 0 ; t < T ; t++) {
		input();
		ans = solve();
		output(t);
	}
	return 0;
}


