#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int n;
string v[16][2];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i][0] >> v[i][1];
	int opt = 0;
	for (unsigned int comb = 0; comb < (1 << n); comb++) {
		set<string> s1, s2;
		for (int i = 0; i < n; i++)
			if ((comb & (1 << i)) == 0) {
				s1.insert(v[i][0]);
				s2.insert(v[i][1]);
			}
		bool flag = true;
		for (int i = 0; i < n; i++)
			if (comb & (1 << i)) {
				if (s1.find(v[i][0]) == s1.end() || s2.find(v[i][1]) == s2.end()) {
					flag = false;
					break;
				}
			}
		if (!flag)
			continue;
		int cnt = 0;
		unsigned int mask = 0x1000000;
		while (mask) {
			if (mask & comb)
				cnt++;
			mask >>= 1;
		}
		if (cnt > opt)
			opt = cnt;
	}
	cout << opt << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
