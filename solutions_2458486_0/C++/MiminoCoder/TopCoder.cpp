#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std; 

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return n & two(b); }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int MAX = 207;
int K, N;

int have[MAX]; // keys, that I have
int need[MAX]; // key needed for the chest
vector<int> gain[MAX];

int dp[1<<20];

void use(int chest, int sign)
{
	have[need[chest]] -= sign;
	REP(i, gain[chest].size())
		have[gain[chest][i]] += sign;
}

int go(int state)
{
	if (!state)
		return true;
	int & res = dp[state];
	if (res != -1) return res;

	res = 0;
	REP(i, N)
	{
		if (test(state, i) && have[need[i]])
		{
			use(i, 1);
			res |= go(state ^ two(i));
			use(i, -1);
			if (res) break;
		}
	}
	return res;
}

void Solve(int tc)
{
	scanf("%d%d", &K, &N);
	memset(have, 0, sizeof(have));
	REP(i, K)
	{
		int k;
		scanf("%d", &k);
		++have[k];
	}
	REP(i, N)
	{
		int ki, k;
		scanf("%d%d", &need[i], &ki);
		gain[i].clear();
		REP(j, ki)
		{
			scanf("%d", &k);
			gain[i].push_back(k);
		}
	}
	printf("Case #%d: ", tc);

	memset(dp, -1, sizeof(dp));
	int state = two(N) - 1;
	if (!go(state))
		printf("IMPOSSIBLE\n");
	else
	{
		while (state)
		{
			int n;
			REP(i, N)
				if (test(state, i) && have[need[i]])
				{
					use(i, 1);
					if (go(state ^ two(i)))
					{
						n = i;
						break;
					}
					use(i, -1);
				}
			if (state != two(N) - 1)
				printf(" ");
			printf("%d", n + 1);
			state ^= two(n);
		}
		printf("\n");
	}
}

int main()
{
	int T;
	scanf("%d\n", &T);
	FOR(tc,1,T) Solve(tc);

	return 0;
}
