#include <stdio.h>

char str[200], trans[200];

char inp[3][200] = {
	"ejp mysljylc kd kxveddknmc re jsicpdrysi"
 "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
 "de kr kd eoya kw aej tysr re ujdr lkgc jv"
};
char out[3][200] = {
	"our language is impossible to understand"
 "there are twenty six factorial possibilities"
 "so it is okay if you want to just give up"
};

char map[256];
bool chk[256];

int main()
{
	int i, j;
	for (i=0; i<3; i++) for (j=0; inp[i][j]; j++) {
		map[ inp[i][j] ] = out[i][j];
		chk[out[i][j]] = true;
	}
	map['q'] = 'z'; map['z'] = 'q';

	int t, tt=0;
	scanf("%d\n", &t);
	while (t--) {
		gets(str);

		printf("Case #%d: ", ++tt);
		for (i=0; str[i]; i++) str[i] = map[str[i]];
		printf("%s\n", str);
	}
}
