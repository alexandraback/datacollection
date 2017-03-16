#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	int ti;
	cin >> ti;
	cout << "Case #1:\n";
	int r, n, m, k;
	cin >> r >> n >> m >> k;

	for (int ri=0; ri<r; ri++) {
		vector<int> prim_all(10);
		vector<int> prim_max(10);
		for (int i = 0; i < k; i++) {
			ll prod;
			cin >> prod;
			for (int p : { 2, 3, 5 }) {
				int c = 0;
				while (prod % p == 0) {
					prod /= p;
					c++;
				}
				prim_all[p] += c;
				prim_max[p] = max(prim_max[p], c);
			}
		}

		vector<int> count(10);
		count[3] = max(prim_max[3], prim_all[3] * 2 / k);
		count[5] = max(prim_max[5], prim_all[5] * 2 / k);
		int rem = n - count[3] - count[5];
		count[4] = min(rem, max(prim_max[2] - rem, prim_all[2] * 2 / k - rem));
		count[2] = rem - count[4];

		int sum = 0;
		for (int i = 0; i < m+1 && sum < n; i++)
			for (int j = 0; j < count[i] && sum < n; j++) {
				cout << i;
				sum ++;
			}
		cout << endl;
	}
	return 0;
}
