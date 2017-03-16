#include <stdio.h>
#define MN 111
int N, M, c[MN][MN], num[MN];
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for (int s = 1; s <= T; s++) {
		scanf("%d%d",&N,&M);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				scanf("%d",&c[i][j]);
				num[c[i][j]] = 1;
			}
		}
		int sw;
		for (int x = 1; x <= 100; x++) {
			if (!num[x]) continue;
			sw = 1;
			for (int i = 1; i <= N; i++) {
				sw = 1;
				for (int j = 1; j <= M; j++) {
					if (c[i][j] == x) {
						sw = 1;
						int cnt = 0;
						for (int k = 1; k <= M; k++)
							cnt += ((c[i][k]==0)||(c[i][k]==x));
						if (cnt == M) {
							for (int k = 1; k <= M; k++)
								c[i][k] = 0;
							sw = 0;
						} else {
							cnt = 0;
							for (int k = 1; k <= N; k++)
								cnt += ((c[k][j]==0)||(c[k][j]==x));
							if (cnt == N) {
								for (int k = 1; k <= N; k++)
									c[k][j] = 0;
								sw = 0;
							}
							if (sw == 1) {
								sw = 2;
								break;
							}
						}
					}
				}
				if (sw == 2) break;
			}
			if (sw == 2) break;
		}
		printf("Case #%d: ",s);
		if (sw == 2) printf("NO\n");
		else printf("YES\n");
	}
	fcloseall();
	return 0;
}