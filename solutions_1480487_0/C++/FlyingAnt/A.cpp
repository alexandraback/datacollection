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

#define MX 202

int n, A[MX], X;

bool pakkaLose(double myperc, int ci)
{
	double percLeft = 100 - myperc, myscore = A[ci] + X * myperc/100.;
	REP(i,n) if(i!=ci)
	{
		if(A[i]>=myscore) continue;
		double need = (myscore-A[i])*100./(X*1.);
		if(need>percLeft) return false;
		percLeft-=need;
	}	
	return true;
}

double solve(int ci)
{
	double lo = 0, hi = 100.0;
	REP(k,100)
	{
		double mid = (lo+hi)/2.;
		if(pakkaLose(mid,ci)) lo = mid;
		else hi = mid;
	}
	return (lo+hi)/2.;
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out1.out","w",stdout);
		
	for(int kases=SI,kase=1;kase<=kases;kase++)
	{
		n = SI;
		X = 0;
		REP(i,n){ A[i] = SI; X += A[i]; }		
		printf("Case #%d: ",kase);
		REP(i,n) printf("%lf ",solve(i));
		puts("");
	}
	
	return 0;
}
