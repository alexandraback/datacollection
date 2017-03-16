#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

	FILE *fp = fopen(argv[1], "r");
	
	if (fp == NULL){
		printf("unable to open file");
		exit(1);
	}
	
	int start, end, i, n, test, t;
	char s[1001], p[2001], op[1001]; 
	
	fscanf(fp, "%d", &test);
	for (t = 1; t <= test; t++){
	
		fscanf(fp, "%s", s);
		n = strlen(s);
		start = 1000;
		end = 1001;
		i = 0;
		p[start] = s[i];
		for (i = 1; i < n; i++){
			if (s[i] < p[start]){
				p[end] = s[i];
				end++;
			}
			else{
				start--;
				p[start] = s[i];
			} 
		}
		int j = 0;
		for (i = start; i < end; i++){
			op[j] = p[i];
			j++;
		}
		
		printf("Case #%d: ", t);
		for (i = 0; i < j; i++)
			printf("%c", op[i]);
		printf("\n");
			
	}
	
	
	fclose(fp);
}
