/*
 * 3.cpp
 *
 *  Created on: 2013-4-12
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

LL P[5000000];
int totP = 0;

bool isP(LL t) {
	static int s[100];
	int l = 0;
	do s[l++] = t % 10; while (t /= 10);
	for (int left = 0, right = l - 1; left < right; ++left, --right)
		if (s[left] != s[right]) return false;
	return true;
}

void getP() {
	Rep(i, 1, 10000000) if (isP(i)) if (isP(LL(i) * i)) {
		Debug(i);
		P[++totP] = LL(i) * i;
	}
}

void Solve(int Case) {
	LL A, B;
	cin >> A >> B;
	int l = lower_bound(P + 1, P + totP + 1, A) - P;
	int r = upper_bound(P + 1, P + totP + 1, B) - P;
	printf("Case #%d: %d\n", Case, r - l);
}

int main() {
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	
	getP();
	
	int T;
	scanf("%d", &T);
	Rep(i, 1, T) Solve(i);
	
	return 0;
}
