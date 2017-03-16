#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

string make_equal(int n, string &c, string &j) {
	string s(n, '.');
	for (int i = 0; i < n; i++) {
		if (c[i] == '?' || j[i] == '?') {
			s[i] = c[i] == '?' ? j[i] : c[i];
			if (s[i] == '?') {
				s[i] = '0';
			}
		} else if (c[i] == j[i]) {
			s[i] = j[i];
		} else {
			return "";
		}
	}
	return s;
}

tuple<string, string, long long> make_diff(int n, string &s1, string &s2) {
	vector<pair<string, string>> pairs;
	// cout << n << s1 << s2 << endl;

	// 変更開始する場所
	for (int i = 0; i < n; i++) {
// cout << i << "------" << endl;
		// t1 > t2となるようにする
		string t1(n, '@');
		string t2(n, '@');

		bool ok = true;
		for (int j = 0; j < i; j++) {
// cout << i <<  ", " << j << ", " << t1 << ", " << t2 << endl;
			if (s1[j] == '?' && s2[j] == '?') {
				t1[j] = '0';
				t2[j] = '0';
			} else if (s1[j] == '?' && s2[j] != '?') {
				t1[j] = s2[j];
				t2[j] = s2[j];
			} else if (s1[j] != '?' && s2[j] == '?') {
				t1[j] = s1[j];
				t2[j] = s1[j];
			} else if (s1[j] == s2[j]) {
				t1[j] = s1[j];
				t2[j] = s1[j];
			} else {
				ok = false;
				break;
			}
// cout << i <<  ", " << j << ", " << t1 << ", " << t2 << endl;
		}
		if (!ok) {
			continue;
		}

		{
			int j = i;
// cout << i <<  ", " << j << ", " << t1 << ", " << t2 << endl;
			if (s1[j] == '?' && s2[j] == '?') {
				t1[j] = '1';
				t2[j] = '0';
			} else if (s1[j] == '?' && s2[j] != '?') {
				if (s2[j] == '9') {
					ok = false;
				}
				t1[j] = s2[j] + 1;
				t2[j] = s2[j];
			} else if (s1[j] != '?' && s2[j] == '?') {
				if (s1[j] == '0') {
					ok = false;
				}
				t1[j] = s1[j];
				t2[j] = s1[j] - 1;
			} else if (s1[j] > s2[j]) {
				t1[j] = s1[j];
				t2[j] = s2[j];
			} else {
				ok = false;
			}
// cout << i <<  ", " << j << ", " << t1 << ", " << t2 << endl;
		}
		if (!ok) {
			continue;
		}

		for (int j = i + 1; j < n; j++) {
// cout << i <<  ", " << j << ", " << t1 << ", " << t2 << endl;
			t1[j] = s1[j] == '?' ? '0' : s1[j];
			t2[j] = s2[j] == '?' ? '9' : s2[j];
			if (s1[j] == '?') {
			}

			if (s2[j] == '?') {
				t2[j] = '9';
			}
// cout << i <<  ", " << j << ", " << t1 << ", " << t2 << endl;
		}
		if (!ok) {
			continue;
		}

		pairs.emplace_back(make_pair(t1, t2));
	}

	long long diff_min = 2e18;
	long long n1_min = 2e18;
	tuple<string, string, long long> ans
		= make_tuple(string(18, '9'), string(18, '0'), 1e18 - 1);

	for (auto p : pairs) {
		long long n1 = stoll(p.first);
		long long n2 = stoll(p.second);
		long long diff = n1 - n2;

		if (diff < diff_min) {
			diff_min = diff;
			ans = make_tuple(p.first, p.second, diff);
			n1_min = n1;
		} else if (diff == diff_min && n1 < n1_min) {
			diff_min = diff;
			ans = make_tuple(p.first, p.second, diff);
			n1_min = n1;
		}
	}


	return ans;
}


string solve(string &c, string &j) {
	int n= c.size();
	string s = string(c.size(), '.');

	string s_equal = make_equal(n, c, j);
	if (!s_equal.empty()) {
		return s_equal + " " + s_equal;
	}

	auto tup1 = make_diff(n, c, j);
	auto tup2 = make_diff(n, j, c);

	if (get<2>(tup1) < get<2>(tup2)) {
		return get<0>(tup1) + " " + get<1>(tup1);
	} else if (get<2>(tup1) > get<2>(tup2)) {
		return get<1>(tup2) + " " + get<0>(tup2);
	} else {
		if (get<0>(tup1) <= get<0>(tup2)) {
			return get<0>(tup1) + " " + get<1>(tup1);
		} else {
			return get<1>(tup2) + " " + get<0>(tup2);
		}
	}
}

int main() {
	int t;
	string c, j;

	cin >> t;
	vector<string> ans(t);
	for (int i = 0; i < t; i++) {
		cin >> c >> j;
		ans[i] = solve(c, j);
	}

	for (int i = 0; i < t; i++) {
		printf("Case #%d: %s\n", i + 1, ans[i].c_str());
	}
	return 0;
}
