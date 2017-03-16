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
int S;
char C[MAXN];

int main()
{
	cin >> T;
	FOR(tt,1,T+1)
	{
		cin >> S >> C;
		int res = 0;
		int sum = 0;
		FOR(i,0,S+1)
		{
			if(sum < i)
			{
				++sum;
				++res;
			}
			sum += C[i]-'0';
		}
		printf("Case #%d: %d\n", tt, res);
	}

	return 0;
}
