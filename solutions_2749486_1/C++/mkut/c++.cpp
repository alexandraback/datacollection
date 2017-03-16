#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T; cin >> T;
	for (int caseNo = 1; caseNo <= T; caseNo++) {
		int X, Y; cin >> X >> Y;
		string ans = "";
		int n = 0;
		for (int r = 0; r < abs(X) + abs(Y) || r % 2 != (abs(X) + abs(Y)) % 2;) {
			n++;
			r += n;
		}
		for (int i = n; i > 0; i--) {
			if (abs(X) > abs(Y)) {
				if (X > 0) {
					ans += "E";
					X -= i;
				} else {
					ans += "W";
					X += i;
				}
			} else {
				if (Y > 0) {
					ans += "N";
					Y -= i;
				} else {
					ans += "S";
					Y += i;
				}
			}
		}
		//cerr << X << "," << Y << endl;
		reverse(ans.begin(), ans.end());
		cout << "Case #" << caseNo << ": " << ans << endl;
	}
	return 0;
}
