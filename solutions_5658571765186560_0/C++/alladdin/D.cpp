#include <iostream>
#include <set>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <ctime>
#include <cassert>
#include <bitset>

using namespace std;

int t, n, l, ans, tans, x, y, z;
string s, s1, ps;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> t;
	for (int j = 0; j < t; j++) {
		cin >> z >> x >> y;
		if (z == 1) {
			cout << "Case #" << j + 1 << ": GABRIEL" << endl;
		}
		else if (z == 2) {
			if (x == 1 && y == 1 || x == 1 && y == 3 || x == 3 && y == 1 || x == 3 && y == 3) {
				cout << "Case #" << j + 1 << ": RICHARD" << endl;
			}
			else {
				cout << "Case #" << j + 1 << ": GABRIEL" << endl;
			}
		}
		else if (z == 3) {
			if (x == 2 && y == 3 || x == 3 && y == 2 || x == 3 && y == 3 || x == 3 && y == 4 || x == 4 && y == 3) {
				cout << "Case #" << j + 1 << ": GABRIEL" << endl;
			}
			else {
				cout << "Case #" << j + 1 << ": RICHARD" << endl;
			}
		}
		else {
			if (x == 3 && y == 4 || x == 4 && y == 3 || x == 4 && y == 4) {
				cout << "Case #" << j + 1 << ": GABRIEL" << endl;
			}
			else {
				cout << "Case #" << j + 1 << ": RICHARD" << endl;
			}
		}
	}

	return 0;
}