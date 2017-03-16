/*/**/

#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		cin >> s;
		string ans = "";
		ans += s[0];
		for(int i = 1; i < s.size(); i++) {
			if(s[i] < ans[0]) {
				ans = ans + s[i];
			}
			else {
				ans = s[i] + ans;
			}
		}
		cout << "Case #" << tt << ": ";
		cout << ans << endl;
	}
	return 0;
}
