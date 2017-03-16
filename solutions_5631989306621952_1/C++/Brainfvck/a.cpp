#include <iostream>
using namespace std;

int main() {
	int kase;
	cin >> kase;
	for (int ii = 1; ii <= kase; ii++) {
	string s;
	cin >> s;
	string ans = "";
	for (int i = 0; i < s.length(); i++) {
		if (ans + s[i] > s[i] + ans) {
			ans = ans + s[i];
		} else {
			ans = s[i] + ans;
		}
	}
	cout << "Case #" << ii << ": " << ans << endl;
	}
	return 0;
}