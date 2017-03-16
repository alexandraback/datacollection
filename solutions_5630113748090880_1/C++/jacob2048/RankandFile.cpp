#include <stdio.h>

int flag[3000];

int main(){
	FILE *Fin;
	FILE *Fout;
	int TestLoof = 0;
	int TestCount = 0;
	int i = 0, j = 0, k = 0;
	int num;
	int N;

	Fin = fopen("B-large.in", "r");
	Fout = fopen("output.txt", "w");

	fscanf(Fin, "%d", &TestCount);

	for (TestLoof = 1; TestLoof <= TestCount; TestLoof++){
		
		fscanf(Fin, "%d", &N);
		for (i = 0; i < 2600;i++){
			flag[i] = 0;
		}
		for (i = 0; i < N*((2 * N - 1)); i++){
			fscanf(Fin, "%d", &num);
			flag[num]++;
		}


		fprintf(Fout, "Case #%d: ", TestLoof);
		for (i = 1; i <= 2500;i++){
			if (flag[i]%2){
				fprintf(Fout, "%d ", i);
			}
		}
		fprintf(Fout, "\n");
	}
	fclose(Fout);
	fclose(Fin);

	return 0;
}