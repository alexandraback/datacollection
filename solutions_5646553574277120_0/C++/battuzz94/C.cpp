#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> COINS;
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		COINS.clear();
		int C, D, V, ans= 0;
		cin >> C >> D >> V;
		COINS.resize(D);
		for (int i = 0; i < D; i++) {
			cin >> COINS[i];
		}

		sort(COINS.begin(), COINS.end());

		for (int i = 1; i <= V; i++) {
			int target = i;

			for (int j = COINS.size()-1; j>= 0; j--) {
				int c = COINS[j];
				//target -= min(C*c, target-(target%c));
				for (int k = 1; k<=C && target>=c; k++) target-=c;
			}
			if (target > 0) {
				ans++;
				COINS.push_back(i);
				sort(COINS.begin(), COINS.end());
			}
		}

		cout << "Case #" << tc << ": " << ans << endl;
	}
}