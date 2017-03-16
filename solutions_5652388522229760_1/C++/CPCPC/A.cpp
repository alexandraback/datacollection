#include <cstring>
#include <cstdio>
typedef long long ll;
int main() {
	int T, n, h[10];
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		scanf("%d", &n);
		printf("Case #%d: ", C);
		if (n > 0) {
			int x = 0, s = 0;
			memset(h, 0, sizeof(h));
			while (s < 10) {
				int t = x += n;
				while ((t > 0)) {
					int k = t%10;
					s += 1^h[k];
					h[k] = 1;
					t /= 10;
				}
			}
			printf("%d\n", x);
		} else  puts("INSOMNIA");
	}
}
