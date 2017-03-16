#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cassert>

using namespace std;

int T;
int R, N, M, K;
long long prod[13];
long long minX[4], temp[12][4];
long long extra[10];
int prime[] = {2, 3, 5, 7};

int main() {
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		srand(time(NULL));
		cout << "Case #" << tt << ":" << endl;
		cin >> R >> N >> M >> K;
		for (int i = 0; i < R; i++) {
			memset(extra,0,sizeof(extra));
			memset(minX, 0, sizeof(minX));
			for (int j = 0; j < K; j++) {
				cin >> prod[j];
				memset(temp[j], 0, sizeof(temp[j]));
				long long tmp = prod[j];
				for (int k = 0; k < 4; k++) {
					while (tmp % prime[k] == 0) {
						temp[j][k]++;
						tmp /= prime[k];
					}
					minX[k] = max(minX[k], temp[j][k]);
				}
			}
			long long total = 0;
			for (int k = 0; k < 4; k++) {
				total += minX[k];
			}
			//assert(total >= N);
			while (total > N) {
				// flip a damn coin
				int cointoss = rand()%3;
				if (total - N > 1 && cointoss == 0 && minX[0] > 2) { // 2 * 2 * 2
					minX[0] -= 3;
					extra[8]++;
					total -= 2;
				} else if (minX[0] > 1) { // 2 * 2
					minX[0] -= 2;
					extra[4]++;
					total--;
				} else if (minX[0] > 0 && minX[1] > 0) { // 2 * 3
					//assert(minX[0] > 0 && minX[1] > 0);
					minX[0]--;
					minX[1]--;
					extra[6]++;
					total--;
				} else if (minX[0] > 0 && extra[4] > 0) {
					minX[0]--;
					extra[4]--;
					extra[8]++;
					total--;
				} else {
					break;
				}
			}
			int test = 0;
			for (int k = 0; k < 4 && test < N; k++) {
				for (int kk = 0; kk < minX[k] && test < N; kk++) {
					cout << minX[k];
					test++;
				}
			}
			for (int k = 2; k <= 8 && test < N; k++) {
				for (int kk = 0; kk < extra[k] && test < N; kk++){
					cout << k;
					test++;
				}
			}
			if (test != N) {
				//cerr << "error " << i << " " << test << endl;
			}
			while (test != N) {
				cout << 2;
				test++;
			}
			cout << endl;
		}
	}
	return 0;
}
