#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int mr[105];
int mc[105];
int arr[105][105];

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int I = 0; I < T; ++I) {
		printf("Case #%d: ", I + 1);
		memset(mr, 0, sizeof mr);
		memset(mc, 0, sizeof mc);

		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &arr[i][j]);
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				mr[i] = max(mr[i], arr[i][j]);
				mc[j] = max(mc[j], arr[i][j]);
			}
		}
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (mr[i] != arr[i][j] && mc[j] != arr[i][j]) {
					ok = false;
				}
			}
		}
		if (ok) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}