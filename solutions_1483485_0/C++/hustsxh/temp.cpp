#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

#define N 1000010

using namespace std;

char s[101];

char a[26] = {
	'y', 'h', 'e', 's', 'o', 'c', 'v',
	'x', 'd', 'u', 'i', 'g', 'l', 'b',
	'k', 'r','z', 't', 'n', 'w', 
	'j', 'p', 'f', 'm', 'a', 'q'
};

int main() 
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);

	int T;
	cin >> T;
	gets(s);
	for(int test = 1; test <= T; ++test) {
		gets(s);
		for(int i = 0; s[i]; ++i) {
			if(s[i] == ' ') continue;
			s[i] = a[s[i] - 'a'];
		}
		printf("Case #%d: %s\n", test, s);
		//puts(s);
	}
	return 0;
}
/*
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up
*/
