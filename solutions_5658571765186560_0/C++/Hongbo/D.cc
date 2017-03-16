#include <iostream>
#include <string>
using namespace std;

string solve() {
	int x, r, c;
	cin >> x >> r >> c;
	if (r * c % x) return "RICHARD";
	if (x == 3 && r * c < 6) return "RICHARD";
	if (x == 4 && r * c < 12) return "RICHARD";
	return "GABRIEL";
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i ++)
		cout << "Case #" << i << ": " << solve() << endl;
	return 0;
}
