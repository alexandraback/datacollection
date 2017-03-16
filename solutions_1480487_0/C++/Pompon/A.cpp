//Grzegorz Prusak
#include <cstdio>
#include <algorithm>

#define REP(i,n)    for(int i=0; i<(n); ++i)
#define FOR(i,p,k)  for(int i=(p); i<=(k); ++i)
#define FORD(i,p,k) for(int i=(p); i>=(k); --i)

typedef long long LL;

struct Z
{
	Z(){}
	Z(int _i, double _p) : i(_i), p(_p) {}
	int i;
	double p;
	bool operator<(const Z &b) const { return p<b.p; }
};

Z l[300];
double r[300];
int main()
{
	int T; scanf("%d",&T);
	FOR(_,1,T)
	{
		int N; scanf("%d",&N);
		REP(i,N)
		{
			int p; scanf("%d",&p);
			l[i] = Z(i,p);
		}
		int s = 0;
		REP(i,N) s += l[i].p;
		REP(i,N) l[i].p /= s;
		std::sort(l,l+N);
		double g = 0;
		REP(i,N) if(i<N-1)
		{
			g += (i+1)*(l[i+1].p-l[i].p);
			if(g>1){ g = l[i+1].p-(g-1)/(i+1); break; }
		}
		else g = l[i].p+(1-g)/N;
		REP(i,N) r[l[i].i] = 100*std::max(g-l[i].p,0.);
		printf("Case #%d: ",_); REP(i,N) printf("%.7lf ",r[i]); puts("");
	}
	return 0;
}

