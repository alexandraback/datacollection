#include <cstdio>

typedef long long ll;

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		ll A, B, K, vysledek = 0;
		scanf("%lld%lld%lld", &A, &B, &K);
		for (ll a = 0; a < A; a++) {
			for (ll b = 0; b < B; b++) {
				if ((a & b) < K) {
					vysledek++;
				}
			}
		}
		printf("Case #%d: %lld\n", t, vysledek);
	}
	return 0;
}
