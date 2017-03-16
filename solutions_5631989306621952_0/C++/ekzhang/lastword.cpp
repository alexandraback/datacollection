#include <bits/stdc++.h>
using namespace std;

string S;
int L;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("lastword.in", "r", stdin);
	freopen("lastword.out", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		cin >> S;
		L = S.size();
		string ans = "";
		ans += S[0];
		char low = ans[0];
		for (int i = 1; i < L; i++) {
			char c = S[i];
			if (c >= low) {
				ans = c + ans;
				low = c;
			}
			else {
				ans += c;
			}
		}
		cout << ans << '\n';
	}

	cout.flush();
	return 0;
}
