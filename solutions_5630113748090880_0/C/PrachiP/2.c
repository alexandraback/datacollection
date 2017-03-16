#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main(int argc, char *argv[]){

	FILE *fp = fopen(argv[1], "r");
	
	if (fp == NULL){
		printf("unable to open file");
		exit(1);
	}
	
	int test, t, ht[2501], n, a[50], i, j, num;
	
	fscanf(fp, "%d", &test);
	//scanf("%d", &test);
	for (t = 1; t <= test; t++){
		for (i = 0; i < 2501; i++)
			ht[i] = 0;
		
		fscanf(fp, "%d", &n);
		for (i = 0; i < 2 * n - 1; i++){
			for (j = 0; j < n; j++){
				fscanf(fp, "%d", &num);
				ht[num]++;
			}
		}
		i = j = 0;
		while (i < n){
			if (ht[j] % 2 == 1){
				a[i] = j;
				i++;
			}
			j++;
		}
		
		qsort(a, n, sizeof(int), cmpfunc);
	
		printf("Case #%d: ", t);
		for (i = 0; i < n; i++)
			printf("%d ", a[i]);
		printf("\n");
			
	}
	
	
	
	fclose(fp);
	return 0;
}
