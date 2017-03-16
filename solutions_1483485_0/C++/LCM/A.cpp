#include<cstdio>

int a;
char b[110], c[30] = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
	scanf("%d\n", &a);
	for (int i = 0 ; i < a ; i++) {
		scanf("%[^\n]\n", b);
		printf("Case #%d: ", i + 1);
		for (int j = 0 ; b[j] ; j++) {
			if (b[j] >= 'A' && b[j] <= 'Z') printf("%c", c[b[j] - 'A']);
			else if (b[j] >= 'a' && b[j] <= 'z') printf("%c", c[b[j] - 'a']);
			else printf("%c", b[j]);
		}
		printf("\n");
	}
	scanf("\n");
	return 0;
}
/*
6
qee
zjccs
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
abc
*/
