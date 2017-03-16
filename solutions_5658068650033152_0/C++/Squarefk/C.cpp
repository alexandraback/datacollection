/*
 * 1.cpp
 *
 *  Created on: 
 *      Author: 
 */

#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>

#include <iostream>
#include <sstream>

#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>

#include <utility>
#include <numeric>
#include <functional>
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

#define MAX_ROW 37
#define MAX_COL 1033

int N, M, K;
int dp[2][MAX_ROW + MAX_COL * 2][2][2][MAX_ROW][MAX_ROW];

void solve(int Case) {
	printf("Case #%d: ", Case);

	scanf("%d %d %d", &N, &M, &K);
	if (N > M) swap(N, M); // N rows, M columns

	int ans = K;
	memset(dp, -1, sizeof(dp));
	Rep(L, 1, N)
		Rep(R, L, N)
			dp[1][R - L + 1][0][0][L][R] = R - L + 1;
	
	Rep(i, 2, M) {
		int now = i & 1, last = now ^ 1;
		Rep(j, 0, N + i + i) Rep(LI, 0, 1) Rep(RI, 0, 1)
			Rep(L, 1, N) Rep(R, L, N)
				dp[now][j][LI][RI][L][R] = -1;
//		memset(dp[now], -1, sizeof(dp[now]));
		
		Rep(j, 1, N + i + i - 4) Rep(LI, 0, 1) Rep(RI, 0, 1)
			Rep(L, 1, N) Rep(R, L, N) {
				int v = dp[last][j][LI][RI][L][R];
				if (v == -1) continue;
				int lb = L, le = L, rb = R, re = R;

				if (LI == 0 && lb - 1 >= 1) --lb;
				else if (le + 1 <= N) ++le;

				if (RI == 0 && re + 1 <= N) ++re;
				else if (rb - 1 >= 1) --rb;

				assert(lb <= le && rb <= re);
				Rep(lp, lb, le) Rep(rp, rb, re) if (lp <= rp) {
					int LIp, RIp;
					if (lp == L) LIp = LI;
					else if (lp < L) {
						LIp = 0;
						assert(LI == 0);
					}
					else {
						LIp = 1;
					}

					if (rp == R) RIp = RI;
					else if (rp > R) {
						RIp = 0;
						assert(RI == 0);
					}
					else RIp = 1;

					int jp = j + 1 + int(lp != rp);
					int vp = v + rp - lp + 1;
					Up(dp[now][jp][LIp][RIp][lp][rp], vp);
				}
				
			}
		Rep(j, 1, N + i + i) Rep(LI, 0, 1) Rep(RI, 0, 1)
			Rep(L, 1, N) Rep(R, L, N) {
				if (dp[now][j][LI][RI][L][R] >= K)
					Down(ans, j + R - L - int(R > L));
			}
	}
	printf("%d\n", ans);
}

int main() {
	int T;
	scanf("%d", &T);
	Rep(Case, 1, T) solve(Case);
	return 0;
}
