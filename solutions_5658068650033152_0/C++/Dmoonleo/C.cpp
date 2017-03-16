#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

int func(int i) {
	if (i == 0) return 0;
	else return (1 + i) * i / 2;
}

int main() {
	int T;
	cin >> T;
	for(int c=1;c<=T;c++) {
		int N, M, K;
		cin >> N >> M >> K;
		cout << "Case #" << c << ": ";
		if (K <= 4) {
			cout << K << endl;
			continue;
		}
		if (N > M) {
			int temp = N;
			N = M;
			M = temp;
		}
		int ans = K;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				for (int k = 0; k < i; k++) {
					for (int l = 0; l < i; l++) {
						for (int m = 0; m < i; m++) {
							for (int n = 0; n < i; n++) {
								if (k + l >= j || m + n >= j || k + m >= i || l + n >= i) continue;
								int sum = i*j - func(k) - func(l) - func(m) - func(n);
								int cost = i + i + j + j - 4 - k - l - m - n;
								if (sum >= K) {
									ans = ans > cost ? cost : ans;
								}
							}
						}
					}
				}
			}
		}
		cout << ans << endl;

	}
	return 0;
}