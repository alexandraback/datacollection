#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[200];
char exg[30] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

FILE* fw;

int main() {
	freopen("A-small-attempt2.in", "r", stdin);
	fw = fopen("A_s_2.txt", "w");
//	fopen("A_s_0.txt", "w");
	int t, i, g = 1;
	scanf("%d", &t);
	getchar();
	while(t--) {
//		printf("t=%d\n", t);
		gets(str);
//		puts(str);
		fprintf(fw, "Case #%d: ", g++);
		for(i = 0; str[i]; ++i) {
			if(str[i] == ' ') fprintf(fw, " ");
			else
				fprintf(fw, "%c", exg[str[i] - 'a']);
		}
		fprintf(fw, "\n");
	}
	return 0;
}
