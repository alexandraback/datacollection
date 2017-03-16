#include <iostream>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int D;
		cin >> D;
		vector<int> P;
		int res = 0;
		for (int i = 0; i < D; ++i) {
			int p;
			cin >> p;
			res = max(res, p);
			P.push_back(p);
		}
		for (int i = 1; i < res; ++i) {
			int moves = 0;
			for (auto p : P) {
				moves += (p-1)/i;
			}
			res = min(res, moves + i);
		}
		cout << "Case #" << t << ": " << res << endl;
	}
	return 0;
}
