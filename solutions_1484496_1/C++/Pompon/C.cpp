//Grzegorz Prusak
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i,n)    for(int i=0; i<(n); ++i)
#define FOR(i,p,k)  for(int i=(p); i<=(k); ++i)
#define FORD(i,p,k) for(int i=(p); i>=(k); --i)

typedef long long LL;

enum { n_max = 550 };

int S[30*200000];

struct P
{
	P(){}
	P(LL a) : ac(0), v(a) { A[ac++] = a; }
	P(const P &a, const P &b) : v(b.v-a.v), ac(0)
	{
		REP(i,a.ac) A[ac++] = a.A[i];
		REP(i,b.ac) A[ac++] = -b.A[i];
	}
	LL v,A[40]; int ac;
	bool operator<(const P &p) const { return v<p.v; }

	void print(int _)
	{
		printf("Case #%d:\n",_);
		REP(i,ac) if(A[i]>0) printf("%lld ",A[i]); puts("");
		REP(i,ac) if(A[i]<0) printf("%lld ",-A[i]); puts("");
	}

	void print_p(){ REP(i,ac) if(A[i]>0) printf("%lld ",A[i]); }
	void print_n(){ REP(i,ac) if(A[i]<0) printf("%lld ",-A[i]); }
};

P p[n_max];

int main()
{
	int T; scanf("%d",&T);
	FOR(_,1,T)
	{
		memset(S,0,sizeof S);
		int N; scanf("%d",&N);
		REP(i,N)
		{
			LL a;
			scanf("%lld",&a);
			p[i] = P(a);	
		}
		bool ok = 0;
		std::sort(p,p+N);
		while(N>32)
		{
			if(p[0].v==0){ p[0].print(_); ok = 1; break; }
			REP(i,N/2) p[i] = P(p[2*i],p[2*i+1]); N /= 2;
			std::sort(p,p+N);
		}
		if(ok) continue;

		int NN = 24;
		REP(m,1<<NN)
		{
			int s = 0;
			REP(i,NN) if((m>>i)&1) s += p[i].v;
			if(S[s])
			{
				printf("Case #%d:\n",_);
				REP(i,NN) if((S[s]>>i)&1) p[i].print_p();
				REP(i,NN) if((m>>i)&1) p[i].print_n();
				puts("");
				REP(i,NN) if((S[s]>>i)&1) p[i].print_n();
				REP(i,NN) if((m>>i)&1) p[i].print_p();
				puts("");
				ok = 1; break;
			}
			S[s] = m;
		}
		if(!ok) printf("Case #%d:\nImpossible\n",_);
	}

	return 0;
}
