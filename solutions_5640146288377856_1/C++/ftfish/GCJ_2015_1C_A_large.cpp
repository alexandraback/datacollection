#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define PB push_back

int R, C, W, Ans;
int F[30][30];

int DP(int i, int j) {
	if (F[i][j] != -1)
		return F[i][j];

	int ret = i;
	if (i == j)
		ret = i;
	else {
		for (int k = 1; k <= j; k++) {
			int tmp;
			if (i - k >= j) {
				tmp = max(DP(i - k, j), DP(min(i, k + j - 1) - 1, j - 1)) + 1;
				if (tmp < ret)
					ret = tmp;
			} else {
				tmp = DP(min(i, k + j - 1), j - 1) + 1;
				if (tmp < ret)
					ret = tmp;
			}
		}
	}

	F[i][j] = ret;
	//cout << "F[" << i << "][" << j << "]=" << F[i][j] << "\n" ;
	return F[i][j];
}

void Solve() {
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= 20; j++)
			F[i][j] = -1;
	Ans = DP(C, W);
}

int main() {
//	freopen("A.in", "r", stdin);
//	freopen("A.out","w",stdout);

	int Tc;
	cin >> Tc;
	for (int Tn = 1; Tn <= Tc; ++Tn) {
		cin >> R >> C >> W;
		Solve();

		if (R > 1) {
			int tmp = C / W;
			Ans += tmp * (R - 1);
		}

		printf("Case #%d: %d\n", Tn, Ans);
	}
	return 0;
}
