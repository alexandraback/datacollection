#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

typedef long long int64;

const int MOD = int(1e9) + 7;

int64 fact(int n) {
	int64 ret = 1;
	for (int i = 1; i <= n; ++i) {
		ret = ret * i % MOD;
	}
	return ret;
}

int main() {
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		printf("Case #%d: ", nc);
		int n;
		cin >> n;
		vector<string> s(n);
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
		}
		long long ans = 1;
		for (char a = 'a'; a <= 'z'; ++a) {
			vector<int> right, left, mid;
			for (int i = 0; i < s.size(); ++i) {
				if (count(s[i].begin(), s[i].end(), a) == s[i].size()) {
					mid.push_back(i);
				} else if (s[i][0] == a) {
					right.push_back(i);
				} else if (s[i].back() == a) {
					left.push_back(i);
				}
			}
			if (left.size() > 1 || right.size() > 1) {
				ans = 0;
			}
			if (ans == 0)
				break;
			ans *= fact(mid.size());
			ans %= MOD;
			string tmp = "";
			for (vector<int>::iterator e = left.begin(); e != left.end(); ++e) {
				tmp += s[*e];
				s[*e] = "";
			}
			for (vector<int>::iterator e = mid.begin(); e != mid.end(); ++e) {
				tmp += s[*e];
				s[*e] = "";
			}
			for (vector<int>::iterator e = right.begin(); e != right.end();
					++e) {
				tmp += s[*e];
				s[*e] = "";
			}
			vector<string> ns;
			for (int i = 0; i < s.size(); ++i) {
				if (s[i] != "")
					ns.push_back(s[i]);
			}
			if (tmp != "")
				ns.push_back(tmp);
			s = ns;
		}

		if (ans == 0) {
			cout << ans << endl;
			continue;
		}
		ans *= fact(s.size());
		ans %= MOD;
		string str = accumulate(s.begin(), s.end(), string(""));
		bool check = true;
		for (char a = 'a'; a <= 'z'; ++a) {
			vector<int> at;
			for (int i = 0; i < str.size(); ++i) {
				if (str[i] == a)
					at.push_back(i);
			}
			if (!at.empty()) {
				if (at.back() - at.front() + 1 != at.size())
					check = false;
			}
		}

		if (!check)
			ans = 0;
		cout << ans << endl;
	}
}
