#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <stack>
#include <cassert>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <algorithm>

using namespace std;
typedef long long LL;
#define FOR(k,a,b) for(LL k(a); k < (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<vector<int> > VVI;
typedef vector<bool> VB;


int main()
{
#ifdef HOME
	freopen ("B-small-attempt0.in","r",stdin);
	freopen ("B-small-attempt0.out","w",stdout);
#endif
	int T;
	scanf("%d",&T);
	FOR(testcase,1,T+1)
	{
		int N,M;
		scanf("%d %d",&N,&M);
		VVI v(N,VI(M));
		VVI t(N,VI(M));
		REP(i,N)
			REP(j,M)
			scanf("%d",&v[i][j]);
		VI w(N,0),z(M,0);
		REP(i,N) REP(j,M)
		{
			w[i]=max(w[i],v[i][j]);
			z[j]=max(z[j],v[i][j]);
		}
		REP(i,N) REP(j,M)
			t[i][j]=min(w[i],z[j]);
		bool ok=t==v;
		if(ok)
			printf("Case #%d: YES\n",testcase);
		else
			printf("Case #%d: NO\n",testcase);
	}
	return 0;
} 