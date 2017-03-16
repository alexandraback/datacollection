#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a;
	int b;
	int s;	// stars earned at this level
} LEVEL;

int main() {
	int T, t, N, n, c, rating, passed, ans;
	int maxn, maxv;
	int bad = 0;
	LEVEL* l;

	scanf("%d", &T);
	for(t=1; t<=T; t++) {
		scanf("%d", &N);
		l = calloc(N, sizeof(LEVEL));
		for(n=0; n<N; n++) {
			scanf("%d %d", &(l[n].a), &(l[n].b));
			l[n].s = 0;
		}
		rating = 0;
		bad = 0;
		ans = 0;
		while(rating<2*N) {
			passed = 0;
			for(n=0; n<N; n++) {
				if(l[n].s>=2) continue;
				if(l[n].b <= rating) {
					//printf("Playing %d at 2 stars\n", n+1);
					rating+= 2 - l[n].s;
					l[n].s+= 2 - l[n].s;
					passed = 1;
					ans++;
					break;
				}
			}
			if(passed) continue;
			maxn = -1;
			maxv = -1;
			for(n=0; n<N; n++) {
				if(l[n].s>=1) continue;
				if(l[n].a>rating) continue;
				if(l[n].b>maxv) {
					maxv = l[n].b;
					maxn = n;
				}
			}
			if(maxn<0) bad++;
			else {
				//printf("Playing %d at 1 star\n", maxn+1);
				rating+= 1;
				l[maxn].s = 1;
				ans++;
			}
			if(bad>=3) break;
		}
		if(bad) printf("Case #%d: Too Bad\n", t);
			else printf("Case #%d: %d\n", t, ans);
		free(l);
	}
}
