#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

string solve(string &s) {
	string t;
	for (auto it = s.begin(); it != s.end(); it++) {
		if (t.empty()) {
			t.push_back(*it);
		} else if (*it >= t.front()) {
			t = *it + t;
		} else {
			t.push_back(*it);
		}
	}
	return t;
}

int main() {
	int t;
	string s;

	cin >> t;
	vector<string> ans(t);
	for (int i = 0; i < t; i++) {
		cin >> s;
		ans[i] = solve(s);
	}

	for (int i = 0; i < t; i++) {
		printf("Case #%d: %s\n", i + 1, ans[i].c_str());
	}
	return 0;
}
