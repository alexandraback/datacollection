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

int main()
{
    int t, n;
    t = readInt();
    int a[1000];
    int b[1000];
    int c[1000];
    int ca[1000];
    IFOR(ti, 1, t+1)
    {
	int n = readInt();
	int vcount = 0, lcount = 0;
	REP(ni, n)
	{
	    a[ni] = readInt();
	    b[ni] = readInt();
	    c[ni] = 0;
	    ca[ni] = 0;
	}
	int star = 0;
	while(1)
	{
	    REP(ni, n)
	    {
		//debug("vheck", ni);
		if(c[ni]==0 && b[ni] <= star)
		{
		    //debug("c", c[ni]);
		    c[ni] = 1;
		    if(ca[ni] == 1)
			star += 1;
		    else
			star += 2;
		    ca[ni] = 1;
		    lcount++;
		    vcount++;
		    //debug("visiting ", ni, b[ni], star);
		    ni = -1;
		}
	    }
	    if(vcount == n)
	    {
		printf("Case #%d: %d\n", ti, lcount);
		break;
	    }
	    int flag = 0;
	    REP(ni, n)
	    {
		if(ca[ni] == 0 && a[ni] <= star)
		{
		    ca[ni] = 1;
		    star += 1;
		    lcount++;
		    //debug("vis", ni, star);
		    flag = 1;
		    break;
		}
	    }
	    if(!flag)
	    {
		printf("Case #%d: Too Bad\n", ti);
		break;
	    }
	}
    }
    return 0;
}
