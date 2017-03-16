#include <stdio.h>
#define MAX 30
#define INF 2147483647
int resposta[MAX];

int main(){
	FILE * ent;
	FILE * saida;
	ent = fopen("entrada1.txt", "r");
	saida = fopen("saida1.txt", "w");
	int T, ind;
	int R, C, W, resp, i, j;
	int value;
	fscanf(ent, "%d", &T);
	for(ind=0; ind<T; ind++){
		fscanf(ent, "%d %d %d", &R, &C, &W);
		if(W==1) fprintf(saida, "Case #%d: %d\n", ind+1, R*C);
		else{
		for(i=1; i<=C; i++) resposta[i]=INF/2-1;
		for(i=1; i<W; i++) resposta[i]=0;
		resposta[W] = R+W-1;
		for(i=W+1; i<=2*W-1; i++) resposta[i] = R + W;

		for(i=2*W; i<=C; i++){
			for(j=2; j<=i-1; j++){
				value = R + resposta[j-1]+resposta[i-j];
				if(value<resposta[i])
					resposta[i] = value;
			}
		}
		fprintf(saida, "Case #%d: %d\n", ind+1, resposta[C]);
		}
	}

	return 0;
}