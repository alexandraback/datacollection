#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const uint64_t mod = 1000000007;

bool check(string &s) {
	vector<bool> cnt(256, false);
	cnt[s[0]] = true;
	for (uint32_t i = 1; i < s.size(); ++i) {
		if (cnt[s[i]] && s[i] != s[i - 1])
			return false;
		cnt[s[i]] = true;
	}
	return true;
}

int main()
{
	int T;
	cin >> T;
	for (int test = 0; test < T; ++test) {
		cerr << test << endl;
		int n;
		cin >> n;
		vector<pair<int, string>> v(n);
		uint64_t ans = 0;
		for (int i = 0; i < n; ++i) {
			v[i].first = i;
			cin >> v[i].second;
		}
		sort(v.begin(), v.end());
		do {
			string r;
			for (auto &i : v)
				r += i.second;
			if (check(r)) {
				++ans;
				if (ans == mod)
					ans = 0;
			}
		} while (next_permutation(v.begin(), v.end()));
		cout << "Case #" << test + 1 << ": " << ans << endl;
	}
	return 0;
}