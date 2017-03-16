#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char w[1000];
int main(void) {
const char *a="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv y qee z";
const char *b="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up a zoo q";
char to[128];
	for(int i=0;a[i];i++) to[a[i]] = b[i];
	int T;
	scanf("%d", &T);
	gets(w);
	for(int cs=1;cs<=T;cs++) {
		gets(w);
		printf("Case #%d: ", cs);
		for(int i=0;w[i];i++)
			if(w[i]==' ') printf(" ");
 		else printf("%c", to[w[i]]);
		puts("");
	}
	return 0;
}
