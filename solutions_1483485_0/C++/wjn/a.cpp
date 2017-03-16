#include <stdio.h>
#include <algorithm>
using namespace std;

const char *A[] = { "ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv" };
const char *B[] = { "our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up" };
char go[128];

int main()
{
	for (int i = 0; i < 3; ++i)
		for (int j = 0; A[i][j]; ++j)
			go[A[i][j]] = B[i][j];
	int T;
	char s[1024];
	scanf("%d ", &T);
	go['z'] = 'q';
	go['q'] = 'z';
	for (int t = 0; t < T; ++t)
	{
		gets(s);
		printf("Case #%d: ", t+1);
		for (int i = 0; s[i]; ++i) putchar(go[s[i]]);
		puts("");
	}
	return 0;
}
