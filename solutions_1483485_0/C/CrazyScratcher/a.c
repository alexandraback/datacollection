#include <stdio.h>
#include <string.h>

int findmapping_main() {
	char buf[1024], buf2[1024];
	int i, j;
	char mapping[26];
	memset(mapping, 0, sizeof(mapping));
	while (1) {
		if (gets(buf) == NULL) break;
		if (gets(buf2) == NULL) return 1;

		if (strlen(buf) != strlen(buf2)) return 1;
		for (i = 0; i < strlen(buf); i++) {
			if (buf[i] != ' ' && buf2[i] != ' ') {
				if (mapping[buf[i]-'a']) {
					if (mapping[buf[i]-'a'] != buf2[i]) {
						printf("Inconsistent mapping\n");
						return 2;
					}
				} else
					mapping[buf[i]-'a'] = buf2[i];
			}
		}
	}
	for (i = 0; i < sizeof(mapping); i++) {
		if (mapping[i]) printf("\'%c\'\n", mapping[i]);
		else printf("\n");
	}
	return 0;
}

char mapping[26] = {'y',
'h',
'e',
's',
'o',
'c',
'v',
'x',
'd',
'u',
'i',
'g',
'l',
'b',
'k',
'r',
'z',
't',
'n',
'w',
'j',
'p',
'f',
'm',
'a',
'q'};

int main() {
	char buf[1024];
	int N;
	scanf("%d", &N);

	int i, j;
	gets(buf);
	for (i = 0; i < N; i++) {
		gets(buf);
		for (j = strlen(buf)-1; j >= 0; j--) {
			if (buf[j] >= 'a' && buf[j] <= 'z')
				buf[j] = mapping[buf[j]-'a'];
		}
		printf("Case #%d: %s\n", i+1, buf);
	}
	return 0;
}

