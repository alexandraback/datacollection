#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <vector>
#include <queue>

using namespace std;

#define PI acos(-1)
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define PII pair <int, int>
#define LL long long
#define SET(v,i) memset(v, i, sizeof(v))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define FORN(i,a,b) for (int i = (a); i < (b); i++)
#define DOWN(i,a,b) for (int i = (a); i > (b); i--)
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define FREOPEN freopen("A-small-attempt2.in", "r", stdin); freopen("a.out", "w", stdout)

char s[110];
map <char, char> f;

string a[6] = { "ejp mysljylc kd kxveddknmc re jsicpdrysi",
				"our language is impossible to understand",
				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
				"there are twenty six factorial possibilities",
				"de kr kd eoya kw aej tysr re ujdr lkgc jv",
				"so it is okay if you want to just give up" };
				
int main() {
	int t;
	FREOPEN;
	f['a'] = 'y';
	f['z'] = 'q';
	f['o'] = 'e';
	f[' '] = ' ';
	
	FOR (i, 0, 5)
	if ((i % 2) == 0) {
		int j = 0;
		while (a[i][j]) {
			f[a[i][j]] = a[i + 1][j];
			j++;
		}
	}
	for (char c = 'a'; c <= 'z'; c++) {
		int ok = 1;
		for (char x = 'a' ; x <= 'z'; x++)
			if (f[x] == c) ok = 0;
		if (ok == 1) f['q'] = c;
	}
	
	cin >> t; gets(s);
	
	FOR (test, 1, t) {
		gets(s);
		int i = 0;
		//printf("%s\n", s);
		while (s[i]) {
			s[i] = f[s[i]];
			//cerr << s[i] << endl;
			i++;
		}
		printf("Case #%d: %s\n", test, s);		
	}
	return 0;
}
