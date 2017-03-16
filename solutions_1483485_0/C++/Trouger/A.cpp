#include <stdio.h>
#include <string.h>

const char samplesI[][101] = {
	"ejp mysljylc kd kxveddknmc re jsicpdrysi",
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
	"de kr kd eoya kw aej tysr re ujdr lkgc jv"
};
const char samplesO[][101] = {
	"our language is impossible to understand",
	"there are twenty six factorial possibilities",
	"so it is okay if you want to just give up"
};

int mapping[128];

int main()
{
	memset(mapping, -1, sizeof(mapping));
	for (int i = 0; i < 3; i++){
		for (const char *s1 = samplesI[i], *s2 = samplesO[i]; *s1; ++s1, ++s2){
			int t = mapping[*s1];
			if (t == -1)
				mapping[*s1] = *s2;
			else if (t != *s2){
				puts("error");
				return 0;
			}
		}
	}
	mapping['q'] = 'z';
	mapping['z'] = 'q';
	for (int i = 'a'; i <= 'z'; i++)
		if (mapping[i] == -1){
			printf("missing: %c\n", i);
		}
	if (mapping[' '] == -1){
		puts("error");
		return 0;
	}
	int T;
	scanf("%d", &T);
	char s[101];
	gets(s);
	for (int ttt = 1; ttt <= T; ttt++){
		gets(s);
		for (char *p = s; *p; ++p)
			*p = mapping[*p];
		printf("Case #%d: %s\n", ttt, s);
	}
	return 0;
}