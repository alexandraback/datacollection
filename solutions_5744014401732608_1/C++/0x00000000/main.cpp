#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
#include <tuple>
#include <queue>
#include <utility>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <limits>
#include <new>
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;

void print_mat(vector<vector<bool>>& m) {
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m.size(); j++) {
			if (m[i][j]) cout << '1';
			else cout << '0';
		}
		cout << '\n';
	}
}

int main(void) {
	cin.tie(nullptr);
	cin.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		int B;
		ll M;
		cin >> B >> M;
		ll v = 1;
		v = v << (B - 2);
		if (v < M) {
			cout << "Case #" << tt << ": " << "IMPOSSIBLE" << endl;
			continue;
		}
		else if (v == M) {
			vector<vector<bool>> mat(B, vector<bool>(B, false));
			for (int i = 0; i < B - 1; i++) {
				for (int j = i + 1; j < B; j++) {
					mat[i][j] = true;
				}
			}
			cout << "Case #" << tt << ": " << "POSSIBLE" << endl;
			print_mat(mat);
		}
		else {
			vector<vector<bool>> mat(B, vector<bool>(B, false));
			for (int i = 1; i < B - 1; i++) {
				for (int j = i + 1; j < B; j++) {
					mat[i][j] = true;
				}
			}
			for (int i = 0; i < B - 1; i++) {
				if (M & (1 << i)) {
					mat[0][B - 2 - i] = true;
				}
			}
			cout << "Case #" << tt << ": " << "POSSIBLE" << endl;
			print_mat(mat);
		}
	}

	return 0;
}