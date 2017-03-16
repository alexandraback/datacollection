#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <cassert>

#define oo 1000111000

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define FOREACH(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)

#define PB push_back
#define MP make_pair
#define SIZE(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
#define RESET(c,x) memset(c,x,sizeof(c))
#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <class T> inline T MAX(T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN(T a, T b) { if (a < b) return a; return b; }
template <class T> inline T ABS(T x) { if (x < 0) return -x; return x; }

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

// template by ptrrsn_1

#define MAXN 20

inline bool check(int y0, int x1, int y1) {
	int x2 = 0;
	int y2 = y0;
	
	int x3 = 0;
	int y3 = y0;
	
	while (y2 >= 0) {
		int y = y2;
		for (int x = x2; x <= x3; x += 2) {
			if (x == x1 && y == y1) return true;
		}
		
		x2--;
		y2--;
		x3++;
		y3--;
	}
	return false;
}

int nTC;
int N, X, Y;
double dp[MAXN + 2][MAXN + 2][MAXN + 2][MAXN + 2];

double doDP(int left, int middle, int right, int k) {
	double &ret = dp[left][middle][right][k];
	if (ret == ret) return ret;
	
	if (k == N) {
		// check if X, Y is inside!
		if (check(middle - 1, X, Y)) ret = 1.0;
		else if (check(left - 1, X + ((middle - left) + 2), Y)) ret = 1.0;
		else if (check(right - 1, X - ((middle - right) + 2), Y)) ret = 1.0;
		else ret = 0.0;
		return ret;
	} else {
		ret = 0;
		if (left > middle && right > middle) {
			ret += doDP(0, middle + 2, 0, k + 1);
		} else if (left > middle) {
			ret += doDP(left, middle, right + 1, k + 1);
		} else if (right > middle) {
			ret += doDP(left + 1, middle, right, k + 1);
		} else {
			ret += 0.5 * doDP(left + 1, middle, right, k + 1);
			ret += 0.5 * doDP(left, middle, right + 1, k + 1);
		}
		return ret;
	}
}

int main() {
	scanf("%d", &nTC);
	
	FOR (tc, 1, nTC) {
		RESET(dp, -1);
		scanf("%d%d%d", &N, &X, &Y);
		printf("Case #%d: %.10lf\n", tc, doDP(0, 1, 0, 1));
	}
	
	return 0;
}

