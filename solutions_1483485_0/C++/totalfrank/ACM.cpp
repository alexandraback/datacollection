#include <stdio.h>
#include <string.h>
#include <map>
#include <set>

using namespace std;

#define MAXN 110

char goo[][MAXN] = { "ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv" };
char eng[][MAXN] = { "our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up" };
char text[MAXN];

map<char, char> mp;
set<char> st;

int main() {
	freopen("A-small-attempt3.in", "r", stdin);
	freopen("A.out", "w", stdout);

	for (int i = 0; i < 3; ++i) {
		int l = strlen(goo[i]);
		for (int j = 0; j < l; ++j)
			mp[goo[i][j]] = eng[i][j];
	}
	mp['q'] = 'z';
	mp['z'] = 'q';
	int T;
	scanf("%d", &T);
	gets(text);
	for (int cas = 1; cas <= T; ++cas) {
		gets(text);
		printf("Case #%d: ", cas);
		int l = strlen(text);
		for (int i = 0; i < l; ++i)
			putchar(mp[text[i]]);
		puts("");
	}
	return 0;
}
