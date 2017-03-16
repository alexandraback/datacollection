#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ++ca) {
		printf("Case #%d: ", ca);
		int p, q;
		scanf("%d/%d", &p, &q);
		int t = q;
		while (t % 2 == 0)
			t /= 2;
		if (t > 1) {
			puts("impossible");
			continue;
		}
		t = 0;
		while (p < q) {
			p *= 2;
			++t;
		}
		printf("%d\n", t);
	}
	return 0;
}
