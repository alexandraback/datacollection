#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
const int MAXN = 10, MAXE = 5;
int e, r, v[MAXN];
int f[MAXN + 1][MAXE + 1];

int main()
{
	int dat;
	scanf("%d", &dat);
	for (int t = 1; t <= dat; ++t) {
		scanf("%d%d%d", &e, &r, &n);
		for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
		memset(f, 0, sizeof(f));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= e; ++j) {
				for (int k = 0; k <= j; ++k) {
					f[i + 1][min(e, j - k + r)] =
						max(f[i + 1][min(e, j - k + r)],
						    f[i][j] + k * v[i]);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i <= e; ++i) ans = max(ans, f[n][i]);
		printf("Case #%d: %d\n", t, ans);
	}
}
