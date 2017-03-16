#include <iostream> 
#include <stdlib.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int x, r, c;
		cin >> x >> r >> c;
		if (r * c % x != 0) {
			cout << "Case #" << i + 1 << ": RICHARD\n";
			continue;
		}
		if (x == 1) {
			cout << "Case #" << i + 1 << ": GABRIEL\n";
			continue;
		}
		if (x == 2) {
			cout << "Case #" << i + 1 << ": GABRIEL\n";
			continue;
		}
		if (x == 3) {
			if (r * c == 3) {
				cout << "Case #" << i + 1 << ": RICHARD\n";
			} else {
				cout << "Case #" << i + 1 << ": GABRIEL\n";
			}
			continue;
		}
		if (x == 4) {
			if (r * c <= 8) {
				cout << "Case #" << i + 1 << ": RICHARD\n";
			} else {
				cout << "Case #" << i + 1 << ": GABRIEL\n";
			}
			continue;
		}
	}
	return 0;
}