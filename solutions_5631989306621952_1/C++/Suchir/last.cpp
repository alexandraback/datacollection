#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int T;

int main() {
	freopen("A.in", "r", stdin);
	cin >> T;
	for(int nt = 1; nt <= T; nt++) {
		string s;
		cin >> s;
		string ans = "";
		for(char x: s)
			ans = max(x + ans, ans + x);
		cout << "Case #" << nt << ": " << ans << '\n';
	}
}