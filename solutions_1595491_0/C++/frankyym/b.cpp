#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	for (int t=0; t<T; ++t) {
		printf("Case #%d: ", t+1);
		
		int N, S, p;
		scanf("%d%d%d", &N, &S, &p);
		int ret = 0;
		for (int i=0; i<N; ++i) {
			int k;
			scanf("%d", &k);
			
			if (k >= p*3) ++ret;
			else if ((k >= p*3-2)&&(p >= 1)) ++ret;
			else if ((k >= p*3-4)&&(p >= 2) && (S > 0)) {
				++ret;
				--S;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
