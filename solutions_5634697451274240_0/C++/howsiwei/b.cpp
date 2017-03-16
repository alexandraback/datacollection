#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int itc;

void solve() {
	string s;
	cin >> s;
	int ans = 0;
	bool b = true;
	for (int i = s.size()-1; i >= 0; i--) {
		if ((s[i] == '+') != b) {
			ans++;
			b = !b;
		}
	}
	printf("%d\n", ans);
}

int main() {
	cin.sync_with_stdio(false);
	int ntc;
	cin >> ntc;
	for (itc = 1; itc <= ntc; itc++) {
		printf("Case #%d: ", itc);
		solve();
	}
}
