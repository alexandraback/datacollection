#include <stdio.h>
#include <stdlib.h>

int main() {
	int T, t;
	long long A, B, K, i, j, ans;
	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		printf("Case #%d: ", t + 1);
		scanf("%lld %lld %lld", &A, &B, &K);
		if (K > A && K > B)
			K = (A > B ? B : A);
		//================	
		ans = 0;
		for (i = 0; i < A; i++) {
			for (j = 0; j < B; j++) {
				if ((i & j) < K)
					ans++;
			}
		}
		printf("%lld\n", ans);
		//================	
	}
	return 0;
}
