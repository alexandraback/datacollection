#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string t1, key;

const int MAXN = 1010;

int cnt[MAXN];

int main() {
	int tt;
	cin >> tt;
	for (int o = 1; o <= tt; o++) {
		int k, l, s;
		cin >> k >> l >> s;
		cin >> t1 >> key;
		int len = 0;
		for (int l = 1; l < key.size(); l++) {
			bool good = true;
			for (int i = 0; i < l; i++)
				if (key[i] != key[i + (int)key.size() - l])
					good = false;
			if (good)
				len = l;
		}
		len = (int)key.size() - len;
//		cerr << "len: " << len << endl;
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < t1.size(); i++)
			cnt[t1[i]]++;
		bool canMake = key.size() <= s;
		for (int i = 0; i < key.size(); i++)
			if (cnt[key[i]] == 0)
				canMake = false;
		int mx = 0;
		if (canMake) {
			int sz = key.size();
			mx = 1;
			while (sz + len <= s) {
//				cerr << " sz: " << sz << " " << mx << endl;
				sz += len, mx++;
			}
		}
//		cerr << " mx " << mx << endl;
		vector<int> p;
		for (int i = 0; i < key.size(); i++)
			p.push_back(cnt[key[i]]);
		double ans = 0;
		if (mx) {
			sort(p.begin(), p.end(), greater<int>());
			ans = 1.0 * s - 1.0 * (int)key.size() + 1.0;
//			cerr << " prev ans : " << ans << endl;
			for (int i = 0; i < p.size(); i++)
				ans = ans * (double)p[i] / (double)t1.size();
		}
		cout << "Case #" << o << ": " << setprecision(7) << fixed << (double)mx - ans << endl;
	}
	return 0;
}
