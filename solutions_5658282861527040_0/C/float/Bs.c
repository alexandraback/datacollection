#include <stdio.h>
#include <stdlib.h>

int main()
{
	int T, t;
	int A, B, K;
	int i, j, ans;
	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		ans = 0;
		scanf("%d %d %d", &A, &B, &K);
		for(i = 0; i < A; i++) {
			for(j = 0; j < B; j++) {
				if((i&j) < K)
					ans++;
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
