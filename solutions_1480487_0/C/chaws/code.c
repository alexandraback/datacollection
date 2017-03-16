#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]){
	
	int N, teste, i, X = 0, m, m2;
	
	// Le os valores a partir de argv
	teste = atoi(argv[1]);
	m = N = atoi(argv[2]);
	
	int s[N];
	float y[N], minimum;
	
	// Calcula o total e pega os scores individuais
	for(i = 0; i < N; i++)
		X += s[i] = atoi(argv[3+i]);
		
	// Calcula o mínimo pra cada um
	m2 = X + X;
	minimum = (float)m2 / (float)m;
	
	
	// Verifica todas porcentagens
	for(i = 0; i < N; i++){
		y[i] = ((float)(minimum - s[i]) / (float)X) * 100.0;
		if(y[i] < 0.0){
			m--;
			y[i] = 0.0;
			m2 -= s[i];
		}
	}
	
	// calcula o mínimo de novo
	minimum = (float)m2 / (float)m;
		
	// Verifica somente scores arriscados
	for(i = 0; i < N; i++)
		if(y[i])
			y[i] = ((float)(minimum - s[i]) / (float)X) * 100.0;
		
	printf("Case #%d:", teste);
	for(i = 0; i < N; i++)
		printf(" %f", y[i]);
		
	printf("\n");

	return 0;
}

