#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <assert.h>
#include <math.h>
#include <string.h>
using namespace std;

#define FOREACH(it,vec) for(typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); it++)
#define MOD(a,b) (((a)%(b)+(b))%(b))
#define REP(i,n) for (int i = 0; i < (int)(n); i++)

char si[] = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
char so[] = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";

char ma[26];

char zeile[1000];

int T;

int main() {
	REP(i,26)
		ma[i] = 0;
	int L = strlen(si);
	ma['q'-'a'] = 'z';
	ma['z'-'a'] = 'q';
	REP(i,L)
		ma[si[i]-'a'] = so[i];
	REP(i,26)
		fprintf(stderr, "%c -> %c\n", i+'a', ma[i]);
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		gets(zeile);
		L = strlen(zeile);
		REP(i,L)
			zeile[i] = ma[zeile[i]-'a'];
		printf("%s\n", zeile);
	}
	return 0;
}
