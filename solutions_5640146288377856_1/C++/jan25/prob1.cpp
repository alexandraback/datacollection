#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) {
		int r,c ,w; cin >> r >> c >> w;
		int ans = (r-1)*(c/w);
		int j = 0;
		while (j < c - w) {
			j += w;
			++ans;
		}
		ans += w;
		cout << "Case #" << i << ": " << ans << endl;
	}

	return 0;
}