//Grzegorz Prusak
#include <cstdio>

#define REP(i,n)    for(int i=0; i<(n); ++i)
#define FOR(i,p,k)  for(int i=(p); i<=(k); ++i)
#define FORD(i,p,k) for(int i=(p); i>=(k); --i)

typedef long long LL;

struct Dec
{
	Dec(int v) : c(0) { for(;v; v/=10) D[c++] = v%10; }
	operator int*(){ return D; }
	int D[8],c;

	int cycle()
	{
		FOR(i,1,c) //equally good you can just browse the divisors of c 
		{
			bool same = 1;
			REP(j,c) if(D[j]!=D[(i+j)%c]){ same = 0; break; }
			if(same) return i;
		}
	}
};

int greater(Dec n, Dec L)
{
	if(L.c>n.c) return 0;
	int res = 0;
	REP(i,n.cycle())
	{
		FORD(j,L.c-1,0)
		{
			int ld = L[j], nd = n[(j+i)%n.c];
			if(ld<nd) res++;
			if(ld!=nd) break;
		}
	}
	return res;
}

int main()
{
	int T; scanf("%d",&T);
	FOR(_,1,T)
	{
		LL res = 0;
		int A,B; scanf("%d%d",&A,&B);
		FOR(n,A,B) res += greater(n,n)-greater(n,B);
		printf("Case #%d: %lld\n",_,res);
	}

	return 0;
}

