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

int R, N, M, K;
int A[10], Subset[10];
bool done;

void Check() {
	static int mul[33];
	
	Foru(i, 0, Pow2(N)) {
		int &res = mul[i] = 1;
		Foru(j, 0, N) if (Contain(i, j))
			res *= A[j + 1];
	}
	Rep(k, 1, K) {
		bool good = false;
		Foru(s, 0, Pow2(N)) if (Subset[k] == mul[s]) {
			good = true;
			break;
		}
		if (!good) return;
	}
	done = true;
	Rep(i, 1, N) printf("%d", A[i]); puts("");
}

void DFS(int i) {
	if (i == N + 1) {
		Check();
		return;
	}
	for (int &v = A[i] = 2; v <= M; ++v) {
		DFS(i + 1);
		if (done) return;
	}
}

void Solve() {
	scanf("%d %d %d %d", &R, &N, &M, &K);
	while (R--) {
		Rep(i, 1, K) scanf("%d", Subset + i);
		done = false;
		DFS(1);
		if (!done) {
			Rep(i, 1, N) printf("%d", 1); puts("");
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	puts("Case #1:");
	Solve();
	return 0;
}
