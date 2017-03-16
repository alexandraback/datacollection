#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen ("out.txt", "w", stdout);
	int t;
	long long s, k, c;
	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		cin >> k >> c >> s;
		cout << "Case #" << tc << ":";
		for(int i = 0; i < s; i++) {
			cout << " " << i + 1;
		}
		cout << "\n";
	}
	return 0;
}