#include <stdio.h>
FILE* input = fopen("input.txt", "r");
FILE* output = fopen("output.txt", "w");
int t;
int r, c, m;
int p[60][60] = {0,};
int dir[8][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
char ans[60][60] = {0,};
int ch = 0;
void play(){
	int q[60][60] = {0,};
	int i, j, k, l, cc = 0;
	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			q[i][j] = p[i][j];
			if(p[i][j] > 0) cc++;
		}
	}
	if(cc > r*c-m) return ;
	if(cc == r*c-m){
		for(i = 0; i < r; i++){
			for(j = 0; j < c; j++){
				if(p[i][j] == 0) ans[i][j] = '*';
				else ans[i][j] = '.';
			}
		}
		ch = 1;
		return ;
	}
	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			if(p[i][j] == 1){
				p[i][j] = 2;
				for(k = 0; k < 8; k++){
					int xx = i + dir[k][0], yy = j + dir[k][1];
					if(xx >= 0 && xx < r && yy >= 0 && yy < c && p[xx][yy] == 0) p[xx][yy] = 1;
				}
				play();
				for(k = 0; k < r; k++) for(l = 0; l < c; l++) p[k][l] = q[k][l];
				if(ch == 1) return ;
			}
		}
	}
}
int main(){
	fscanf(input, "%d", &t);
	int tt;
	for(tt = 1; tt <= t; tt++){
		fscanf(input, "%d%d%d", &r, &c, &m);
		fprintf(output, "Case #%d:\n", tt);
		int i, j;
		for(i = 0; i < r; i++){
			for(j = 0; j < c; j++){
				p[i][j] = 1;
				play();
				p[i][j] = 0;
				if(ch == 1){
					ans[i][j] = 'c';
					break;
				}
			}
			if(ch == 1) break;
		}
		if(ch == 1){
			for(i = 0; i < r; i++){
				for(j = 0; j < c; j++){
					fprintf(output, "%c", ans[i][j]);
				}
				fprintf(output, "\n");
			}
		}
		else fprintf(output, "Impossible\n");
		ch = 0;
	}
	return 0;
}