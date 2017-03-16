#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int T = 0;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int N, M, K;
		scanf("%d %d %d", &N, &M, &K);
		if (M < N) {
			int t = N;
			N = M;
			M = t;
		}
		int ans = K;
		if (N <= 2) {
			ans = K;
		} else {
			int aa, bb;
			for (int a = 1; a <= N-2; a++)
				for (int b = 1; b <= M-2; b++) {
					int max = 2*(a+b)+a*b;
					int ans0 = 2*(a+b)+((K>max)?(K-max):0);
					if (max+4 >= K && ans0 <= ans) {
						ans = ans0;
						aa = a;
						bb = b;
					}
				}
			fprintf(stderr, "#%d: (%d, %d):%d -> (%d, %d):%d\n", t+1, N, M, K, aa, bb, ans);
		}
		printf("Case #%d: ", t+1);
		printf("%d\n", ans);
	}
	return 0;
}

