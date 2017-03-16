#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


// Richard が勝てればwin
bool solve(int x, int r, int c) {

	if (r * c % x != 0) {
		return true;
	}

	int small = min(r, c);
	int large = max(r, c);

	if (x == 1) {
		return false;
	}

	if (x == 2) {
		return false;
	}

	if (x == 3) {
		if (small == 1) {
			// Lを指定
			return true;
		} else {
			return false;
		}
	}

	if (x == 4) {
		if (small == 1 || large < 4) {
			return true;
		}
		if (small == 2) {
			return true;
		} else {
			// 3, 4
			return false;
		}
	}

	return true;
}

int main() {
	int t, x, r, c;

	cin >> t;
	vector<int> ans(t, 0);

	for (int i = 0; i < t; i++) {
		cin >> x >> r >> c;

		ans[i] = solve(x, r, c);
	}

	for (int i = 0; i < t; i++) {
		printf("Case #%d: %s\n", i + 1, ans[i] ? "RICHARD" : "GABRIEL");
	}
	return 0;
}
