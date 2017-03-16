#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 1000

char mapping[256];

void prepare_map() {
	char* sample_inp[3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	char* sample_out[3] = {"our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};
	memset(mapping, '\0', 256);
	int j = 0;
	for(; j < 3; j++) {
		char * e = sample_inp[j];
		char * d = sample_out[j];
		while (*e != '\0') {
			//if (mapping[*e] == '\0')
			//	printf("%c --> %c\n", *e, *d);
			mapping[*e] = *d;
			e++;
			d++;
		}
	}
	//mapping['y'] = 'a';
	//mapping['e'] = 'o';
	mapping['z'] = 'q';
	//mapping['t'] = 'w';
	mapping['q'] = 'z';
}

void decode(char * str) {
	char * r = str;
	while (*r != '\0') {
		if ('a' <= *r  && *r <= 'z')
			*r = mapping[*r];
		r++;
	}
}

void main() {
	int T;
	char str[MAX_STRING_LEN + 1];
	prepare_map();
	scanf("%d\n", &T);
	int i;
	for(i = 0; i < T; i++) {
		char * s = fgets(str, MAX_STRING_LEN + 1, stdin);
		int l = strlen(s);
		s[l-1] = '\0';
		//printf("Input = %s\n", s);
		decode(s);
		printf("Case #%d: %s\n", i+1, s);
	}
}
