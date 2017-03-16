#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	int t;
	int i;
	string S;
	string ans;
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	cin >> T;
	for (t = 1; t <= T; ++t) {
		cin >> S;
		cout << "Case #" << t << ": ";
		ans = "";
		ans = ans + S[0];
		for (i = 1; i < S.length(); ++i) {
			if (S[i] >= ans[0])
				ans = S[i] + ans;
			else
				ans = ans + S[i];
		}
		cout << ans << endl;
	}
	return 0;
}