#include <cstdio>
int main () {
	int T;
	int A, B, K;
	int tt = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &A, &B, &K);
		int ans = 0;
		for (int i = 0 ; i < A ; i++) {
			for (int j = 0 ; j < B ; j++) {
				if ((i&j) < K) ans++;
			}	
		}
		printf("Case #%d: %d\n", tt, ans);
		tt++;
	}
	return 0;
}
