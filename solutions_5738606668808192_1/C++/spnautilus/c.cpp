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

const int N = 32;
const int J = 500;
const int BADASS = 11;

LL sol[J][12];
int soln;

int main()
{
	IO();

	FOR(b0,1,J+1)
	{
		int b = b0*2 + 1;
		int l = 32-__builtin_clz(b);
		sol[soln][0] = (b << (32-l)) | (b << BADASS) | b;
		FOR(i,2,11)
		{
			LL a = 0;
			LL p = 1;
			FOR(j,0,l)
			{
				if((b>>j) & 1) a += p;
				p *= i;
			}
			sol[soln][i] = a;
		}
		++soln;
	}
	cout << "Case #1:" << nl;
	FOR(i,0,J)
	{
		cout << bitset<N>(sol[i][0]);
		FOR(j,2,11) cout << ' ' << sol[i][j];
		cout << nl;
	}

	return 0;
}