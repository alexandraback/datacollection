#include <cstdio>
#include <memory.h>

int main() {
	int T;
	scanf("%d",&T);
	for (int tc = 1; tc <= T; tc++) {
		int N;
		scanf("%d",&N);

		int ar[2505];
		memset(ar, 0, sizeof ar);

		int a;
		for (int i = 0; i < 2*N-1; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d",&a);
				ar[a]++;
			}
		}

		printf("Case #%d:", tc);
		for (int i = 1; i <= 2500; i++) {
			if (ar[i] % 2)
				printf(" %d", i);
		}
		printf("\n");
	}
	return 0;
}