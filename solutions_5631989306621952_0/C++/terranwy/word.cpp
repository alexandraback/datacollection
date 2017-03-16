#include <cstdio>
#include <cstring>

const int maxlen = 1100;

int casei, cases;
char st[maxlen], ans[maxlen];

int main() {
	scanf("%d", &cases);
	for (casei = 1; casei <= cases; ++casei) {
		scanf(" %s", st);
		int len = strlen(st);
		int l = 0, r = 1;
		ans[0] = st[0];
		for (int i = 1; i < len; ++i) {
			if (st[i] >= ans[l]) {
				if (l == 0) l = maxlen - 1;
				else --l;
				ans[l] = st[i];
			}
			else ans[r++] = st[i];
		}
		printf("Case #%d: ", casei);
		while (l != r) {
			printf("%c", ans[l]);
			if (++l == maxlen) l = 0;
		}
		printf("\n");
	}
	return 0;
}
