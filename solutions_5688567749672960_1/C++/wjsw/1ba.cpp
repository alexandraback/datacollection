#include <stdio.h>
#include <string.h>

char s[40];
int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		scanf("%s", s);
		int l = strlen(s);
		for (int i = 0; i < l; ++i) s[i] -= '0';
		long long r = 0;
		if (s[l-1] == 0){
			++r;
			int ii = l -1;
			while (s[ii] == 0) {
				--ii;
			}
			if (ii == 0 && s[ii] == 1) {
				--l;
				memset(s, 9, l);
			} else {
				--s[ii];
				memset(s + ii + 1, 9, l);
			}
		}
		while (l > 0)
		{
			if (l == 1){
				r += s[0];
				break;
			}
			long long m = 1;
			bool f = 0;
			for (int i = 0; i + i < l; ++i){
				int mm = (i == 0 ? 1 : 0);
				if (i + i + 1 == l) {
					r += (s[i] - mm) * m;
				} else {
					if (s[i] != mm) f = 1;
					r += (s[i] + s[l - i - 1] - mm - mm) * m;
				}
				m *= 10;
			}
			r += 2 + f;
			--l;
			memset(s, 9, l);
		}
		printf("Case #%d: %lld\n", tt, r);
	}
}
