#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;
const double PI = acos(-1);
const double EPS = 1e-7;

#define PB push_back
#define MP make_pair
#define FOR(_i, _from, _to) for (int (_i) = (_from), (_batas) = (_to); (_i) <= (_batas); (_i)++)
#define REP(_i, _n) for (int (_i) = 0, (_batas) = (_n); (_i) < (_batas); (_i)++)
#define SZ(_x) ((int)(_x).size())

int value[20];
int memo[10][20];
int E, R, N;
inline int DP(int e, int n) {
	if (memo[e][n] != -1) return memo[e][n];
	//printf("masuk %d %d\n", e, n);
	int &ret = memo[e][n];
	ret = 0;
	if (n < N) {
		FOR(i, 0, e) {
			ret = max(ret, i * value[n] + DP(min(e - i + R, E), n+1));
		}
	}
	//printf("memo[%d][%d] = %d\n", e, n, ret);
	return ret;
}

inline void solve(int tc) {
	scanf("%d %d %d", &E, &R, &N);
	REP(i, N) {
		scanf("%d", &value[i]);
	}
	memset(memo, -1, sizeof memo);
	printf("Case #%d: %d\n", tc, DP(E, 0));
}

int main() {
	int T;
	scanf("%d", &T);
	REP(i, T) solve(i+1);
	return 0;
}
