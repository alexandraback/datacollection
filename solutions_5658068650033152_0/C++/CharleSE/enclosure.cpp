#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

int N, M, K;
int stones;
FILE *in = fopen("C-small-attempt3.in", "r");
FILE *out = fopen("C.out", "w");

int main(){
	int T, tests;
	fscanf(in, "%d", &T);
	tests = T;
	while (T--){
		stones = 0;
		fscanf(in, "%d %d %d", &N, &M, &K);
		fprintf(out, "Case #%d: ", tests - T);
		if (K <= 4) fprintf(out, "%d\n", K);
		else if (N <= 2 || M <= 2) fprintf(out, "%d\n", K);
		else{
			if (K >= N * M - 4) fprintf(out, "%d\n", 2 * (N - 2) + 2 * (M - 2) + 4 - (N * M - K));
			else{
				int x, y;
				for (int i = 2; i <= N + M - 4, stones == 0; i++){
					x = 1; y = i - 1;
					while (y > M - 2 && y >= 1) {
						x++; y--;
					}
					while (x <= N - 2 && y >= 1){
						if (2 * x + 2 * y + x * y >= K){
							if (2 * x + 2 * y + x * y - 2 >= K){
								stones = 2 * x + 2 * y - 1;
								fprintf(out, "%d\n", stones);
								break;
							}
							stones = 2 * x + 2 * y;
							fprintf(out, "%d\n", 2 * x + 2 * y);
							break;
						}
						else if (2 * x + 2 * y + x * y + 1 == K){
							stones = 2 * x + 2 * y + 1;
							fprintf(out, "%d\n", stones);
							break;
						}
						else {
							x++; y--;
						}
					}
				}
			}
		}
	}
	fcloseall();
	return 0;
}