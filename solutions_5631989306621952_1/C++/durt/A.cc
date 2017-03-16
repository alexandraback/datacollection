#include <bits/stdc++.h>
using namespace std;

string solve(string s) {
	string ans = "";
	ans += s[0];
	for (int i = 1; i < (int)s.length(); i++) {
		bool before = true;
		for (int j = 0; j < (int)ans.length(); j++) {
			if (ans[j] > s[i]) {
				before = false;
				break;
			}
		}
		
		if (before) {
			ans = s[i] + ans;
		} else {
			ans = ans + s[i];
		}
	}
	return ans;
}

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		string s;
		cin >> s;
		string res = solve(s);
		cout << "Case #" << icase << ": " << res << endl;
	}
	return 0;
}
