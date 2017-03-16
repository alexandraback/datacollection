#include <iostream>
#include <algorithm>
using namespace std;

string solve(string s) {
	string ans = s.substr(0, 1);
	for (int i = 1; i < s.size(); i++) {
		string a = s.substr(i, 1) + ans;
		string b = ans + s[i];
		ans = max(a, b);
	}
	return ans;
}

int main() {
	int T; cin >> T;
	for (int No = 1; No <= T; No++) {
		string S; cin >> S;
		string ans = solve(S);
		cout << "Case #" << No << ": ";
		cout << ans << endl;
	}
	return 0;
}
