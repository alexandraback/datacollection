// spnauT
//
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int _b=(b),i=(a);i<_b;++i)
#define ROF(i,b,a) for(int _a=(a),i=(b);i>_a;--i)
#define REP(n) for(int _n=(n);_n--;)
#define _1 first
#define _2 second
#define PB(x) push_back(x)
#define SZ(x) int((x).size())
#define ALL(x) (x).begin(),(x).end()
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue<T>
#define MIN_PQ(T) priority_queue<T,vector<T>,greater<T>>
#define IO(){ios_base::sync_with_stdio(0);cin.tie(0);}
#define nl '\n'
#define cint1(a) int a;cin>>a
#define cint2(a,b) int a,b;cin>>a>>b
#define cint3(a,b,c) int a,b,c;cin>>a>>b>>c
typedef long long LL;typedef pair<int,int> PII;typedef pair<LL,LL> PLL;
typedef vector<int>VI;typedef vector<LL>VL;typedef vector<PII>VP;
template<class A,class B>inline bool mina(A &x,const B &y){return(y<x)?(x=y,1):0;}
template<class A,class B>inline bool maxa(A &x,const B &y){return(x<y)?(x=y,1):0;}

#define MAXN (20)

LL dp1[MAXN][10][10][4];
LL dp2[MAXN][10][10][4];
PLL dp3[MAXN][10][10][4];
LL D[MAXN];

inline void up(int n, int a, int b, int c, LL t, PLL p)
{
	if(maxa(dp2[n+1][a][b][c],1))
	{
		dp1[n+1][a][b][c] = dp1[n+1][a][b][c+1] = t;
		dp2[n+1][a][b][c+1] = 1;
		dp3[n+1][a][b][c] = dp3[n+1][a][b][c+1] = p;
	}
	else
	{
		if(mina(dp1[n+1][a][b][c], t))
			dp3[n+1][a][b][c] = p;
		else if(dp1[n+1][a][b][c] == t)
			mina(dp3[n+1][a][b][c], p);

		if(maxa(dp1[n+1][a][b][c+1], t))
			dp3[n+1][a][b][c+1] = p;
		else if(dp1[n+1][a][b][c+1] == t)
			mina(dp3[n+1][a][b][c+1], p);
	}
}

int main()
{
	IO();

	D[0] = 1;
	FOR(i,1,MAXN) D[i] = D[i-1]*10;
	cint1(TT);
	FOR(T,1,TT+1)
	{
		string A,B;
		cin >> A >> B;
		int N = SZ(A);
		MSET(dp2,0);
		dp2[0][0][0][1] = dp2[0][0][0][2] = 1;

		FOR(i,0,N)
		{
			char ca = A[N-i-1];
			char cb = B[N-i-1];
			FOR(aa,0,10) FOR(bb,0,10) FOR(j,0,4) if(dp2[i][aa][bb][j])
			{
				PLL p1 = dp3[i][aa][bb][j];
				FOR(a,0,10) if(ca == '?' || a+'0' == ca)
				{
					FOR(b,0,10) if(cb == '?' || b+'0' == cb)
					{
						PLL p(p1._1 + D[i]*a, p1._2 + D[i]*b);
						LL t = p._2 - p._1;
						if(t <= 0) up(i,a,b,0,t,p);
						if(t >= 0) up(i,a,b,2,t,p);
					}
				}
			}
		}

		LL res = 1LL << 60;
		PLL sol;
		FOR(a,0,10) FOR(b,0,10) FOR(c,0,4) if(dp2[N][a][b][c])
		{
			LL t = abs(dp1[N][a][b][c]);
			PLL p = dp3[N][a][b][c];
			if(mina(res, t)) sol = p;
			else if(res == t) mina(sol, p);
		}

		printf("Case #%d: %0*lld %0*lld\n", T, N, sol._1, N, sol._2);
	}

	return 0;
}