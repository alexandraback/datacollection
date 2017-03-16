#include <iostream>

using namespace std;

int t, x, r, c;

int main() {
	cin >> t;
	for (int i=1;i<=t;i++) {
		cout << "CASE #" << i << ": ";
		cin >> x >> r >> c;
		if (x >= 7 || ((r*c)%x)) {
			cout << "RICHARD\n";
			continue;
		}
		if (x == 3)  {
			if (min(r,c) == 1) {
				cout << "RICHARD\n";
				continue;
			}
		} else if (x == 4) {
			if (min(r,c) < 3) {
				cout << "RICHARD\n";
				continue;
			}

		} else if (x == 5) {
			if (min(r,c) < 4) {
				cout << "RICHARD\n";
				continue;
			}
		} else if (x == 6) {
			if (min(r,c) < 4) {
				cout << "RICHARD\n";
				continue;
			}
		}
		cout << "GABRIEL\n";
	}
}
