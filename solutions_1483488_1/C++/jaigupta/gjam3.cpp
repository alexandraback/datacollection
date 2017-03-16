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


/* memset(start*, byteVal, numBytes);
 *  memcpy(dst*, src*, numBytes);
 */

char tab[2000005];
int  resm[2000005][10];
int  ft[20];
inline int numRec(int n)
{
    int p = 1,k=0, cnt=0;
    while(p<=n) {
	p*=10;
    }
    int r = 10, nf = 0, nfi;
    while(r < p)
    {
	int rem = n%r;
	if(rem>=(r/10))
	{
	    int n2 = rem*(p/r) + n/r;
	    if(n2 < n)
	    {
		for(nfi=0; nfi<cnt; nfi++)
		    if(resm[n][nfi]==n2) break;
		if(nfi == cnt)
		{
//		    debug(n, "=>", n2);
		    resm[n][cnt++] = n2;
		}
	    }
	}
	r*=10;
    }
    return cnt;
}

void precalculate()
{
    for(int i = 1; i<=2000001; i++)
    {
	tab[i] = numRec(i);
    }
}

int main()
{
    precalculate();
    int t = readInt();
    IFOR(ti, 1, t+1)
    {
	int a = readInt();
	int b = readInt();
	int res = 0;
	IFOR(i, a+1, b+1)
	{
	    REP(j, tab[i])
	    {
		if(resm[i][j] >=a)
		{
//		    debug(i, resm[i][j]);
		    res++;
		}
	    }
	    //if(tab[i])
//	    debug(i, res);
	}
	printf("Case #%d: %d\n", ti, res);
    }
    return 0;
}
