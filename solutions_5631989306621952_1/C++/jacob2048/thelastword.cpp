#include <stdio.h>

char str[1010];

int main(){
	FILE *Fin;
	FILE *Fout;
	int TestLoof = 0;
	int TestCount = 0;
	int i = 0, j = 0, k = 0;
	char temp;
	int Index;
	int max;
	int len = 0;
	
	Fin = fopen("A-large.in", "r");
	Fout = fopen("output.txt", "w");

	fscanf(Fin, "%d", &TestCount);

	for (TestLoof = 1; TestLoof <= TestCount; TestLoof++){
		len = 0;
		fscanf(Fin, "%c", &temp);
		fscanf(Fin, "%s", str);
		for (i = 0; str[i] != 0; i++){
			len++;
		}

		for (i = 0; i < len;i++){
			if (str[0] <= str[i]){
				temp = str[i];
				for (j = i; j >= 1; j--){
					str[j] = str[j - 1];
				}
				str[0] = temp;
			}
		}


		fprintf(Fout, "Case #%d: ", TestLoof);
		fprintf(Fout, "%s\n", str);
	}
	fclose(Fout);
	fclose(Fin);

	return 0;
}