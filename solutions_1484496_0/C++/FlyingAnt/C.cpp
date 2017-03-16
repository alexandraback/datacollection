/* AnilKishore * India */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SET(v,x) memset(v,x,sizeof v)
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define EACH(it,v) for(typeof((v).begin()) it = (v).begin();it!=(v).end();it++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

int n, A[22];

int bc[(1<<20)];

bool solve(int ci,int as,int bs, int am,int bm)
{
	if(as==bs && bc[am]>0 && bc[bm]>0)
	{
		REP(i,n) if((am&(1<<i))) printf("%d ",A[i]);
		puts("");
		REP(i,n) if((bm&(1<<i))) printf("%d ",A[i]);
		puts("");
		return true;
	}
	
	if(ci==n) return false;
	
	if(solve(ci+1,as,bs,am,bm)) return true;
	if(solve(ci+1,as+A[ci],bs,am|(1<<ci),bm)) return true;
	if(solve(ci+1,as,bs+A[ci],am,bm|(1<<ci))) return true;
	
	return false;
}

int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("out1.out","w",stdout);

	REP(i,(1<<20)) bc[i] = bc[i>>1] + (i&1);
		
	for(int kases=SI,kase=1;kase<=kases;kase++)
	{
		n = SI;
		REP(i,n) A[i] = SI;			
		printf("Case #%d: \n",kase);
		solve(0,0,0,0,0);
	}
	
	return 0;
}
