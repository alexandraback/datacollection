#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

double C[1500][1500];

int main() {
	C[0][0] = 1;
	for (int i = 1; i < 1500; ++i) {
		for (int j = 0; j <= i; ++j) {
			C[i][j] = 0;
			if (j != 0) C[i][j] += C[i - 1][j - 1];
			if (j != i) C[i][j] += C[i - 1][j];
		}
	}
	int T;
	scanf("%d", &T);
	vector<int> Y;
	Y.push_back(1);
	for (int i = 4; i <= 3000; i += 4) {
		Y.push_back(Y.back() + 1 + i);
		if (Y.back() > 1000000) break;
	}
	for (int cn = 1; cn <= T; ++cn) {
		int N, x, y;
		scanf("%d%d%d", &N, &x, &y);
		if (x < 0) x = -x;
		double ret;
		for (int i = 0; i < Y.size(); ++i) {
			if (N == Y[i]) {
				if ((x + y) <= 2 * i) ret = 1.0; else ret = 0.0;
				break;
			}
			if (Y[i] < N && N < Y[i + 1]) {
				if (x + y < 2 * (i + 1)) {
					ret = 1.0;
					break;
				}
				if (x + y > 2 * (i + 1) || (x + y == 2 * (i + 1) && x == 0)) {
					ret = 0.0;
					break;
				}
				int order = N - Y[i]; // 얘는 1 부터 4 * (i + 1) 사이임...
				double up = 0;
				double down = 1;
//				printf("order = %d\n", order);

				if (order <= 2 * (i + 1)) {
					if (y >= order) {
						ret = 0.0;
						break;
					} else {
						for (int j = 0; j < order - y; ++j) {
							up += C[order][j];
						}
					}
					for (int j = 0; j < order; ++j)
						down *= 2;
				} else {
					order -= 2 * (i + 1); // 다시 1 부터 2 * (i + 1) 사이임
					if (y < order) {
						ret = 1.0;
						break;
					} else {
						for (int j = 0; j < 2 * (i + 1) - y; ++j) {
							up += C[2 * (i + 1) - order][j];
						}
					}
					for (int j = 0; j < 2 * (i + 1) - order; ++j)
						down *= 2;
				}
				ret = up / down;
			}
		}
//		printf("Case #%3d : %5d, %5d, %5d -> ", cn, N, x, y);
//		cout << ret << endl;
		printf("Case #%d: %.10lf\n", cn, ret);
//		cout << "Case #" << cn << ": " << ret << endl;
		
	}
}
