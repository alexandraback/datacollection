#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

int judge(int n, string s) {
	stringstream ss;
	ss << n;
	string nstr = ss.str();
	if (nstr.length() > s.length())
		return 0;
	reverse(s.begin(), s.end());
	reverse(nstr.begin(), nstr.end());
	//cout << s << endl;;
	//getchar();
	for (int i = 0; i < s.length(); ++i) {
		//cout << i << ": " << s[i] << ", " << nstr[i] << endl;
		if (s[i] == '?' || (i < nstr.length() && s[i] == nstr[i]) || (i >= nstr.length() && s[i] == '0')) {
			continue;
		}
		return 0;
	}
	return 1;
}

string ans_str(int n, string s) {
	stringstream ss;
	ss << n;
	string nstr = ss.str();
	reverse(s.begin(), s.end());
	reverse(nstr.begin(), nstr.end());
	for (int i = 0; i < s.length(); ++i) {
		if (i < nstr.length()) {
			s[i] = nstr[i];
		} else {
			s[i] = '0';
		}
	}
	reverse(s.begin(), s.end());
	return s;
}

int main() {
	int t, ansi, ansj, mini, tc = 0;
	string s1, s2;
	cin >> t;
	while (t--) {
		cin >> s1 >> s2;
		ansi = ansj = 1e9;
		mini = 1e9;
		for (int i = 0; i < 999; ++i) {
			if (judge(i, s1)) {
				for (int j = 0; j < 999; ++j) {
					if (judge(j, s2)) {
						if (mini == abs(i - j)) {
							if (i < ansi) {
								ansi = i, ansj = j;
							} else if (i == ansi && j < ansj) {
								ansi = i, ansj = j;
							}
						} else if (mini > abs(i - j)) {
							ansi = i, ansj = j;
							mini = abs(i - j);
						}
					}
				}
			}
		}
		cout << "Case #" << ++tc << ": " << ans_str(ansi, s1) << " " << ans_str(ansj, s2) << endl;
	}
	return 0;
}