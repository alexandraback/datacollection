#include <cstdio>
#include <cstring>

int main () {
	int cas;
	scanf("%d", &cas);
	for (int i = 1; i <= cas; i++) {
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		int ans = 0;
		for (int x = 0; x < a; x++) {
			for (int y = 0; y < b; y++)
				if ((x&y) < k)
					ans++;
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}
