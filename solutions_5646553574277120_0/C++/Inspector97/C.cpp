#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<string>
#include<sstream>

using namespace std;

#pragma warning (disable : 4996)

int solve(vector<int> &coins, int v) {
	vector<bool> m;
	int ans = 0;
	while (true){
		int len = coins.size();
		m.assign(v + 2, false);
		for (int mask = 0; mask < 1 << len; mask++) {
			int sum = 0;
			for (int i = 0; i < len; i++) {
				if (1 << i & mask) {
					sum += coins[i];
				}
			}
			if (sum <= v) {
				m[sum] = true;
			}
		}
		int cur = 0;
		for (; cur <= v; cur++) {
			if (!m[cur]) {
				coins.push_back(cur);
				ans++;
				break;
			}
		}
		if (cur > v)
			break;
	}
	return ans;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, TT = 0;
	cin >> T;
	while (T-- && ++TT) {
		cout << "Case #" << TT << ": ";
		int c, d, v;
		cin >> c >> d >> v;
		vector<int> vd(d);
		for (int i = 0; i < d; i++) {
			cin >> vd[i];
		}
		cout << solve(vd, v) << endl;
	}
	return 0;
}