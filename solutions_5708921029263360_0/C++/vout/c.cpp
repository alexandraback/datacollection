#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

typedef long long LL;

int count[10][10][10];
int countXY[10][10], countXZ[10][10], countYZ[10][10];

int x, y, z, K;
vector<int> ans;
vector<int> v;

void gao(int i, int j, int k) {
	if (k == z) {
		if (ans.size() < v.size()) ans = v;
	} else {
		int ii = i + 1, jj = j, kk = k;
		if (ii == x) { ii = 0; jj++; }
		if (jj == y) { jj = 0; kk++; }
		if (countXY[i][j] < K && countXZ[i][k] < K && countYZ[j][k] < K) {
			v.push_back(i * 100 + j * 10 + k);
			countXY[i][j]++; countXZ[i][k]++; countYZ[j][k]++;
			gao(ii, jj, kk);

			v.pop_back();
			countXY[i][j]--; countXZ[i][k]--; countYZ[j][k]--;
		}
		gao(ii, jj, kk);
	}
}

int main() {
	int T;
	cin >> T;
	for (int re = 1; re <= T; ++re) {
		cin >> x >> y >> z >> K;
		ans.clear();
		v.clear();
		gao(0, 0, 0);
		cout << "Case #" << re << ": " << ans.size() << endl;
		for (int i = 0; i < ans.size(); ++i) {
			cout << ans[i] / 100 + 1 << ' ' << ans[i] % 100 / 10 + 1 << ' ' << ans[i] % 10 + 1 << endl;
		}
	}

	return 0;
}