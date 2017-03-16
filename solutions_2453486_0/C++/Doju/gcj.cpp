#include <stdio.h>
FILE* input = fopen("input.txt", "r");
FILE* output = fopen("output.txt", "w");
int a;
char p[5][5] = {0,};
int main(){
	fscanf(input, "%d", &a);
	int t;
	for(t = 1; t <= a; t++){
		fprintf(output, "Case #%d: ", t);
		int i, j;
		for(i = 0; i < 4; i++) fscanf(input, "%s", &p[i]);
		int cmpl = 0;
		for(i = 0; i < 4; i++) for(j = 0; j < 4; j++) if(p[i][j] == '.') cmpl = 1;
		int win = 0;
		for(i = 0; i < 4; i++){
			int c1 = 0, c2 = 0;
			for(j = 0; j < 4; j++){
				if(p[i][j] == 'O') c1++;
				if(p[i][j] == 'X') c2++;
				if(p[i][j] == 'T'){
					c1++;
					c2++;
				}
			}
			if(c1 == 4) win = 1;
			if(c2 == 4) win = 2;
		}
		for(i = 0; i < 4; i++){
			int c1 = 0, c2 = 0;
			for(j = 0; j < 4; j++){
				if(p[j][i] == 'O') c1++;
				if(p[j][i] == 'X') c2++;
				if(p[j][i] == 'T'){
					c1++;
					c2++;
				}
			}
			if(c1 == 4) win = 1;
			if(c2 == 4) win = 2;
		}
		int c1 = 0, c2 = 0;
		for(i = 0; i < 4; i++){
			if(p[i][i] == 'O') c1++;
			if(p[i][i] == 'X') c2++;
			if(p[i][i] == 'T'){
				c1++;
				c2++;
			}
		}
		if(c1 == 4) win = 1;
		if(c2 == 4) win = 2;
		c1 = 0;
		c2 = 0;
		for(i = 0; i < 4; i++){
			if(p[i][3-i] == 'O') c1++;
			if(p[i][3-i] == 'X') c2++;
			if(p[i][3-i] == 'T'){
				c1++;
				c2++;
			}
		}
		if(c1 == 4) win = 1;
		if(c2 == 4) win = 2;
		if(win == 1) fprintf(output, "O won\n");
		else if(win == 2) fprintf(output, "X won\n");
		else if(cmpl == 1) fprintf(output, "Game has not completed\n");
		else fprintf(output, "Draw\n");
	}
	return 0;
}