/*
 * 1.cpp
 *
 *  Created on: 2013-1-1
 *      Author: DebutantGY
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>
#include <string>
#include <bitset>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

#define INF 1000000000
#define LL_INF 4000000000000000000ll
#define EPS (1e-9)

#define Lowbit(x) ((x) & (-(x)))
#define Lc(x) ((x) << 1)
#define Rc(x) (Lc(x) + 1)
#define Pow2(x) (1 << (x))
#define Contain(a, x) (((a) >> (x)) & 1)

#define Rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define Til(i, a, b) for(int i = (a); i >= (b); --i)
#define Foru(i, a, b) for(int i = (a); i < (b); ++i)
#define Ford(i, a, b) for(int i = (a); i > (b); --i)

#define It iterator
#define For(i, x) for(__typeof(x.begin()) i = x.begin(); i != x.end(); ++i)

#define Debug(x) (cerr << #x << " = " << (x) << endl)
#define Debug2(x, y) (cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl)

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> pii;
typedef vector<int> VI;
typedef vector<string> VS;

//inline int rand(int a, int b) { return rand() % (b - a + 1) + a; }

template <class T> inline bool Up(T &a, const T &b) { if(a < b) {a = b; return true;} return false; }
template <class T> inline bool Down(T &a, const T &b) { if(a > b) {a = b; return true;} return false; }

inline int getus() { int tmp, c; while(tmp = fgetc(stdin), tmp < '0' || tmp > '9'); tmp -= '0'; while(c = fgetc(stdin), '0' <= c && c <= '9') tmp = tmp * 10 + c - '0'; return tmp; }
inline int getint() { int tmp, c, flag; while(flag = fgetc(stdin), flag != '-' && (flag < '0' || flag > '9')); if(flag == '-') tmp = 0; else tmp = flag - '0'; while(c = fgetc(stdin), '0' <= c && c <= '9') tmp = tmp * 10 + c - '0'; return flag == '-' ? -tmp : tmp; }

#define MAXN 10023

int E, R, N, V[MAXN];
int opt[123][123];

void Solve(int Case) {
	scanf("%d %d %d", &E, &R, &N);
	Rep(i, 1, N) scanf("%d", V + i);
//	sort(V + 1, V + N + 1);
//	sort(V + 1, V + N + 1, greater<int>());
	
	memset(opt, -63, sizeof(opt));
	opt[0][E] = 0;
	Rep(i, 1, N) Rep(e, 0, E) {
		int x = opt[i - 1][e];
		if (x < 0) continue;
		Rep(c, 0, e)
			Up(opt[i][min(e - c + R, E)], x + c * V[i]);
	}
	
	int ans = 0;
	Rep(e, 0, E) Up(ans, opt[N][e]);
	printf("Case #%d: %d\n", Case, ans);
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int T;
	scanf("%d", &T);
	Rep(i, 1, T) Solve(i);
	
	return 0;
}
