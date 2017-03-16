// spnauT
//
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int _b=(b),i=(a); i<_b; ++i)
#define ROF(i,b,a) for(int _a=(a),i=(b); i>_a; --i)
#define _1 first
#define _2 second
#define PB(x) push_back(x)
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue <T>
#define MIN_PQ(T) priority_queue <T,vector<T>,greater<T>>
typedef long long LL; typedef long double LD; typedef unsigned int uint;
typedef pair<int,int> PII; typedef pair<LL,LL> PLL;
typedef vector<int> VI; typedef vector<LL> VL; typedef vector<PII> VP;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

#define MAXN (1004)

int T;
int N;
int A[MAXN];

int main()
{
	cin >> T;
	FOR(tt,1,T+1)
	{
		int res = 1e9;

		cin >> N;
		FOR(i,0,N) cin >> A[i];
		FOR(j,1,1001)
		{
			int r = j;
			FOR(i,0,N) r += (A[i]-1) / j;
			mina(res, r);
		}

		printf("Case #%d: %d\n", tt, res);
	}

	return 0;
}
