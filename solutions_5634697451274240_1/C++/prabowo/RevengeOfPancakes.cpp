#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int Main () {
	string s;
	cin >> s;
	s.resize (unique(s.begin(), s.end()) - s.begin());
	
	cout << s.length() - (s[s.size() - 1] == '+') << endl;
	
	return 0;
}

int main () {
	freopen ("B-large.in", "r", stdin);
	freopen ("B-large.out", "w", stdout);

	int t;
	cin >> t;
	for (int tc=0; tc<t; tc++) {
		cout << "Case #" << tc + 1 << ": ";
		Main ();
	}
	
	return 0;
}