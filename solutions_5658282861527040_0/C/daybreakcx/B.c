#include <stdio.h>

int ti, tn, a, b, k, i, j, ans;

int
main() {
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		printf("Case #%d: ", ti);
		scanf("%d%d%d", &a, &b, &k);
		for (ans = i = 0; i < a; ++i)
			for (j = 0; j < b; ++j)
				if ((i & j) < k)
					++ans;
		printf("%d\n", ans);
	}
	return 0;
}
