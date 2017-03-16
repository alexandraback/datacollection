#include <cstdio>

int R, N, M, K;
int cnt[15];
//int val[4][4][4][4];

bool chk(int a, int b, int c, int d) {
	//printf("%d %d %d %d\n", a, b, c, d);
	return (a == 1) || 
	       (a == b) ||
		   (a == c) ||
		   (a == d) || 
		   (a == b * c) ||
		   (a == c * d) ||
		   (a == b * d) ||
		   (a == b * c * d);
}

int main() {
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("C-small-1-attempt0.out", "w", stdout);
	scanf("%*d");
	scanf("%d%d%d%d", &R, &N, &M, &K);
	puts("Case #1:");
	for(int z = 0; z < R; ++z) {
		int i, j, k;
		int jiz[7];
		bool fnd = false;
		for(int t = 0; t < 7; ++t)
			scanf("%d", &jiz[t]);
		for(i = 2; i <= 5 && !fnd; ++i){
			for(j = 2; j <= 5 && !fnd; ++j) {
				for(k = 2; k <= 5 && !fnd; ++k) {
					fnd = true;
					for(int p = 0; p < 7 && fnd; ++p)
						if(!chk(jiz[p], i, j, k)) fnd = false;
					if(fnd) break;
				}
				if(fnd) break;
			}
			if(fnd) break;
		}
		printf("%d%d%d\n", i, j, k);
	}
}
