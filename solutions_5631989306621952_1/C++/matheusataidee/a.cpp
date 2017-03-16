#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int z = 1; z <= t; z++) {
		string s;
		cin >> s;
		string word = "";
		word += s[0];
		char last, first;
		last = first = s[0];
		stack<char> mystk;
		for (int i = 1; i < (int)s.size(); i++) {
			if (s[i] >= last) {
				last = s[i];
				mystk.push(s[i]);
			} else {
				first = s[i];
				word += s[i];
			}
		}
		string ans = "";
		while (!mystk.empty()) {
			char p = mystk.top();
			mystk.pop();
			ans += p;
		}
		ans += word;
		cout << "Case #" << z << ": " << ans << endl;
	}
	return 0;
}
