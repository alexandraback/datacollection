#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
	int t;
	cin >> t;
	for (int z = 1; z <= t; z++) {
		cin >> s;
		int ans = 0;
		char last = '+';
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] != last) {
				ans++;
				last = s[i];
			}
		}
		cout << "Case #" << z << ": " << ans << endl;
	}
	return 0;
}

