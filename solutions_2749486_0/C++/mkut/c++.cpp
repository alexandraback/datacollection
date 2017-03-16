#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T; cin >> T;
	for (int caseNo = 1; caseNo <= T; caseNo++) {
		int X, Y; cin >> X >> Y;
		string ans = "";
		for (int i = 0; i < abs(X); i++) {
			ans += X < 0 ? "EW" : "WE";
		}
		for (int i = 0; i < abs(Y); i++) {
			ans += Y < 0 ? "NS" : "SN";
		}
		cout << "Case #" << caseNo << ": " << ans << endl;
	}
	return 0;
}
