//Grzegorz Prusak
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,p,k) for(int i=(p); i<=(k); ++i)
#define FORD(i,p,k) for(int i=(p); i>=(k); --i)

typedef long long LL;

enum { n_max = 200 };

template<typename T> void checkmax(T &a, T b){ if(a<b) a = b; }

int A[n_max][n_max];
int N[n_max],M[n_max];

int main()
{
	int t; scanf("%d",&t);
	FOR(_,1,t)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		REP(nn,n) REP(mm,m) scanf("%d",&A[nn][mm]);
		memset(N,0,sizeof N);
		memset(M,0,sizeof M);
		REP(nn,n) REP(mm,m)
		{
			checkmax(N[nn],A[nn][mm]);
			checkmax(M[mm],A[nn][mm]);
		}
		bool ok = 1;
		REP(nn,n) REP(mm,m) ok &= A[nn][mm]==N[nn] || A[nn][mm]==M[mm];
		printf("Case #%d: %s\n",_,ok ? "YES" : "NO");
	}
	return 0;
}
