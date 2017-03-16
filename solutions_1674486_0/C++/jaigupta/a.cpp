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
int visited[1005];
int tvisited[1005];
vi edges[1005];
int n;
bool checkfedge(int p)
{
    memset(tvisited, 0, sizeof(int)*1005);
    stack<int> st;
    st.push(p);
    visited[p] = 1;
    tvisited[p] = 1;
    while(!st.empty())
    {
	int b = st.top();
	st.pop();
	REP(ti, edges[b].size())
	{
	    if(tvisited[edges[b][ti]]) return true;
	    st.push(edges[b][ti]);
	    tvisited[edges[b][ti]] = 1;
	    visited[edges[b][ti]] = 1;
	}
    }
    return false;
}
int main()
{
    int t = readInt();
    IFOR(ti, 1, t+1)
    {
	n = readInt();
	REP(ni, n)
	{
	    edges[ni].clear();
	}
	REP(ni, n)
	{
	    int s = readInt();
	    REP(si, s)
	    {
		int e = readInt();
		e--;
		edges[ni].push_back(e);
	    }
	}
	memset(visited, 0, sizeof(int)*1005);
	bool flag = false;
	REP(ni, n)
	{
	    if(visited[ni] == 0)
	    {
		flag = checkfedge(ni);
		if(flag)
		{
		    break;
		}
	    }
	}
	if(flag)
	{
	    printf("Case #%d: Yes\n", ti);
	}else {
	    printf("Case #%d: No\n", ti);
	}
    }
    return 0;
}
