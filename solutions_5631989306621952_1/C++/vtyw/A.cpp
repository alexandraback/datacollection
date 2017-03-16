#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		string s;
		cin >> s;
		string ans;
		ans += s[0];
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] >= ans[0])
				ans = s[i] + ans;
			else
				ans += s[i];
		}
		printf("Case #%d: %s\n", t+1, ans.c_str());
	}
}
