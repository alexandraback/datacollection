#include<stdio.h>
#include<string.h>
#include<memory.h>

FILE *in = fopen("B-small-attempt1.in", "r");
FILE *out = fopen("output.txt", "w");

int queue[2000000][5], head, tail;
int map[3000][3000], an;
int ans[1000];

int main()
{
	int T, cn, X, Y, i, j, nx, ny, jump;
	fscanf(in, "%d", &T);
	for(cn = 1; cn <= T; cn++){
		fscanf(in, "%d%d", &X, &Y);
		fprintf(out, "Case #%d: ", cn);
		if(X >= 0){
			for(i = 1; i <= X; i++){
				fprintf(out, "WE");
			}
		}
		else{
			X *= -1;
			for(i = 1; i <= X; i++){
				fprintf(out, "EW");
			}
		}
		if(Y >= 0){
			for(i = 1; i <= Y; i++){
				fprintf(out, "SN");
			}
		}
		else{
			Y *= -1;
			for(i = 1; i <= Y; i++){
				fprintf(out, "NS");
			}
		}
		fprintf(out, "\n");
	}
	return 0;
}