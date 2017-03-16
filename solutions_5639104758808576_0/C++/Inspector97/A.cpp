#include <iostream>
#include <vector>
#include <string>

using namespace std;

#pragma warning (disable : 4996)

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int K, KK = 0;
	cin >> K;
	while (K-- && ++KK) {
		cout << "Case #" << KK << ": ";
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> v(n + 1);
		int ans = 0, up = 0;
		up = s[0] - '0';
		for (int i = 1; i <= n; i++) {
			int cur = s[i] - '0';
			if (cur == 0)
				continue;
			if (i <= up) {
				up += cur;
			}
			else {
				ans += i - up;
				up += i - up;
				up += cur;
			}
		}
		cout << ans;
		cout << "\n";
	}
	return 0;
}
