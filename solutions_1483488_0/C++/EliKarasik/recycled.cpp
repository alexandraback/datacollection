/*
 * Eli Karasik
 * CodeJam 2012 - Qualification - C
 *
 * C++ - compile with any free compiler
 */

#include <iostream>
#include <algorithm>

using namespace std;

int len(int num) {
	int i = 0;
	while (num != 0) {
		num /= 10;
		i++;
	}
	return i;
}



void solve() {
	int a, b;
	cin >> a >> b;
	int c, i, m, p, count = 0;
	int recycled[7]; // max length given
	for (c = a; c <= b; c++) {
		if (c < 10) {
			continue;
		}
		m = 10, p = pow((double)10,len(c)-1);
		for (i = 0; i < len(c)-1; i++) {
			/*tested = c/m + (c%m)*p;
			if ((tested > c) && (tested <= b)) {
				count++;
			}*/
			recycled[i] = c/m + (c%m)*p;
			m*=10;
			p/=10;
		}
		sort(recycled, recycled+(len(c)-1));
		if ((recycled[0] > c) && (recycled[0] <= b)) {
			count++;
		}
		for (i = 1; i < (len(c)-1); i++) {
			if ((recycled[i] > c) && (recycled[i] <= b) && (recycled[i] != recycled[i-1])) {
				count++;
			}
		}
	}
	cout << count;
}

int main() {
	int t;
	cin >> t;

	int i;
	for (i = 0; i < t; i++) {
		cout << "Case #" << (i+1) << ": ";
		solve();
		cout << endl;
	}
}