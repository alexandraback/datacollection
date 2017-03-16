#include <iostream>
using namespace std;

long long dp[101][101];
int N, M;
long long a[101], b[101], A[101], B[101];
long long min (long long a, long long b) {
	return a > b ? b : a;
}

int main () {
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		for (int i = 1; i <= N; ++i) {
			cin >> a[i] >> A[i];
		}
		for (int i = 1; i <= M; ++i) {
			cin >> b[i] >> B[i];
		}
		memset (dp, 0, 101*101*sizeof(long long));
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				for (int k = 0; k < i; ++k) {
					for (int l = 0; l < j; ++l) {
						for (int p = 1; p <= 100; ++p) {
							long long tmp1 = 0;
							long long tmp2 = 0;
							for (int q = k + 1; q <= i ; q++) {
								if (A[q] == p) {
									tmp1 += a[q];
								}
							}
							for (int q = l+1; q <= j; q++) {
								if (B[q] == p) {
									tmp2 += b[q];
								}
							}
							dp[i][j] = dp[i][j] > (dp[k][l] + min(tmp1, tmp2))? dp[i][j] : (dp[k][l] + min(tmp1, tmp2));
						}
					}
				}
			}
		}
		cout << "Case #" << t+1 << ": " << dp[N][M] << endl;
	}
}

