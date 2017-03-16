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

struct Item {
	int a, b, c;
	bool operator==(const Item& B)const {
		int com;
		if (com = a - B.a)return a < B.a;
		if (com = b - B.b)return b < B.b;
		return c < B.c;
	}
};

int dp[11][11][11];
int K;
vector<Item> arr;
bool used[1000], ans[1000];
int best;

void solve(int step, int sel) {
	if (sel < best)return;
	if (step == arr.size()) {
		best = sel;
		memcpy(ans, used, sizeof ans);
		return;
	}
	Item& item = arr[step];
	if (dp[0][item.b][item.c] < K
		&& dp[item.a][0][item.c] < K
		&& dp[item.a][item.b][0] < K) {
		used[step] = true;
		++dp[0][item.b][item.c];
		++dp[item.a][0][item.c];
		++dp[item.a][item.b][0];

		solve(step + 1, sel + 1);

		used[step] = false;
		--dp[0][item.b][item.c];
		--dp[item.a][0][item.c];
		--dp[item.a][item.b][0];
	}
	solve(step + 1, sel);
}

int main()
{
	int TC;
	scanf("%d", &TC);
	FOR(T, 1, TC)
	{
		int J, P, S;
		scanf("%d%d%d%d", &J, &P, &S, &K);
		printf("Case #%d: ", T);

		arr.clear();
		FOR(a, 1, J)FOR(b, 1, P)FOR(c, 1, S) {
			arr.push_back(Item{ a,b,c });
		}
		CLEAR(used);
		CLEAR(dp);
		best = 0;
		solve(0, 0);
		const int size = arr.size();
		printf("%d\n", best);
		rep(i, size)if (ans[i]) {
			Item& j = arr[i];
			printf("%d %d %d\n", j.a, j.b, j.c);
		}
	}

	return 0;
}