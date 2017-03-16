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
#define pint(t)      printf("%d\n", t);
#define pb           push_back
//#define JAI_ARENA
#ifdef JAI_ARENA
#define debug(args...) {dbg,args; cerr<<endl;}
#define dline cerr<<endl
#else
#define debug(args...) {};
#endif

typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<vi>      vii;


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
double tv[2005];
double pv[2005];
double av[255];
double vv[2005];

double d;
int n, a;
double solve(double acc)
{
    REP(ni, n-1)
    {
	vv[ni] = (pv[ni+1]-pv[ni])/(tv[ni+1] - tv[ni]);
    }
    double mp = 0;
    double mv = 0;
    int ni = 0;
    debug("n", n);
    double ttot;
    for(; ni < n-1; ni++)
    {
	if(pv[ni+1] > d)
	{
	    break;
	}
	double dt = tv[ni+1] - tv[ni];
	mp = mv*dt + 0.5*acc*dt*dt;
	mv = mv + acc*dt;
	if(mp > pv[ni+1])
	{
	    mp = pv[ni+1];
	    mv = vv[ni];
	}
	ttot = tv[ni+1];
	debug("at time ", tv[ni+1], mp);
    }
    if(mp < d)
    {
	double t  = tv[ni];
	double dt = tv[ni+1] - tv[ni];
	double dd = d - mp;
	debug("mv", mv, dd, sqrt(mv*mv+2*acc*dd));
	double t1 = (-mv + sqrt(mv*mv+2*acc*dd))/acc; // time when i reach
	double dv = mv-vv[ni];
	double dd2 = pv[ni] - mp;
	double t2 = (-dv + sqrt(dv*dv+2.0*acc*dd2))/acc; // time when i crosses it
	debug("t1", t1, "t2", t2, mv, vv[ni+1]);
	if(t1 <= t2)
	{
	    debug("ret", t, t1, t2);
	    return t + t1;
	}else
	{
	    debug("hehr");
	    mp += mv*t2 + 0.5*acc*t2*t2;
	    mv += acc*t2;
	    double t3 = (d - mp)/vv[ni];
	    debug(t, t2, t3);
	    return t + t2 + t3;
	}
    }
    else
    {
	debug("direct reach");
	return ttot;
    }
}
int main()
{
    int t;
    gint(t);
    IFOR(ti, 1, t+1)
    {
	scanf("%lf", &d);
	gint(n);
	gint(a);
	REP(ni, n)
	{
	    scanf("%lf", tv+ni);
	    scanf("%lf", pv+ni);
	}
	printf("Case #%d:\n", ti);
	REP(ai, a)
	{
	    scanf("%lf", av+ai);
	    double bestt = solve(av[ai]);
	    printf("%.10lf\n", bestt);
	}
    }
    return 0;
}
