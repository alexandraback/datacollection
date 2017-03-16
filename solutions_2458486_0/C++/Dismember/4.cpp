/*
 * 4.cpp
 *
 *  Created on: 2013-4-4
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


int K, N, opt[1 << 20];
VI key[20];
int curKey[40], toOpen[20];

int DP(int S) {
	int &res = opt[S];
	if (res < N || res == INF) return res;
	if (S == Pow2(N) - 1) return -1;
	res = INF;
	Foru(i, 0, N) if (!Contain(S, i)) {
		int t = toOpen[i];
		if (curKey[t]) {
			--curKey[t];
			For(itr, key[i]) ++curKey[*itr];
			
			if (DP(S | Pow2(i)) < INF) {
				Down(res, i);
				break;
			}
			
			++curKey[t];
			For(itr, key[i]) --curKey[*itr];
		}
	}
	return res;
}

void Solve(int Case) {
	printf("Case #%d:", Case);
	memset(curKey, 0, sizeof(curKey));
	memset(opt, 63, sizeof(opt));
	Foru(i, 0, 20) key[i].clear();
	
	scanf("%d %d", &K, &N);
	Debug2(K, N);
	Rep(i, 1, K) {
		int a;
		scanf("%d", &a);
		++curKey[a - 1];
	}
	
	Foru(i, 0, N) {
		scanf("%d %d", toOpen + i, &K);
		--toOpen[i];
		for (key[i].reserve(K); K--; ) {
			int a;
			scanf("%d", &a);
			key[i].push_back(a - 1);
		}
	}
	if (DP(0) >= INF) {
		printf(" IMPOSSIBLE\n");
		return;
	}
	for (int k = 0; k != Pow2(N) - 1; k |= Pow2(opt[k]))
		printf(" %d", opt[k] + 1);
	putchar('\n');
}

int main() {
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	Rep(Case, 1, T) Solve(Case);
	return 0;
}
