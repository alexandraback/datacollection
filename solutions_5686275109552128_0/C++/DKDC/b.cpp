#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	int T, n = 1, D;

	cin >> T;

	while (n <= T) {
		cin >> D;
		int M = INT_MIN;
		int MCnt = 0;
		vector <int> P;
		for (int i = 0; i < D; i++) {
			int Pi;
			cin >> Pi;
			P.push_back(Pi);
			if (M < Pi) {
				M = Pi;
				MCnt = 1;
			} else if (M == Pi) {
				MCnt++;
			}
		}

		int ans = M;
		int SMCnt = MCnt;

		while (M > 3) {
			int M2 = (M + 1) / 2;
			if (M2 != M - M2 && M2 % 3 > 0 && (M - M2) % 3 > 0) {
				M2++;
			}
			for (int i = 0; i < P.size(); i++) {
				if (P[i] == M) {
					P[i] = M2;
					P.push_back(M - M2);
				}
			}
			int M3 = INT_MIN;
			int MCnt3 = 0;
			for (int i = 0; i < P.size(); i++) {
				if (P[i] > M3) {
					M3 = P[i];
					MCnt3 = 1;
				} else if (P[i] == M3) {
					MCnt3++;
				}
			}
			int tempans = M3 + SMCnt;
			if (tempans < ans) {
				ans = tempans;
			}
			M = M3;
			SMCnt += MCnt3;
		}
		cout << "Case #" << n++ << ": " << ans << endl;
	}
	return 0;
}
