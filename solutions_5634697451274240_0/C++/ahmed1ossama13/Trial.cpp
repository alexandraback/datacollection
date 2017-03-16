#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	freopen("/home/ahmed/Desktop/B-small-attempt0.in", "r", stdin);
	freopen("/home/ahmed/Desktop/B-small-attempt0.out", "w", stdout);
	int t; cin >> t;
	int id = 1;
	while (t--) {
		string s; cin >> s;
		int ans = 0;
		int plus = 0, minus = 0;
		for (int i = 0; i < int(s.size()); i++) {
			if (s[i] == '-') {
				minus++;

			}
			else {
				if (minus) {
					ans++;
					ans += plus > 0;
				}
				minus = plus = 0;
				plus++;
			}
		}
		if (minus) {
			ans++;
			ans += plus > 0;
		}
		cout << "Case #" << id << ": " << ans << endl;
		id++;
	}


	return 0;
}
