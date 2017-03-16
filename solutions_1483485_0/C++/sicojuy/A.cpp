#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

int main() {
	freopen("Input.txt", "rt", stdin);
	freopen("Output.txt", "wt", stdout);

	int t;
//	char from[3][105] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
//	char to[3][105] = {"our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};
	char m[30] = "yhesocvxduiglbkrztnwjpfmaq";
	char googlerese[105];
	char english[105];
	char *p, *q;
	int i;
	/*memset(m, 0, sizeof(char) * 26);
	for(i = 0; i < 3; ++i) {
		for(p = from[i], q = to[i]; *p; ++p, ++q) {
			if(*p != ' ')
				m[*p - 'a'] = *q;
		}
	}
	m['q' - 'a'] = 'z';
	m['z' - 'a'] = 'q';
	for(i = 0; i < 26; ++i)
		printf("%c", m[i]);
	return 0;*/

	scanf("%d\n", &t);
	for(i = 1; i <= t; ++i) {
		gets(googlerese);
		for(p = googlerese, q = english; *p; ++p, ++q) {
			*q = *p == ' ' ? ' ' : m[*p - 'a'];
		}
		*q = '\0';
		printf("Case #%d: %s\n", i, english);
	}
	return 0;
}