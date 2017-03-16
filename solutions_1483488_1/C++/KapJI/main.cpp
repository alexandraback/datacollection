#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <set>

using namespace std;

int a, b;

void solve() {
	scanf("%d%d", &a, &b);
	stringstream ss;
	string s;
	int ans = 0;
	for (int i = a; i < b; ++i) {
		set<int> mem;
		ss.str("");
		ss << i;
		s = ss.str();
		int len = s.size();
		for (int j = 0; j < len; ++j) {
			int k = atoi(s.c_str());
			if (k > i && k <= b) {
				mem.insert(k);
			}
			s = s.substr(1, len - 1) + s[0];
		}
		ans += mem.size();
	}
	printf("%d", ans);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; ++i) {
		cerr << "Case #" << i + 1 << endl;
		cout << "Case #" << i + 1 << ": ";
		solve();	
		cout << endl;
	}
	return 0;
}
