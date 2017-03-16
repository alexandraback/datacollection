#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t; cin >> t;
	for (int cas = 1; cas <= t; ++cas) {
		string s; cin >> s >> s;
		int m = 0, t = 0;
		for (int i = 0; i < s.length(); ++i) {
			m = max(m, i - t);
			t += s[i] - '0';
		}
out:	cout << "Case #" << cas << ": " << m << endl;
	}
}
