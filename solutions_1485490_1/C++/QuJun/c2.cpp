#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int A[101], B[101];
long long a[101], b[101];
long long f[101][101];

int main() {
	int test;
	scanf("%d", &test);
	for (int tt = 1; tt <= test; tt++) {
		cout << "Case #" << tt << ": ";
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> a[i] >> A[i];
		for (int i = 1; i <= m; i++)
			cin >> b[i] >> B[i];
		memset(f, 0, sizeof(f));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
				for (int x = 1; x <= i; x++) {
					long long cnt[101];
					memset(cnt, 0, sizeof(cnt));
					for (int k = x; k <= i; k++)
						cnt[A[k]] += a[k];
					long long cnt2[101];
					memset(cnt2, 0, sizeof(cnt2));
					long maxv = 0, maxc = 0;
					for (int y = j; y >= 1; y--) {
						cnt2[B[y]] += b[y];
						if (min(cnt[B[y]], cnt2[B[y]]) > maxv) {
							maxv = min(cnt[B[y]], cnt2[B[y]]);
							maxc = B[y];
						}
						f[i][j] = max(f[i][j], f[x - 1][y - 1] + maxv);
					}
				}
			}
		}

		cout << f[n][m] << endl;

	}
}