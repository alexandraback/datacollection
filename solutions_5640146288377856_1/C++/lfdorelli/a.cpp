#include <bits/stdc++.h>

using namespace std;


int main (void) {
	int t, r, c, w;
	cin >> t;
	for (int T = 1; T <= t; ++T) {
		cin >> r >> c >> w;
		int ans = 0;
		for (int j = 0; j < c; ++j) 
			if ((j+1)%w == 0) ans++;
		ans *= (r-1);
		int lj = 0;
		for (int j = 0; j < c; ++j) {
			if ((j+1)%w == 0) { 
				ans++; 
				lj = j;
			}
		}
		// cout << ans << " " << lj << endl;
		if (lj + 1 < c) ans += 1;
		ans += w-1;
		cout << "Case #" << T << ": " << ans << endl;
	}
	return 0;
}