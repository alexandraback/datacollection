#include <iostream>
#include <cstdio>

using namespace std;

bool win(int x, int r, int c) {
	if (x > 6 || r * c % x != 0) 
		return false;
	if (r > c) 
		swap(r, c);
	if (c < x)
		return false;
	if (x == 1 || x == 2) { 
		return true;
	}
	if (x == 3) {
		if (r == 1)
			return false;
	}
	if (x == 4) {
		if (r == 1)
			return false;
		if (r == 2 && c <= 4)
			return false;
	}
	if (x == 5) {
		if (r < 3)
			return false;
	}
	if (x == 6) {
		if (r < 3) 
			return false;
		//011
		//010
		//111
		if (r == 3)
			return false;
	}
	return true;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int test_case, x, r, c;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; ++tc) {
		cin >> x >> r >> c;
		cout << "Case #" << tc << ": " << (win(x, r, c) ? "GABRIEL" : "RICHARD") << endl;
	}
	return 0;
}
