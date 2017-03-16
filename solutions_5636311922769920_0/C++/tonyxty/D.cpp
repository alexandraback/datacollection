#include <cstdio>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int k, c, s;
		scanf("%d%d%d", &k, &c, &s);
		int L = (k + c - 1) / c;
		printf("Case #%d:", t);
		if (s < L) puts(" IMPOSSBLE");
		else {
			int b = 0;
			for (int i = 0; i < L; i++) {
				long long ans = 0;
				for (int j = 0; j < c; j++) {
					int x = b + j;
					ans *= k;
					if (x < k) ans += x;
				}
				printf(" %lld", ans + 1);
				b += c;
			}
			putchar('\n');
		}
	}
}
