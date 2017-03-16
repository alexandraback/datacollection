#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#define REP(I,N) for(int I = 0; I < N; I++)
using namespace std;
char bd[5][5];

int main(int argc, char *argv[])
{
	int T;
	scanf("%d\n", &T);
	REP(t, T) {
		bool filled = true;
		REP(i, 4) {
			REP(j, 4) {
				scanf("%c", &bd[i][j]);
				if(bd[i][j] == '.') filled = false;
			}
			scanf("\n");
		}

		char plrow,plcol;
		bool winx=false, wino=false;
		REP(i, 4) {
			plrow = bd[0][i]; plcol = bd[i][0];
			if(plrow == 'T') plrow = bd[1][i];
			if(plcol == 'T') plcol = bd[i][1];
			bool wr = true, wc = true;
			if(plrow == '.') wr = false;
			if(plcol == '.') wc = false;
			REP(j, 4) {
				if(bd[i][j] == '.' || (bd[i][j] != plcol && bd[i][j] != 'T')) wc = false;
				if(bd[j][i] == '.' || (bd[j][i] != plrow && bd[j][i] != 'T')) wr = false;
			}
			if(wr) {
				if(plrow == 'X') winx = true;
				if(plrow == 'O') wino = true;
			}
			if(wc) {
              	if(plcol == 'X') winx = true;
				if(plcol == 'O') wino = true;
			}
		}
		char pld1 = bd[0][0]; char pld2 = bd[0][3];
		if(pld1 == 'T') pld1 = bd[1][1];
		if(pld2 == 'T') pld2 = bd[1][2];
		bool wd1 = true, wd2 = true;
		if(pld1 == '.') wd1 = false;
		if(pld2 == '.') wd2 = false;
		REP(i, 4) {
			if(bd[i][i] == '.' || (bd[i][i] != pld1 && bd[i][i] != 'T')) wd1 = false;
			if(bd[i][3-i] == '.' || (bd[i][3-i] != pld2 && bd[i][3-i] != 'T')) wd2 = false;
		}
		if(wd1) {
			if(pld1 == 'X') winx = true; else wino = true;
		}
		if(wd2) {
			if(pld2 == 'X') winx = true; else wino = true;
		}
		
		printf("Case #%d: ", t+1);
		if(winx) printf("X won");
		else if(wino) printf("O won");
		else if(filled) printf("Draw");
		else printf("Game has not completed");
		printf("\n");
		scanf("\n");
 	}
    return 0;
}
