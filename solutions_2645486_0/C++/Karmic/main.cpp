#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <queue>
using namespace std;
const int maxn = 100;

int E, R, N;
int v[maxn];
int opt[maxn][maxn];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	int nc = 0;
	scanf("%d", &T);

	while (T--) {
		scanf("%d%d%d", &E, &R, &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &v[i]);
		}
		memset(opt, -1, sizeof(opt));
		//for (int j = 0; j <= E; j++)
		//	opt[0][j] = 0;
		opt[0][E] = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= E; j++) {
				if (j - R >= 0) {
					for (int k = 0; k <= E; k++) {
						if (k >= (j - R) && opt[i - 1][k] != -1) {
							opt[i][j] = max(opt[i][j], opt[i - 1][k] + (k - (j - R)) * v[i]);
						}
					}
				}
			}
		}
		int ret = 0;
		for (int i = 0; i <= E; i++)
			ret = max(ret, opt[N][i]);
		printf("Case #%d: %d\n", ++nc, ret);
	}

	return 0;
}
