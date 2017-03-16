#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	unsigned int a, b, k;
	int ans;
	vector<vector<pair<char, int> > > v;
	for (int re = 1; re <= T; ++re) {
		cin >> a >> b >> k;
		ans = 0;
		for (int i = 0; i < a; ++i) {
			for (int j = 0; j < b; ++j) {
				if ((i & j) < k) {
					ans++;
				}
			}
		}
		cout << "Case #" << re << ": " << ans << endl;
	}
	return 0;
}