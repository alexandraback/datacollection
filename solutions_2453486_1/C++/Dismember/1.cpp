/*
 * 1.cpp
 *
 *  Created on: 2013-4-13
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

int N = 4;
int G[5][5];

bool Check(int a, int b, int c, int d) {
	int A[] = {a, b, c, d},cnt = 0;
	
	cnt = 0;
	Rep(i, 0, 3) if (A[i] == 'O') ++cnt;
	else if (A[i] == 'X') cnt = -100;
	if (cnt == 3 || cnt == 4) {
		printf("O won\n");
		return true;
	}
	
	cnt = 0;
	Rep(i, 0, 3) if (A[i] == 'X') ++cnt;
	else if (A[i] == 'O') cnt = -100;
	if (cnt == 3 || cnt == 4) {
		printf("X won\n");
		return true;
	}
	
	return false;
}

void Solve(int Case) {
	printf("Case #%d: ", Case);
	int cnt = 0;
	Rep(i, 1, N) Rep(j, 1, N) {
		int &c = G[i][j];
		do c = getchar(); while (c != 'O' && c != 'X' && c != 'T' && c != '.');
		if (c == '.') ++cnt;
	}
	if (Check(G[1][1], G[1][2], G[1][3], G[1][4])) return;
	if (Check(G[2][1], G[2][2], G[2][3], G[2][4])) return;
	if (Check(G[3][1], G[3][2], G[3][3], G[3][4])) return;
	if (Check(G[4][1], G[4][2], G[4][3], G[4][4])) return;
	
	if (Check(G[1][1], G[2][1], G[3][1], G[4][1])) return;
	if (Check(G[1][2], G[2][2], G[3][2], G[4][2])) return;
	if (Check(G[1][3], G[2][3], G[3][3], G[4][3])) return;
	if (Check(G[1][4], G[2][4], G[3][4], G[4][4])) return;

	if (Check(G[1][1], G[2][2], G[3][3], G[4][4])) return;
	if (Check(G[1][4], G[2][3], G[3][2], G[4][1])) return;
	
	if (cnt == 0) printf("Draw\n");
	else printf("Game has not completed\n");
}

int main() {
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	Rep(i, 1, T) Solve(i);
	
	return 0;
}
