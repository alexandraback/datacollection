/* Jai Gupta */
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <deque>
#include <bitset>
#include <cmath>
#include <functional>
#include <set>

using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define uint unsigned int
#define MAX(a,b)   (((a)>(b))?(a):(b))
#define MIN(a,b)   (((a)<(b))?(a):(b))
#define CMAX(a,b)  if((a)<(b)) a=b
#define CMIN(a,b)  if((a)>(b)) a=b
#define FOR(i,a,b)   for(i=a; i<b; i++)
#define REVI(i,a,b)  for(int i= a ; i >= b ; --i)
#define LET(x,a)     __typeof(a) x(a)
#define IFOR(i,a,b)  for(LET(i,a);i!=(b);++i)
#define EACH(it,v)   IFOR(it,v.begin(),v.end())
#define SWAP(a,b,t)  t=a,a=b,b=t
#define REP(i,n)     for(int i=0; i<n; i++)
#define ll           long long int
#define ull          unsigned long long int
#define gint(t)      scanf("%d", &t);
#define gint2(a,b)   scanf("%d%d", &a, &b);
#define gint3(a,b,c) scanf("%d%d%d", &a, &b, &c);
#define pint(t)      printf("%d\n", t);
#define pint2(a,b)   printf("%d %d\n", a, b);
#define pint3(a,b,c) printf("%d %d %d\n", a, b, c);
#define pii          pair<int, int>
#define debug(args...) {dbg,args; cerr<<endl;}
#define dline cerr<<endl
#define pb           push_back
struct debugger
{
    template<typename T> debugger& operator , (const T& v)
	{
	    cerr<<v<<" ";
	    return *this;
	}
} dbg;


#define BUF 4096
char ibuf[BUF];
int ipt = BUF;
 
int readInt() {
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
    if (ipt == BUF) {
	fread(ibuf, 1, BUF, stdin);
	ipt = 0;
	while (ipt < BUF && ibuf[ipt] < '0') ipt++;
    }
    int n = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
    if (ipt == BUF) {
	fread(ibuf, 1, BUF, stdin);
	ipt = 0;
	while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
    }
    return n;
}

char xmap[255];
/* memset(start*, byteVal, numBytes);
 *  memcpy(dst*, src*, numBytes);
 */
char v[105];
int main()
{
    xmap['a'] = 'y';
    xmap['b'] = 'h';
    xmap['c'] = 'e';
    xmap['d'] = 's';
    xmap['e'] = 'o';
    xmap['f'] = 'c';
    xmap['g'] = 'v';
    xmap['h'] = 'x';
    xmap['i'] = 'd';
    xmap['j'] = 'u';
    xmap['k'] = 'i';
    xmap['l'] = 'g';
    xmap['m'] = 'l';
    xmap['n'] = 'b';
    xmap['o'] = 'k';
    xmap['p'] = 'r';
    xmap['q'] = 'z';
    xmap['r'] = 't';
    xmap['s'] = 'n';
    xmap['t'] = 'w';
    xmap['u'] = 'j';
    xmap['v'] = 'p';
    xmap['w'] = 'f';
    xmap['x'] = 'm';
    xmap['y'] = 'a';
    xmap['z'] = 'q';
    xmap[' '] = ' ';
    int t;
    cin >> t;
    cin.getline(v, 105);
    IFOR(ti, 1, t+1)
    {
	cin.getline(v, 105);
	int l = strlen(v);
	REP(li, l)
	{
	    v[li] = xmap[v[li]];
	}
	printf("Case #%d: %s\n", ti, v);
    }
    return 0;
}
