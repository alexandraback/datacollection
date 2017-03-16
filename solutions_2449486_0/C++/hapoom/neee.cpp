#include<stdio.h>
#include<memory.h>

FILE *in = fopen("B-small-attempt3.in","r");
FILE *out= fopen("output.in","w");

int T, N, M, sw, sw1, min, x, y;
int map[110][110];


int main()
{
	int i, j, k, kk;
	fscanf(in, "%d" ,&T);
	for(kk = 1; kk <=T; kk++){
		memset(map, 0, sizeof(map));
		fscanf(in, "%d%d", &N, &M);
		for(i = 1; i <= N; i++){
			for(j = 1; j <= M; j++){
				fscanf(in, "%d", &map[i][j]);
			}
		}
		for(i = 1; i <= N; i++){
			for(j = 1; j <= M; j++){
				sw = sw1 = 0;
				for(k = 1; k <= N; k++){
					if(map[k][j] > map[i][j]){
						sw = 1;
					}
				}
				for(k = 1; k <= M; k++){
					if(map[i][k] > map[i][j]){
						sw1 = 1;
					}
				}
				if(sw == 1 && sw1 == 1){
					break;
				}
			}
			
			if(sw == 1 && sw1 == 1){
				break;
			}
		}
		if(sw == 1 && sw1 == 1){
			fprintf(out, "Case #%d: NO\n", kk);
		}
		else{
			fprintf(out, "Case #%d: YES\n", kk);
		}
	}
	return 0;
}