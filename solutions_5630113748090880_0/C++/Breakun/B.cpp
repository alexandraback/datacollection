#include <cstdio>
#include <iostream>
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

		for (int i = 1; i <= 2500; i++) {
			if (cnt[i] % 2) {
				printf(" %d", i);
			}
		}

		printf("\n");
	}

	return 0;
}
