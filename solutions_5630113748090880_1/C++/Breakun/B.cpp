#include <cstdio>
#include <iostream>
#include <cassert>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d:", t);

		int n;
		scanf("%d", &n);
		int cnt[3000] = {0};
		for (int i = 0; i < (2 * n - 1) * n; i++) {
			int v;
			scanf("%d", &v);
			cnt[v]++;
		}

		int cc = 0;
		for (int i = 1; i <= 2500; i++) {
			if (cnt[i] % 2) {
				printf(" %d", i);
				cc++;
			}
		}

		assert(cc == n);

		printf("\n");
	}

	return 0;
}
