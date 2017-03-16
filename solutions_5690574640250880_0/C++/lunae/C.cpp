#include <cstdio>
#include <cstring>
int main() {
	int T;
	scanf("%d",&T);
	for (int tc=1; tc<=T; tc++) {
		int R, C, M;
		scanf("%d%d%d",&R,&C,&M);
		printf("Case #%d:\n",tc);
		if (R==1) {
			for (int x=0; x<C; x++) {
				if(x==0)printf("c"); else
				if(x<C-M)printf("."); else
				printf("*");
			}
			printf("\n");
		} else
		if (C==1) {
			for (int y=0; y<R; y++) {
				if(y==0)printf("c\n"); else
				if(y<R-M)printf(".\n"); else
				printf("*\n");
			}
		} else {
			if (M==R*C-1) {
				for (int y=0; y<R; y++) {
					for (int x=0; x<C; x++) {
						if (y==0 && x==0) printf("c");
						else printf("*");
					}
					printf("\n");
				}
				continue;
			}
			bool ok=false;
			for (int h=1; h<R && !ok; h++) {
				for (int w=1; w<C && !ok; w++) {
					//int add = h+w+1;
					//int base = h+w-1;
					//int full = h*w;
					// [add+base .. add+full] = [2*(h+w) .. (h+1)*(w+1)]
					if (2*(h+w) <= R*C-M && R*C-M <= (h+1)*(w+1)) {
						static bool used[105][105];
						memset(used,0,sizeof used);
						int place = R*C-M - (h+w+1);
						for (int y=0; y<h; y++) {
							for (int x=0; x<w; x++) {
								if (y==0 || x== 0) {
									used[y][x] = true;
								}
							}
						}
						int cnt=h+w-1;
						for (int y=1; y<h; y++) {
							for (int x=1; x<w; x++) {
								if (cnt < place) {
									used[y][x] = true;
									cnt++;
								}
							}
						}
						for (int y=R-1; y>=0; y--) {
							for (int x=C-1; x>=0; x--) {
								if (used[y][x]) {
									used[y+1][x] = true;
									used[y][x+1] = true;
									used[y+1][x+1] = true;
								}
							}
						}
						for (int y=0; y<R; y++) {
							for (int x=0; x<C; x++) {
								if (y==0 && x==0) printf("c"); else
								if (used[y][x]) printf("."); else
								printf("*");
							}
							printf("\n");
						}
						ok=true;
						break;
					}
				}
			}
			if (!ok) {
				printf("Impossible\n");
			}
		}
	}
}
