#include <cstdio>
#include <map>
using namespace std;
const int MAXN = 510;
int s[MAXN];
map<int, int> ma;
int main() {
	int testnum, n;
	scanf("%d", &testnum);
	for (int test = 1;test <= testnum;test++) {
		scanf("%d", &n);
		for (int i = 0;i < n;i++) scanf("%d", &s[i]);
		printf("Case #%d:\n", test);
		bool suc = false;
		ma.clear();
		for (int i = 0;i < (1 << n) && !suc;i++) {
			int tmp = i, c = 0, S = 0;
			while (tmp) {
				if (tmp & 1) S += s[c];
				tmp >>= 1; c++;
			}
			if (ma.count(S)) {
				bool first = true;
				tmp = i; c = 0;
				while (tmp) {
					if (tmp & 1) {
						if (first) first = false; else putchar(' ');
						printf("%d", s[c]);
					}
					tmp >>= 1; c++;
				}
				puts("");
				first = true; tmp = ma[S]; c = 0;
				while (tmp) {
					if (tmp & 1) {
						if (first) first = false; else putchar(' ');
						printf("%d", s[c]);
					}
					tmp >>= 1; c++;
				}
				puts("");
				suc = true;
			}
			ma[S] = i;
		}
		if (!suc) puts("Impossible");
	}
	return 0;
}