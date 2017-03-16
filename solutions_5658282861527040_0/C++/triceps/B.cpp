#include <iostream>

using namespace std;

int main()
{
	int T = 0;
	cin >> T;
	for (int t = 1; t <= T; t++){
		int A, B, K;
		cin >> A >> B >> K;

		long long DP[50][2][2][2] = {0};
		for (int a = 0; a < 2; a++){
			for (int b = 0; b < 2; b++){
				int k = a&b;
				DP[0][(A & 1) <= a][(B & 1) <= b][(K & 1) <= k]++;
			}
		}

		for (int x = 1; x <= 32; x++) {
			A >>= 1;
			B >>= 1;
			K >>= 1;
			for (int a = 0; a < 2; a++) {
				for (int b = 0; b < 2; b++) {
					int k = a&b;
					for (int pa = 0; pa < 2; pa++) {
						for (int pb = 0; pb < 2; pb++) {
							for (int pk = 0; pk < 2; pk++) {
								int ia, ib, ik;
								ia = pa == 0 ? (A & 1) < a : (A & 1) <= a;
								ib = pb == 0 ? (B & 1) < b : (B & 1) <= b;
								ik = pk == 0 ? (K & 1) < k : (K & 1) <= k;
								DP[x][ia][ib][ik] += DP[x - 1][pa][pb][pk];
							}
						}
					}
				}
			}
		}

		printf("Case #%d: %d\n", t, DP[32][0][0][0]);
	}
	return 0;
}