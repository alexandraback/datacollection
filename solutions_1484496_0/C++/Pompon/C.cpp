//Grzegorz Prusak
#include <cstdio>
#include <cstring>

#define REP(i,n)    for(int i=0; i<(n); ++i)
#define FOR(i,p,k)  for(int i=(p); i<=(k); ++i)
#define FORD(i,p,k) for(int i=(p); i>=(k); --i)

enum { n_max = 550 };

int S[20*200000];
int l[n_max];

int main()
{
	int T; scanf("%d",&T);
	FOR(_,1,T)
	{
		memset(S,0,sizeof S);
		int N; scanf("%d",&N);
		REP(i,N) scanf("%d",l+i);
		bool ok = 0;
		REP(m,1<<N)
		{
			int s = 0;
			REP(i,N) if((m>>i)&1) s += l[i];
			if(S[s])
			{
				printf("Case #%d:\n",_);
				REP(i,N) if((S[s]>>i)&1) printf("%d ",l[i]); puts("");
				REP(i,N) if((m>>i)&1) printf("%d ",l[i]); puts("");
				ok = 1; break;
			}
			S[s] = m;
		}
		if(!ok) printf("Case #%d:\nImpossible\n",_);
	}

	return 0;
}
