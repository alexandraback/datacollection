#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
long long c, d, v;
long long coin[200];

int main() {
	int T;
	cin >> T;
	for (int itest = 1; itest <= T; ++itest) {
		long long ans = 0;

		cin >> c >> d >> v;
		for (int i = 0; i < d; ++i) {
			cin >> coin[i];
		}
		coin[d] = 1e9;

		long long curcoin = 0;
		long long maxval = 0;
		while (maxval < v) {
			if (maxval + 1 >= coin[curcoin]) {
				maxval += coin[curcoin] * c;
				++curcoin;
				continue;
			}
			else {
				long long newcoin = maxval + 1;
				ans++;
				maxval += newcoin * c;
			}
		}
		cout << "Case #" << itest << ": " << ans << "\n";
	}
	return 0;
}
