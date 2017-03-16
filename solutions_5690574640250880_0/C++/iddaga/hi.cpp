#include <stdio.h>
#include <memory.h>
#define MX 50
int R, C, M;
int d[MX][MX];
FILE *out;
void print()
{
	int i, j;
	
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			if (i == 0 && j == 0)
				fprintf(out,"c");
			else if (d[i][j])
				fprintf(out,".");
			else fprintf(out,"*");
		}
		fprintf(out,"\n");
	}
}
int main()
{
	FILE *in=fopen("input.txt","r");
	out=fopen("output.txt","w");
	int t, T, i, j, k, ph;
	
	fscanf(in,"%d",&T);
	for (t = 1; t <= T; t++) {
		printf("%d / %d\n",t,T);
		fprintf(out,"Case #%d:\n",t);
		fscanf(in,"%d%d%d",&R,&C,&M);
		M = R*C-M;
		if (R == 1 || C == 1) {
			k = 0;
			for (i = 0; i < R; i++) {
				for (j = 0; j < C; j++) {
					if (k == 0) fprintf(out,"c");
					else if (k < M) fprintf(out,".");
					else fprintf(out,"*");
					k++;
				}
				fprintf(out,"\n");
			}
			continue;
		}
		// R >= 2 && C >= 2
		if (M == 1) {
			for (i = 0; i < R; i++) {
				for (j = 0; j < C; j++) {
					if (i == 0 && j == 0)
						fprintf(out,"c");
					else fprintf(out,"*");
				}
				fprintf(out,"\n");
			}
		}
		else if (M == 2 || M == 3 || M == 5 || M == 7)
			fprintf(out,"Impossible\n");
		else if (M % 2 == 0) {
			// M >= 4 && R >= 2 && C >= 2
			memset(d,0,sizeof(d));
			k = 0;
			for (i = 0; i < R; i += 2) {
				if (i+1 < R) {
					d[i][0] = d[i][1] = 1;
					k += 2; if (k == M) print();
					d[i+1][0] = d[i+1][1] = 1;
					k += 2; if (k == M) print();
					for (j = 2; j < C; j++) {
						d[i][j] = d[i+1][j] = 1;
						k += 2; if (k == M) print();
					}
				}
				else {
					for (j = 0; j+1 < C; j += 2) {
						d[i][j] = d[i][j+1] = 1;
						k += 2; if (k == M) print();
					}
				}
			}
		}
		else {
			if (R == 2 || C == 2) {
				fprintf(out,"Impossible\n");
				continue;
			}
			// M >= 9 && R >= 3 && C >= 3
			memset(d,0,sizeof(d));
			d[0][0] = d[0][1] = d[0][2] = 1;
			k = 3;
			for (i = 0; i < R; i += 2) {
				if (i+2 < R) {
					d[i+1][0] = d[i+1][1] = 1;
					k += 2; if (k == M) print();
					d[i+2][0] = d[i+2][1] = 1;
					k += 2; if (k == M) print();
					d[i+1][2] = d[i+2][2] = 1;
					k += 2; if (k == M) print();
					for (j = 3; j < C; j++) {
						d[i][j] = d[i+1][j] = 1;
						k += 2; if (k == M) print();
					}
				}
				else {
					for (j = 3; j+1 < C; j += 2) {
						d[i][j] = d[i][j+1] = 1;
						k += 2; if (k == M) print();
					}
					if (i+1 < R) {
						if (d[R-2][C-1]) {
							for (j = 0; j+1 < C; j += 2) {
								d[i+1][j] = d[i+1][j+1] = 1;
								k += 2; if (k == M) print();
							}
						}
						else {
							for (j = 0; j+1 < C-1; j += 2) {
								d[i+1][j] = d[i+1][j+1] = 1;
								k += 2; if (k == M) print();
							}
							d[R-2][C-1] = d[R-1][C-2] = 1;
							k += 2; if (k == M) print();
						}
					}
				}
			}
		}
	}
	fclose(in);
	fclose(out);
	return 0;
}