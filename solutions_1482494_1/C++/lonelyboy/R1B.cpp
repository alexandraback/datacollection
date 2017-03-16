#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int (*CMP)(const void*, const void*);
int cmp(int *a, int *b) {
	if(a[1] - b[1]) return a[1] - b[1];
	return a[0] - b[0];
}
int n, in[2000][2], mark[2000];

int solve() {
	qsort(in, n, sizeof(in[0]), (CMP)cmp);
	memset(mark, 0, sizeof(mark));
	int now = 0, ret = 0;
	while(1) {
		if(now == n * 2) break;
		int nxt = -1;
		for(int i = 0; i < n; ++i) {
			if(mark[i] != 0) continue;
			if(in[i][1] <= now) {
				nxt = i;
				break;
			}
		}
		
		if(nxt != -1) {
			//printf("nxt2 %d\n", nxt);
			now += 2;
			mark[nxt] = 2;
			++ret;
			continue;
		}
		
		for(int i = 0; i < n; ++i) {
			if(mark[i] == 2) continue;
			if(in[i][mark[i]] <= now) {
				nxt = i;
				if(mark[i] == 1) break;
			}
			/*
			if(mark[i] == 0) {
				if(in[i][0] <= now) {
					nxt = i;
					break;
				}
			} else if(mark[i] == 1) {
				if(in[i][1] <= now) {
					nxt = i;
					break;
				}
			}
			*/
		}
		
		if(nxt != -1) {
			//printf("nxt1 %d\n", nxt);
			now += 1;
			++mark[nxt];
			++ret;
			continue;
		}
		//printf("n %d\n", now);
		if(now != n * 2) return -1;
	}
	return ret;
}

int main() {
	int t;
	freopen("B-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	for(int i = 0; i < t; ++i) {
		scanf("%d", &n);
		for(int j = 0; j < n; ++j) {
			scanf("%d %d", in[j], in[j] + 1);
		}
		printf("Case #%d: ", i + 1);
		int ans = solve();
		if(ans < 0) puts("Too Bad");
		else printf("%d\n", ans);
		//printf("Case #%d: %\n", i + 1, solve());
	}
	//scanf("%d");
}
