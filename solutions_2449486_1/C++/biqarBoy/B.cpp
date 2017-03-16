#include <stdio.h>
#include <string.h>

const int MAX = 1005;

int r, c;
int fld[MAX][MAX], rh[MAX];


int main() {
	freopen("B-large.in", "r", stdin);
	//freopen("B-large.out", "w", stdout);

	int i, j, k;
	int test, t = 0;
	int flg;
	
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d", &r, &c);

		for(i=0; i<r; i+=1) {
			rh[i] = 0;
			for(j=0; j<c; j+=1) {
				scanf("%d", &fld[i][j]);
				if(fld[i][j] > rh[i]) rh[i] = fld[i][j];
			}
		}

		flg = 1;
		for(i=0; i<r && flg; i+=1) {
			for(j=0; j<c && flg; j+=1) {
				if(fld[i][j] < rh[i]) {
					for(k=0; k<r && flg; k+=1) {
						if(fld[k][j] > fld[i][j]) {
							flg = 0;
							break;
						}
					}
				}
			}
		}
		if(flg) printf("Case #%d: YES\n", ++t);
		else printf("Case #%d: NO\n", ++t);
	}
	return 0;
}