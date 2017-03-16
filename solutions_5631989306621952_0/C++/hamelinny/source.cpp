#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int main() {

	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		string s;
		cin >> s;
		string s1 = "";
		s1 += s[0];
		for (int j = 1; j < s.size(); j++) {
			string s2 = "";
			s2 += s[j];
			s2 += s1;
			if (s2 >= s1 + s[j])
				s1 = s2;
			else
				s1 = s1 + s[j];
		}
		cout << "Case #" << i << ": " << s1 << '\n';
	}

}