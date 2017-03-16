#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

int itc;

void solve() {
	string s;
	cin >> s;
	deque<char> t;
	for (char c: s) {
		if (t.empty() || c >= t[0]) {
			t.push_front(c);
		} else {
			t.push_back(c);
		}
	}
	for (char c: t) {
		printf("%c", c);
	}
	puts("");
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
