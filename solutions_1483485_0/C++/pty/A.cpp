#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;i++)
#define drep(i,r,l) for(int i=r;i>=l;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define LL long long
#define travel(u) for(int i=start[u],v;v=e[i].a,i;i=e[i].next)
#define eps 1e-10
#define sqr(x) ((x)*(x))
#define pb push_back

char s[10008];
int n, map[1008];
int main()
{
map['a'] = 'y';
map['b'] = 'h';
map['c'] = 'e';
map['d'] = 's';
map['e'] = 'o';
map['f'] = 'c';
map['g'] = 'v';
map['h'] = 'x';
map['i'] = 'd';
map['j'] = 'u';
map['k'] = 'i';
map['l'] = 'g';
map['m'] = 'l';
map['n'] = 'b';
map['o'] = 'k';
map['p'] = 'r';
map['q'] = 'z';//
map['r'] = 't';
map['s'] = 'n';
map['t'] = 'w';
map['u'] = 'j';
map['v'] = 'p';
map['w'] = 'f';
map['x'] = 'm';
map['y'] = 'a';
map['z'] = 'q';//
map[' '] = ' ';

	int t, cnt = 0;
	scanf("%d%*c", &t);
	while (t--)
	{
		gets(s);
		++cnt;
		printf("Case #%d: ", cnt);
		int n = strlen(s);
		rep(i,0,n-1)
			printf("%c", map[s[i]]);	
		printf("\n");
	}
	return 0;
}
