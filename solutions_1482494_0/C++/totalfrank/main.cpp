#include <stdio.h>
#include <string.h>

#define MAXN 1010

int a[MAXN], b[MAXN];
int done[MAXN];

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("out.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) scanf("%d%d", a + i, b + i);
		memset(done, 0, sizeof(done));
		int res = 0, rem = n, stars = 0;
		bool solved = true;
		while(rem > 0) {
			++res;
			bool ok = false;
			int next = -1;
			for(int i = 0; i < n && !ok; ++i)
				if(done[i] != 2 && stars >= b[i]) {
					ok = true;
					next = i;
					break;
				}
			if(ok) {
				stars += 2 - done[next];
				done[next] = 2;
				--rem;
			} else {
				int curr = -1, next = -1;
				for(int i = 0; i < n; ++i)
					if(done[i] == 0 && stars >= a[i]) {
						if(b[i] > curr) {
							curr = b[i];
							next = i;
						}
					}
				if(next == -1) {
					solved = false;
					break;
				}
				stars += 1;
				done[next] = 1;
			}
		}
		printf("Case #%d: ", cas);
		if(!solved) puts("Too Bad");
		else printf("%d\n", res);
	}
	return 0;
}
