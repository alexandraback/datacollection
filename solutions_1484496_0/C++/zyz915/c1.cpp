#include <cstdio>
#include <cstring>

const int N = 1010;
int same[100000 * 20 + 1], n, a[N], f[1 << 20];

void print(int p) {
	int last = -1;
	for (int i = 0; i < n; i++)
		if (p & (1 << i)) {
			if (last != -1) putchar(' ');
			printf("%d", a[i]);
			last = i;
		}
	printf("\n");
}
int main() {
	int tt;
	scanf("%d", &tt);
	memset(same, -1, sizeof(same));
	for (int cas = 1; cas <= tt; cas++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		memset(f, 0, sizeof(f));
		for (int i = 0; i < (1 << n); i++)
			for (int j = 0; j < n; j++)
				if (i & (1 << j)) f[i] += a[j];
		for (int i = 1; i < (1 << n); i++)
			same[f[i]] = i;
		int p = -1;
		for (int i = 1; i < (1 << n); i++)
			if (same[f[i]] != -1 && same[f[i]] != i) {
				p = i; break;
			}
		printf("Case #%d:\n", cas);
		if (p == -1) {
			printf("Impossible\n");
		} else {
			print(p);
			print(same[f[p]]);
		}
		for (int i = 0; i < (1 << n); i++)
			same[f[i]] = -1;
	}
	return 0;
}