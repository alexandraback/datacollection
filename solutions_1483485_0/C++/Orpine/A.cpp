#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;i++)
char s[10008];
int n;
char map[1008];
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	map['a'] = 'y';map['b'] = 'h';
	map['c'] = 'e';map['d'] = 's';
	map['e'] = 'o';map['f'] = 'c';	
	map['g'] = 'v';map['h'] = 'x';	
	map['i'] = 'd';map['j'] = 'u';
	map['k'] = 'i';map['l'] = 'g';
	map['m'] = 'l';map['n'] = 'b';
	map['o'] = 'k';map['p'] = 'r';
	map['q'] = 'z';map['r'] = 't';	
	map['s'] = 'n';map['t'] = 'w';
	map['u'] = 'j';map['v'] = 'p';
	map['w'] = 'f';map['x'] = 'm';
	map['y'] = 'a';map['z'] = 'q';
	map[' '] = ' ';
	int t, cnt = 0;
	scanf("%d%*c", &t);
	while (t--)
	{
		gets(s);
		++cnt;
		printf("Case #%d: ", cnt);
		int n = strlen(s);
		rep(i,0,n-1)printf("%c",map[s[i]]);
		printf("\n");
	}
	return 0;
}