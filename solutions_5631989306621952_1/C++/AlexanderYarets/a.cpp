#include <iostream>
#include <string>
using namespace std;

string solve(string s) {
	int n = s.size();
	string res;
	res += s[0];
	for (int i = 1; i < n; ++i) {
		if (s[i] >= res[0]) res.insert(0, 1, s[i]);
		else res += s[i];
	}
	return res;
}

int main() {
	int T; cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		string s; cin >> s;
		cout << "Case #" << tt << ": " << solve(s) << endl;
	}
	return 0;
}