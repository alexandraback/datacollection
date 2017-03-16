#include <cstdio>

int casei, cases, N, S, p, score, ans, best;

int main() {
	
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	scanf("%d", &cases);
	for (casei = 1; casei <= cases; ++casei) {
		scanf("%d%d%d", &N, &S, &p);
		ans = 0;
		for (int i = 0; i < N; ++i) {
			scanf("%d", &score);
			best = score / 3;
			if (score % 3) ++best;
			if (best >= p) {
				//printf("%d!\n", score);
				++ans;
			}
			else
				if (S > 0 && score % 3 != 1 && score >= 2 && score <= 28 && best + 1 >= p) {
					//printf("%d!\n", score);
					++ans;
					--S;
				}
		}
		printf("Case #%d: %d\n", casei, ans);
	}
	
	return 0;
}
