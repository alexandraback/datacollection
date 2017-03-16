#include<stdio.h>
#include<memory.h>

FILE *in = fopen("A-large.in","r");
FILE *out= fopen("output.in","w");

int T;
char map[5][5];


int main()
{
	int kk, i, j, k, cntX, cntO, cntDot, N, sw;
	fscanf(in, "%d",&T);
	for(kk = 1; kk <= T; kk++){
		cntDot = 0;
		for(i = 0; i <= 3; i++){
			fscanf(in, "%s", &map[i]);
			if(map[i][0] =='.' || map[i][1] == '.' || map[i][2] == '.' || map[i][3] == '.') cntDot = 1;
		}
		for(i = 0; i <= 3; i++){
			cntX = cntO = N = sw = 0;
			for(j = 0; j <= 3; j++){
				if(map[i][j] == 'X') cntX++;
				if(map[i][j] == 'O') cntO++;
				if(map[i][j] == 'T') N = 1;
			}
			if(cntX == 4 || cntX + N == 4){
				sw = 1;
				fprintf(out, "Case #%d: X won\n", kk);
				break;
			}
			if(cntO == 4 || cntO + N == 4){
				sw = 1;
				fprintf(out, "Case #%d: O won\n", kk);
				break;
			}

			cntX = cntO = N = sw = 0;
			for(j = 0; j <= 3; j++){
				if(map[j][i] == 'X') cntX++;
				if(map[j][i] == 'O') cntO++;
				if(map[j][i] == 'T') N = 1;
			}
			if(cntX == 4 || cntX + N == 4){
				sw = 1;
				fprintf(out, "Case #%d: X won\n", kk);
				break;
			}
			if(cntO == 4 || cntO + N == 4){
				sw = 1;
				fprintf(out, "Case #%d: O won\n", kk);
				break;
			}
		}
		if(sw == 1)continue;
		cntX = cntO = N = 0;
		for(j = 0; j <= 3; j++){
			if(map[j][j] == 'X') cntX++;
			if(map[j][j] == 'O') cntO++;
			if(map[j][j] == 'T') N = 1;
		}
		if(cntX == 4 || cntX + N == 4){
			fprintf(out, "Case #%d: X won\n", kk);
			continue;
		}
		if(cntO == 4 || cntO + N == 4){
			fprintf(out, "Case #%d: O won\n", kk);
			continue;
		}

		
		cntX = cntO = N = 0;
		for(j = 0; j <= 3; j++){
			if(map[j][3 - j] == 'X') cntX++;
			if(map[j][3 - j] == 'O') cntO++;
			if(map[j][3 - j] == 'T') N = 1;
		}
		if(cntX == 4 || cntX + N == 4){
			fprintf(out, "Case #%d: X won\n", kk);
			continue;
		}
		if(cntO == 4 || cntO + N == 4){
			fprintf(out, "Case #%d: O won\n", kk);
			continue;
		}

		if(cntDot ==0)
			fprintf(out, "Case #%d: Draw\n", kk);
		else
			fprintf(out, "Case #%d: Game has not completed\n", kk);
	}
	return 0;
}