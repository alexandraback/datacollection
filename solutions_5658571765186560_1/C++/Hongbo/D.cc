#include <iostream>
#include <string>
using namespace std;

string solve() {
	int x, r, c;
	cin >> x >> r >> c;
	if (x > 6) return "RICHARD";
	if (r * c % x) return "RICHARD";
	if (x == 3 && r * c < 6) return "RICHARD";
	if (x == 4 && r * c < 12) return "RICHARD";
	if (x == 5 && r * c < 15) return "RICHARD";
	if (x == 6) {
		int n, m;
		if (r % 3 == 0) n = r;
		if (c % 3 == 0 && c > r) n = c;
		if (n == r) m = c;
		else m = r;
		if (n == 3) return "RICHARD";
		if (m < 4) return "RICHARD";
	}
	return "GABRIEL";
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i ++)
		cout << "Case #" << i << ": " << solve() << endl;
	return 0;
}
