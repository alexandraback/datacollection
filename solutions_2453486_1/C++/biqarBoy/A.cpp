#include <stdio.h>
#include <string.h>

const int MAX = 10;

char str[MAX][MAX];

int main() {
	freopen("A-large.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);

	int i, j, k;
	int test, t = 0;
	int xc, oc, tc, dc;
	int flg, dflg, xflg, oflg;;

	scanf("%d", &test);
	while(test--) {
		dflg = 0;
		for(i=0; i<4; i+=1) {
			scanf("%s", &str[i]);
			for(j=0; j<4; j+=1) {
				if(str[i][j] == '.') dflg = 1;
			}
		}
		
		flg = -1;
		for(i=0; i<4; i+=1) {			//Row & Col Mejor order
			xc = oc = tc = dc = 0;
			for(j=0; j<4; j+=1) {		//Col
				if(str[i][j] == 'X') xc += 1;
				if(str[i][j] == 'O') oc += 1;
				if(str[i][j] == 'T') tc += 1;
				if(str[i][j] == '.') dc += 1;
			}
			if(xc==4 || (xc==3 && tc==1)) {
				flg = 1;
				break;
			}
			if(oc==4 || (oc==3 && tc==1)) {
				flg = 0;
				break;
			}

			xc = oc = tc = dc = 0;
			for(j=0; j<4; j+=1) {		//Row
				if(str[j][i] == 'X') xc += 1;
				if(str[j][i] == 'O') oc += 1;
				if(str[j][i] == 'T') tc += 1;
				if(str[j][i] == '.') dc += 1;
			}
			if(xc==4 || (xc==3 && tc==1)) {
				flg = 1;
				break;
			}
			if(oc==4 || (oc==3 && tc==1)) {
				flg = 0;
				break;
			}
		}

		if(flg != -1) {
			if(flg == 0) printf("Case #%d: O won\n", ++t);
			if(flg == 1) printf("Case #%d: X won\n", ++t);
			continue;
		}

		xc = oc = tc = dc = 0;
		for(i=0; i<4; i+=1) {			//Diagonal 1
			if(str[i][i] == 'X') xc += 1;
			if(str[i][i] == 'O') oc += 1;
			if(str[i][i] == 'T') tc += 1;
			if(str[i][i] == '.') dc += 1;
		}
		if(xc==4 || (xc==3 && tc==1)) flg = 1;
		if(oc==4 || (oc==3 && tc==1)) flg = 0;

		if(flg != -1) {
			if(flg == 0) printf("Case #%d: O won\n", ++t);
			if(flg == 1) printf("Case #%d: X won\n", ++t);
			continue;
		}

		xc = oc = tc = dc = 0;
		for(i=0; i<4; i+=1) {			//Diagonal 2
			if(str[i][3-i] == 'X') xc += 1;
			if(str[i][3-i] == 'O') oc += 1;
			if(str[i][3-i] == 'T') tc += 1;
			if(str[i][3-i] == '.') dc += 1;
		}
		if(xc==4 || (xc==3 && tc==1)) flg = 1;
		if(oc==4 || (oc==3 && tc==1)) flg = 0;

		if(flg != -1) {
			if(flg == 0) printf("Case #%d: O won\n", ++t);
			if(flg == 1) printf("Case #%d: X won\n", ++t);
			continue;
		}

		if(dflg == 0) printf("Case #%d: Draw\n", ++t);
		else printf("Case #%d: Game has not completed\n", ++t);
	}
	return 0;
}