#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define rep(x, n) for (int x = 1; x <= n; ++x)
#define drp(x, n) for (int x = n; x; --x)
#define FOR(x, l, r) for (int x = l; x <= r; ++x)
char f[1005], s[10005];
int main()
{
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	f['a'] = 'y';
	f['b'] = 'h';
	f['c'] = 'e';
	f['d'] = 's';
	f['e'] = 'o';
	f['f'] = 'c';
	f['g'] = 'v';
	f['h'] = 'x';
	f['i'] = 'd';
	f['j'] = 'u';
	f['k'] = 'i';
	f['l'] = 'g';
	f['m'] = 'l';
	f['n'] = 'b';
	f['o'] = 'k';
	f['p'] = 'r';
	f['q'] = 'z';
	f['r'] = 't';
	f['s'] = 'n';
	f['t'] = 'w';
	f['u'] = 'j';
	f['v'] = 'p';
	f['w'] = 'f';
	f['x'] = 'm';
	f['y'] = 'a';
	f['z'] = 'q';
	f[' '] = ' ';
	int ca;
	scanf("%d%*c", &ca);
	rep(i, ca)
	{
		gets(s);
		printf("Case #%d: ", i);
		int n = strlen(s);
		FOR(i, 0, n - 1) printf("%c", f[s[i]]);
		puts("");
	}
	return 0;
}