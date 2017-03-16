#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	for(int kase = 1; kase <= T; kase++) {
		long long c, d, v;
		cin >> c >> d >> v;
		vector<long long> coins;
		for(int i = 0; i < d; i++) {
			long long coin;
			cin >> coin;
			coins.push_back(coin);
		}

		int ind = 0;
		long long cur = 0;
		long long ans = 0;
		while(cur < v) {
			if(ind < coins.size() && coins[ind] <= cur + 1) {
				cur += coins[ind] * c;
				ind++;
			} else {
				cur += (cur + 1) * c;
				ans++;
			}
		}

		cout << "Case #" << kase << ": " << ans << "\n";
	}

	return 0;
}
