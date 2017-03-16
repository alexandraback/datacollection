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
typedef long long LL;typedef pair<int,int> PII;
typedef vector<int>VI;typedef vector<LL>VL;typedef vector<PII>VP;
template<class A,class B>inline bool mina(A &x,const B &y){return(y<x)?(x=y,1):0;}
template<class A,class B>inline bool maxa(A &x,const B &y){return(x<y)?(x=y,1):0;}

#define MAXN ()

const string A = "0264831579";
const string B = "ZWXUGHOFSE";
int C[128];
int D[64];
const string E[10] = {"ZERO", "TWO", "SIX", "FOUR", "EIGHT", "THREE", "ONE", "FIVE", "SEVEN", "NINE"};

int main()
{
	IO();
	cint1(TT);
	FOR(T,1,TT+1)
	{
		string S;
		cin >> S;
		for(char c: S) ++C[int(c)];
		MSET(D,0);

		int l = 0;
		FOR(i,0,10) REP(C[int(B[i])])
		{
			++l;
			++D[int(A[i])];
			for(char c: E[i]) --C[int(c)];
		}

		string sol;
		sol.reserve(l);
		FOR(i,'0','0'+10) REP(D[i]) sol.PB(i);
		cout << "Case #" << T << ": " << sol << nl;
	}

	return 0;
}