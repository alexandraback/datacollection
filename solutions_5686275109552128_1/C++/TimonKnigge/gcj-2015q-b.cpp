#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

inline int splitcost(int p, int m) {
	return p / m - (p % m == 0);
}

int main() {

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int D, M = 1000000;
		cin >> D;
		vector<int> P(D, 0);
		for (int i = 0; i < D; ++i) cin >> P[i];
		sort(P.begin(), P.end(), greater<int>());

		int sc = 0, i = 0;
		M = P[0];
		for (int em = P[0] - 1; em > 0; --em) {
			int m = em;
			for (int i = 0; i < P.size(); ++i) {
				if (P[i] <= em) break;
				m += splitcost(P[i], em);
			}
			M = min(M, m);
		}

		cout << "Case #" << t << ": " << M << endl;
	}

	return 0;
}