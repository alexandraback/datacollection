#include <iostream>

using namespace std;

int main() {
	freopen("a.txt", "r", stdin);
	freopen("b.txt", "w", stdout);
	int T = 0;
	cin >> T;
	int t = 0;
	while (t < T) {
		if (t != 0) cout << endl;
		int x, r, c;
		cin >> x >> r >> c;
		int ans = 0; // 0:RICHARD 1:GABRIEL
		switch (x) {
		case 1:
			ans = 1;
			break;
		case 2:
			if (r % 2 != 0 && c % 2 != 0) {
				ans = 0;
			}
			else {
				ans = 1;
			}
			break;
		case 3:
			if (r != 3 && c != 3) {
				ans = 0;
			}
			else{
				if (r == 1 || c == 1) {
					ans = 0;
				}
				else {
					ans = 1;
				}
			}
			break;
		case 4:
			if (r <= 2 || c <= 2) {
				ans = 0;
			}
			else {
				if (r == 3 && c == 3) {
					ans = 0;
				}
				else {
					ans = 1;
				}
			}
		}
		if (ans == 0) {
			cout << "Case #" << t + 1 << ": " << "RICHARD";
		}
		else {
			cout << "Case #" << t + 1 << ": " << "GABRIEL";
		}
		t++;
	}
}