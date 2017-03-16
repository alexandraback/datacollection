#include <bits/stdc++.h>
using namespace std;

vector <string> digits = {
	"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

void solve() {
	string s;
	cin >> s;
	vector <int> g_cnt(256);
	for (int i = 0; i < s.size(); ++i) {
		g_cnt[s[i]]++;
	}
	map <int, string> a;
	for (int i = 0; i < 10; ++i) {
		a[i] = digits[i];
	}
	vector <int> ans;
	while (a.size() > 0) {
		char c;
		int d;
		for (char x = 'A'; x <= 'Z'; ++x) {
			int cnt = 0;
			int pos = 0;
			for (int i = 0; i < 10; ++i) {
				if (!a.count(i)) {
					continue;
				}
				bool f = 0;
				for (auto e: a[i]) {
					if (e == x) {
						f = 1;
					}
				}
				cnt += f;
				if (f) {
					pos = i;
				}
			}
			if (cnt == 1) {
				c = x;
				d = pos;
				break;	
			}
		}
		while (g_cnt[c] > 0) {
			for (auto e: a[d]) {
				g_cnt[e]--;
			}
			ans.push_back(d);
		}
		a.erase(d);
	}
	sort(ans.begin(), ans.end());
	for (auto e: ans) {
		cout << e;
	}
	return;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
		cout << endl;
	}
}