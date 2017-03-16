#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string s;

inline void solve () {
	cin >> s;

	string ans;
	for (int i = 0;i < s.size ();i ++) {
		if (s[i]+ans >= ans+s[i]) {
			ans = s[i]+ans;
		} else {
			ans = ans+s[i];
		}
	}

	cout << ans << endl;
}

int main () {
	int t;
	scanf ("%d", &t);

	for (int i = 1;i <= t;i ++) {
		printf ("Case #%d: ", i);
		solve ();
	}
}