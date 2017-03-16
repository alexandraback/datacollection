#include <stdio.h>
#include <string.h>

int t, a, b, k;

int main() {
	int cas = 0;
	scanf("%d", &t);
	while (t--) {
		int ans = 0;
		scanf("%d%d%d", &a, &b, &k);
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if ((i&j) < k)
					ans++;
			}
		}
		printf("Case #%d: %d\n", ++cas, ans);
	}
	return 0;
}