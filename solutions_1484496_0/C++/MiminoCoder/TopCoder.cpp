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

int N, in[20];

void Solve(int tc)
{
	scanf("%d", &N);
	REP(i, N) scanf("%d", &in[i]);

	map<int, int> used;
	int res1 = -1, res2;
	REP(i, two(N))
	{
		if (!i) continue;
		int sum = 0;
		REP(j, N)
			if (test(i, j)) sum += in[j];
		map<int, int>::iterator iter = used.find(sum);
		if (iter == used.end())
			used[sum] = i;
		else
		{
			res1 = iter->second;
			res2 = i;
			break;
		}
	}

	printf("Case #%d:\n", tc);
	if (res1 == -1)
		printf("Impossible\n");
	else
	{
		REP(i, N)
			if (test(res1, i)) printf("%d ", in[i]);
		printf("\n");
		REP(i, N)
			if (test(res2, i)) printf("%d ", in[i]);
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