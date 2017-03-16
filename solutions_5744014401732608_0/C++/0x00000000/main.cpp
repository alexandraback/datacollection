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

int rec(vector<vector<bool>>& m, int pos) {
	if (pos == m.size() - 1) {
		return 1;
	}
	int res = 0;
	for (int i = 0; i < m.size(); i++) {
		if (m[pos][i]) {
			int rs = rec(m, i);
			if (rs == -1) return -1;
			res += rs;
		}
	}
	return res;
}

bool src(vector<vector<bool>>& m, ll M) {
	int res = rec(m, 0);
	if (res == M) return true;
	else return false;
}

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
		bool ok = false;
		ll cnt = (B * (B - 1)) / 2;
		for (int i = 1; i < (1 << cnt); i++) {
			vector<vector<bool>> mat(B, vector<bool>(B, false));
			int temp = 0;
			for (int j = 0; j < B - 1; j++) {
				for (int k = j + 1; k < B; k++) {
					mat[j][k] = (i & (1 << temp));
					temp++;
				}
			}
			ok = src(mat, M);
			if (ok) {
				cout << "Case #" << tt << ": " << "POSSIBLE" << endl;
				print_mat(mat);
				break;
			}
		}
		if (!ok) cout << "Case #" << tt << ": " << "IMPOSSIBLE" << endl;
	}

	return 0;
}