#include <stdio.h>
#include <stdlib.h>

void merging(int *numeros, int tamanho) {
	int *pM = numeros + tamanho / 2, *pI = numeros, *pJ = pM, *pF = numeros + tamanho - 1;
	int *temp = (int*) malloc(tamanho * sizeof(int)), *pT = temp;
	if (!temp) exit(1);
	while (pI < pM && pJ <= pF) {
		if (*pI < *pJ) *pT++ = *pI++;
		else *pT++ = *pJ++;
	}
	if (pI == pM) while (pJ <= pF) *pT++ = *pJ++;
	else while (pI < pM) *pT++ = *pI++;
	for (pT = temp, pI = numeros; pI <= pF; ++pT, ++pI) *pI = *pT;
	free(temp);
}

void merge(int *numeros, int tamanho) {
	if (tamanho > 1) {
		int meio = tamanho / 2;
		merge(numeros, meio);
		merge(numeros + meio, tamanho - meio);
		merging(numeros, tamanho);
	}
}

int compara(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}

int main(int argc, char *argv[]) {
	FILE *fr = fopen("input.txt", "r");
	FILE *fw = fopen("output.txt", "w");
	int i, j, total, mote, motes, restantes, maiores, *motelist, *pML, op;
	fscanf(fr, "%d", &total);
	for (i = 0; i < total; ++i) {
		fscanf(fr, "%d %d", &mote, &motes);
		printf("%d %d\n", mote, motes);
		if (mote == 1) {
			printf("Case %d: #%d\n", i+1, motes);
			//fprintf(fw, "Case #%d: %d\n", i+1, motes);
			continue;
		}
		restantes = motes;
		maiores = 0;
		op = 0;
		motelist = (int*) malloc(motes * sizeof(int));
		for (j = 0, pML = motelist; j < motes; ++j, ++pML) {
			fscanf(fr, "%d", pML);
			printf("%d ", *pML);
		}
		printf("\n");
		qsort(motelist, motes, sizeof(int), compara);
		for (j = 0; j < motes; ++j) printf("%d ", motelist[j]);
		printf("\n");
		//merge(motelist, motes);
		for (j = 0, pML = motelist; j < motes; ++j) {
			if (mote > *pML) {
				--restantes;
				mote += *pML++;
				printf("[%d]\n", mote);
			}
			else {
				if (!maiores) maiores = restantes;
				printf("(%d) ", (mote - 1 > 100) ? 100 : mote - 1);
				mote += (mote - 1 > 100) ? 100 : mote - 1;
				printf("(%d)\n", mote);
				++op;
			}
		}
		printf("Case %d: #%d\n", i+1, ((op > maiores) ? maiores : op));
		//fprintf(fw, "Case #%d: %d\n", i+1, ((op > maiores) ? maiores : op));
		system("PAUSE");
	}
	return 0;
}
