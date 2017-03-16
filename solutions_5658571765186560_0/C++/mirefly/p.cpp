#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int x, int r, int c) {
	int area = r * c;
	if (x == 1 || x > 7)
		return 1;
	if (area % x != 0)
		return 0;
	if (x > r && x > c)
		return 0;
	if (x % 2 == 1) {
		if (x / 2 + 1 > min(c, r))
			return 0;
	} else {
		if (x / 2 > min(c, r))
			return 0;
	}
	if (x == 4 && min(c, r) == 2)
		return 0;
	return 1;
}

int main() {
	int nt;
	cin >> nt;
	int x, r, c;
	for (int i = 0; i < nt; i++) {
		cin >> x;
		cin >> r;
		cin >> c;
		cout << "Case #" << i + 1 << ": ";
		if (solve(x, r, c)) {
			cout << "GABRIEL" << endl;
		} else {
			cout << "RICHARD" << endl;
		}
	}
	return 0;
}
