#include<stdio.h>
#include<string.h>

int main() {
	int i, j;
	int t;
	int out[1024];
	char s[1024];
	char max;
	scanf("%d", &t);
	getchar();
	for (i = 0; i < t; i++) {
		gets(s);
		printf("Case #%d: ", i+1);
		out[0] = 0;
		max = s[0];
		for (j = 1; j < strlen(s); j++) {
			if (s[j] >= max) {
				max = s[j];
				out[j] = 0;
			}
			else {
				out[j] = 1;
			}
		}
		for (j = strlen(s); j > -1; j--) {
			if (out[j] == 0) {
				printf("%c", s[j]);
			}
		}
		for (j = 0; j<strlen(s); j++) {
			if (out[j] == 1) {
				printf("%c", s[j]);
			}
		}
		printf("\n");
	}
}