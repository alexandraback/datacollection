#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;

	for(int t = 1; t <= T; t++) {
		string S, ans;
		cin >> S;
		ans = "";
		ans += S[0];
		for(int i = 1; i < S.size(); i++) {
			if(S[i] >= ans[0]) {
				ans = S[i] + ans;
			}
			else {
				ans += S[i];
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
}
