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

#define MX 102

int na, nb;
int A[MX], B[MX];
LL ca[MX], cb[MX];
LL M[MX][MX];

LL solve(int pa,int pb)
{
	if(pa>=na || pb>=nb) return 0;
	LL &r = M[pa][pb];
	if(r!=-1) return r;
	r = max(solve(pa+1,pb),solve(pa,pb+1));
	int type = A[pa];
	int ppa = pa, ppb = pb;
	for(LL rr=0,aleft = ca[pa], bleft = (B[pb]==type)?cb[pb]:0;pa<na && pb<nb;)
	{
		if(aleft==0){ pa++; while(pa<na && A[pa]!=type) pa++; }
		if(bleft==0){ pb++; while(pb<nb && B[pb]!=type) pb++; }
		
		if(aleft==0 && pa<na && A[pa]==type) aleft = ca[pa];
		if(bleft==0 && pb<nb && B[pb]==type) bleft = cb[pb];
		
		if(aleft==0 || bleft==0) break;
		
		LL pack = min(aleft,bleft);
		rr += pack; aleft-=pack; bleft-=pack;
		r = max(r,rr+solve(pa+1,pb+1));
	}
	//printf("%d,%d --> %lld\n",ppa,ppb,r);
	return r;
}

int main()
{
	//freopen("C-small-attempt0.in","r",stdin);
	freopen("C-large.in","r",stdin);
	//freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	
	for(int kase=1,kases=SI;kase<=kases;kase++)
	{
		printf("Case #%d: ",kase);
		na = SI; nb = SI;
		REP(i,na) scanf("%lld %d",&ca[i],&A[i]);
		REP(i,nb) scanf("%lld %d",&cb[i],&B[i]);
		SET(M,-1);
		printf("%lld\n",solve(0,0));
	}
	
		
	return 0;
}
