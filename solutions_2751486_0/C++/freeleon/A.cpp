#include <cstdio>
#include <cstring>

const int MAXN = 1000006;

int n, ls;
char str[MAXN];

int is_cons(char c) {
	switch (c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return 0;
		default:
			return 1;
	}
	return 1;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int run = 1; run <= T; run++) {
		scanf("%s%d", str, &n);
		ls = strlen(str);
		int l = 0, r = 0, co = 0, cs = 0;
		int cnt = 0;

		if ( is_cons(str[0]) ) co++;
		else cs = 1;

		while (r+1 < ls && co < n) {
			r++;
			if ( is_cons(str[r]) ) {
				co++;
			} else {
				co = 0;
				cs = r + 1;
			}
		}

		if (co == n) cnt += ls - r;

		while (l < ls && r < ls) {
			if ( is_cons(str[l]) && cs <= l) {
				co--;
			}
			l++;
			while (r+1 < ls && co < n) {
				r++;
				if ( is_cons(str[r]) ) {
					co++;
				} else {
					co = 0;
					cs = r + 1;
				}
			}
			if (co == n) cnt += ls - r;
		}
		printf("Case #%d: %d\n", run, cnt);
	}
	return 0;
}
