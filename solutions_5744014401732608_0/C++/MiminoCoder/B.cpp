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

#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
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

const int MAX = 52;
int B, mat[MAX][MAX];
ll M, maxim[MAX];

void Solve(int tc) {
	scanf("%d%lld", &B, &M);
	printf("Case #%d: ", tc);
	if (maxim[B-1] < M) { printf("IMPOSSIBLE\n"); return; }
	printf("POSSIBLE\n");
	memset(mat, 0, sizeof(mat));

	int i = 1;
	for (; i < B && maxim[i] <= M; ++i) {
		for (int j = 0; j < i; ++j)
			mat[j][i] = 1;
	}
	if (maxim[i] != M) {
		int j = 1;
		while (M) {
			mat[j][i] = M%2;
			M /= 2;
			++j;
		}
		++i;
	}
	for (; i < B; ++i)
		mat[i-1][i] = 1;

	REP(i, B) {
		REP(j, B) printf("%d", mat[i][j]);
		printf("\n");
	}
}

int main()
{
	maxim[0] = 1;
	FOR(i, 1, MAX-1)
		REP(j, i) maxim[i] += maxim[j];
	//REP(i, MAX) cout << i << ": " << maxim[i] << endl;

	int T;
	scanf("%d\n", &T);
	FOR(tc,1,T) {
		cerr << "Test case: " << tc << endl;
		Solve(tc);
	}

	return 0;
}