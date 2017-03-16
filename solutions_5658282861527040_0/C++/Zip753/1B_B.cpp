#include <cstdio>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int qwe;
	scanf("%d", &qwe);
	for (int tt = 1; tt <= qwe; tt++) {
		int ans = 0;
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++) {
				int x = (i & j);
				if (x < k)
					ans++;
			}
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}
