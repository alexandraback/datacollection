int N,M;
int matriz[100][100];
int colunas[100];

int testLinha(int i, int indice){
	int j;
	for (j = 0; j < M; ++j){
		if(matriz[i][j] > indice)
			return 1;
	}
	//linhas[i] = indice;
	return 0;
}
int testColuna(int j, int indice){
	int i;
	for (i = 0; i < N; ++i){
		if(matriz[i][j] > indice)
			return 1;
	}
	colunas[j] = indice;
	return 0;
}

int main(){
	int i,j,k;
	int nTest;
	int quant[100];
	int indice;
	int possivel;

	scanf("%d",&nTest);
	for (k = 0; k < nTest; ++k){
		scanf("%d",&N);
		scanf("%d",&M);
		for (j = 0; j < M; ++j){
			colunas[j] = 0;
		}
		for (i = 0; i < N; ++i){
			for (j = 0; j < M; ++j){
				scanf("%d",&matriz[i][j]);
				quant[matriz[i][j]-1]++;
			}
		}
		possivel = 1;
		indice = 0;
		while(indice < 100){
			if(quant[indice] != 0){
				for (i = 0; i < N; ++i){
					if(testLinha(i, indice+1) == 1){
						for (j = 0; j < M; ++j){
							if((matriz[i][j] == indice+1) && (colunas[j] != indice+1)){
								if(testColuna(j, indice+1) == 1){
									possivel = 0;
									break;
								}
							}
						}
						if (possivel == 0){
							break;
						}
					}
				}
				if (possivel == 0){
					break;
				}
			}
			indice++;
		}
		if (possivel == 0){
			printf("Case #%d: NO\n", k+1);
		} else {
			printf("Case #%d: YES\n", k+1);
		}
	}
	return 0;
}
