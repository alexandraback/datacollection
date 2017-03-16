//Grzegorz Prusak
#include <cstdio>

#define REP(i,n)    for(int i=0; i<(n); ++i)
#define FOR(i,p,k)  for(int i=(p); i<=(k); ++i)
#define FORD(i,p,k) for(int i=(p); i>=(k); --i)

int main()
{
	int T; scanf("%d",&T);
	FOR(_,1,T)
	{
		int res = 0;
		int N,S,p; scanf("%d%d%d",&N,&S,&p);
		REP(i,N)
		{
			int v; scanf("%d",&v);
			int  d = v/3, r = v%3;
			if(d+bool(r)>=p) res++; else 
			if(S && ((!r && d && d+1>=p) || (r==2 && d+2>=p))){ res++; S--; }
		}
		printf("Case #%d: %d\n",_,res);
	}

	return 0;
}

