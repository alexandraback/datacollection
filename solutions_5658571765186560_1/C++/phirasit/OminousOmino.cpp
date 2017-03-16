#include <iostream>

using namespace std;

int evaluate(int x, int r, int c) { // 1 Richard wins, 0 otherwise
	if(r < c) {
		return evaluate(x, c, r);
	}
	if((r * c) % x) {
		return 1;
	}
	if(x > r || x > r * c) {
		return 1;
	}
	int s = x / 2 + 1;
	int s2 = x - s + 1;
	if(s > c && s2 > c) {
		return 1;
	}
	if(r * c == x) {
		return 0;
	}
	if(x <= c) {
		return 0;
	}
	if(c == 1) {
		return 0;
	}else if(c == 2) {
		return x >= 4;
	}else { // c >= 3
		if(x >= 7) {
			return 1;
		}
		// x == 4, 5, 6
		if(x == 4) {
			return 0;
		}else if(x == 5) {
			return 0;
		}else if(x == 6) {
			if(c == 3) {
				return 1;
			}else {
				return 0;
			}
		}
	}
}
int main() {
	
	freopen("Dlarge.in", "r", stdin);
	freopen("Dlarge.out", "w", stdout);
	
	int t;
	cin >> t;
	for(int C = 1;C <= t;C++) {
		int x, r, c;
		cin >> x >> r >> c;
		cout << "Case #" << C << ": " << (evaluate(x, r, c) ? "RICHARD" : "GABRIEL") << endl;
	}
}
