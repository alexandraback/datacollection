#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
int c, d, v;
int coin[200];

int main() {
	int T;
	cin >> T;
	for (int itest = 1; itest <= T; ++itest) {
		int ans = 0;

		cin >> c >> d >> v;
		for (int i = 0; i < d; ++i) {
			cin >> coin[i];
		}
		coin[d] = 1e9;

		int curcoin = 0;
		int maxval = 0;
		while (maxval < v) {
			if (maxval + 1 >= coin[curcoin]) {
				maxval += coin[curcoin] * c;
				++curcoin;
				continue;
			}
			else {
				int newcoin = maxval + 1;
				ans++;
				maxval += newcoin * c;
			}
		}
		cout << "Case #" << itest << ": " << ans << "\n";
	}
	return 0;
}
