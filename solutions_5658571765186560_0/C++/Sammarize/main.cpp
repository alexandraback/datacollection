#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int next() {int x; cin >> x; return x;}

int main() {

	int tests = next();
	for (int test = 1; test <= tests; test++) {
		int x = next();
		int r = next();
		int c = next();
		bool win;
		if (r * c % x != 0) win = true;
		else if (x == 1) win = false;
		else if (x == 2) win = false;
		else if (x == 4) {
			if (r*c >= 12) win = false;
			else win = true;
		}
		else if (r == 1 || c == 1) win = true;
		else win = false;

		cout << "Case #" << test << ": " << (win ? "RICHARD" : "GABRIEL") << "\n";
	}
}