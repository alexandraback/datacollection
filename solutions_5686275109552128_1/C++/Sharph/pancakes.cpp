#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int X[1010][1010];

int main() {
	for(int i = 1; i < 1010; ++i) {
		for(int j = i + 1; j < 1010; ++j) {
			X[i][j] = INT_MAX;
			for(int d = 1; d < j; ++d) {
				X[i][j] = min(X[i][j], X[i][d] + X[i][j - d] + 1);
			}
		}
	}
	
	cin.sync_with_stdio(false);
	
	int T;
	cin >> T;
	
	for(int t = 0; t < T; ++t) {
		int D;
		cin >> D;
		
		vector<int> S;
		int maxp = 0;
		for(int i = 0; i < D; ++i) {
			int p;
			cin >> p;
			maxp = max(maxp, p);
			S.push_back(p);
		}
		
		int res = INT_MAX;
		for(int i = 1; i <= maxp; ++i) {
			int a = i;
			for(int s : S) {
				a += X[i][s];
			}
			res = min(res, a);
		}
		
		cout << "Case #" << t + 1 << ": " << res << '\n';
	}
	
	return 0;
}
