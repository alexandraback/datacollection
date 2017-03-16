#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char eng[30] = "abcdefghijklmnopqrstuvwxyz ";
char ggl[30] = "ynficwlbkuomxsevzpdrjgthaq ";

int searchIndex(char c) {
	int i;
	for(i = 0; i < 27; i++) if (c == ggl[i]) return i;
	return -1;
}

void gglToEng(char *c) {
	*c = eng[searchIndex(*c)];
}

int main(){
	int i, j;
	int T;
	char *test;
	char tmp[10];
	char input[30][110];
	FILE *in, *out;

	in = fopen("A-small-attempt0.in", "r");
	out = fopen("output.txt", "w");

	fgets(tmp, 10, in);
	T = atoi(tmp);
	for (i = 0; i < T; i++) {
		fgets(input[i], 110, in);
		for (j = 0; j < strlen(input[i]); j++) {
			gglToEng(&input[i][j]);
		}
		printf("Case #%d: %s\n", i+1, input[i]);
		fprintf(out, "Case #%d: %s\n", i+1, input[i]);
	}

	fclose(in);
	fclose(out);
}
