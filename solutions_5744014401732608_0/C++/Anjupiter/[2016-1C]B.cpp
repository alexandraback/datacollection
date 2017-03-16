//TAG : 
#include<bits/stdc++.h>//Just in case 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<climits>
#include<functional>
#include<numeric>
using namespace std;
#define rep(i,n)	for(int (i)=0;(i)<(n);(i)++)
#define repd(i,n)	for(int (i)=(n)-1;(i)>=0;(i)--)
#define REP(i,j,n)  for(int (i)=(j),_n=(n); (i) < _n; (i)++)
#define FOR(i,a,b)  for(int _b=(b), (i)=(a); (i) <= _b; (i)++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define CLEAR(x) memset((x),0,sizeof(x))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EPS 	(1e-9)
typedef pair<int, int>	PII;
typedef vector<int>		VI;
typedef unsigned int	uint;
typedef long long		LL;
typedef unsigned long long	ULL;
template<typename T> void check_max(T& a, T b) { if (a < b) a = b; }
template<typename T> void check_min(T& a, T b) { if (a > b) a = b; }
#ifdef _MSC_VER
#include "builtin_gcc_msvc.h"
#define gets	gets_s
#else
#define popcnt(x)	__builtin_popcount(x)
#define ctz(x)		__builtin_ctz(x)
#define clz(x)		__builtin_clz(x)
#define popcntll(x)	__builtin_popcountll(x)
#define ctzll(x)	__builtin_ctzll(x)
#define clzll(x)	__builtin_clzll(x)
#endif

const int MAXN = 50;

int main()
{
	char board[MAXN][MAXN + 1];

	int TC;
	scanf("%d", &TC);
	FOR(T, 1, TC)
	{
		int B;
		LL M;
		scanf("%d %lld", &B, &M);
		LL way = 1LL << (B - 2);
		printf("Case #%d: ", T);
		if (M <= way) {
			puts("POSSIBLE");
			CLEAR(board);
			rep(i, B) {
				memset(board[i], '0', B);
				if (i) {
					REP(j, i + 1, B)
						board[i][j] = '1';
				}
			}
			//Process
			if (M == way) {
				REP(j, 1, B)board[0][j] = '1';
			} else {
				while (M > 0) {
					int j = ctzll(M);
					board[0][B - 2 - j] = '1';
					M &= M - 1;
				}
			}
			rep(i, B)puts(board[i]);
		} else {
			puts("IMPOSSIBLE");
		}
	}

	return 0;
}