//TAG : 
#include<bits/stdc++.h>//Just in case 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<climits>
#include<functional>
#include<numeric>
using namespace std;
#define rep(i,n)	for(int (i)=0;(i)<(n);(i)++)
#define repd(i,n)	for(int (i)=(n)-1;(i)>=0;(i)--)
#define REP(i,j,n)  for(int (i)=(j),_n=(n); (i) < _n; (i)++)
#define FOR(i,a,b)  for(int _b=(b), (i)=(a); (i) <= _b; (i)++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define CLEAR(x) memset((x),0,sizeof(x))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EPS 	(1e-9)
typedef pair<int, int>	PII;
typedef vector<int>		VI;
typedef unsigned int	uint;
typedef long long		LL;
typedef unsigned long long	ULL;
template<typename T> void check_max(T& a, T b) { if (a < b) a = b; }
template<typename T> void check_min(T& a, T b) { if (a > b) a = b; }
#ifdef _MSC_VER
#include "builtin_gcc_msvc.h"
#define gets	gets_s
#else
#define popcnt(x)	__builtin_popcount(x)
#define ctz(x)		__builtin_ctz(x)
#define clz(x)		__builtin_clz(x)
#define popcntll(x)	__builtin_popcountll(x)
#define ctzll(x)	__builtin_ctzll(x)
#define clzll(x)	__builtin_clzll(x)
#endif

const int MAXN = 18 + 2;
char line[2][MAXN];
char ans[2][MAXN];
int len;

LL ipow(LL n, int k) {
	LL res = 1;
	while (k-- > 0)res *= n;
	return res;
}

typedef pair<LL, LL> pll;
pll dp[MAXN][5][5];

//a,b ? direction
pll solve(int step, int a, int b) {
	if (step == len)
		return MP(0LL, 0LL);
	pll& ret = dp[step][a + 1][b + 1];
	if (ret.X == -1) {
		rep(i, 2)ans[i][step] = line[i][step];
		char &A = ans[0][step], &B = ans[1][step];
		LL ten = ipow(10, len - 1 - step);

		//direction determined
		if (a && b) {
			rep(i, 2) {
				int j = i == 0 ? a : b;
				if (ans[i][step] == '?') {
					if (j > 0)ans[i][step] = '9';
					else ans[i][step] = '0';
				}
			}
		} else if (A == '?' || B == '?') {
			LL gap = LLONG_MAX;
			pll best = MP(0, 0);
			if (A == '?' && B == '?') {
				FOR(A1, '0', '1') {
					FOR(B1, '0', A1 == '0' ? '1' : '0') {
						pll r;
						if (A1 < B1) {
							r = solve(step + 1, 1, -1);
						} else if (A1 > B1) {
							r = solve(step + 1, -1, 1);
						} else {
							r = solve(step + 1, a, b);
						}
						r = MP((A1 - '0')*ten + r.X, (B1 - '0')*ten + r.Y);
						LL g = abs(r.X - r.Y);
						if (gap > g) {
							gap = g, best = r;
						} else if (gap == g) {
							check_min(best, r);
						}
					}
				}
			} else if (A == '?') {
				char B1 = B;
				FOR(A1, max((int)'0', B1 - 1), min((int)'9', B1 + 1)) {
					pll r;
					if (A1 < B1) {
						r = solve(step + 1, 1, -1);
					} else if (A1 > B1) {
						r = solve(step + 1, -1, 1);
					} else {
						r = solve(step + 1, a, b);
					}
					r = MP((A1 - '0')*ten + r.X, (B1 - '0')*ten + r.Y);
					LL g = abs(r.X - r.Y);
					if (gap > g) {
						gap = g, best = r;
					} else if (gap == g) {
						check_min(best, r);
					}
				}
			} else if (B == '?') {
				char A1 = A;
				FOR(B1, max((int)'0', A1 - 1), min((int)'9', A1 + 1)) {
					pll r;
					if (A1 < B1) {
						r = solve(step + 1, 1, -1);
					} else if (A1 > B1) {
						r = solve(step + 1, -1, 1);
					} else {
						r = solve(step + 1, a, b);
					}
					r = MP((A1 - '0')*ten + r.X, (B1 - '0')*ten + r.Y);
					LL g = abs(r.X - r.Y);
					if (gap > g) {
						gap = g, best = r;
					} else if (gap == g) {
						check_min(best, r);
					}
				}
			}
			return ret = best;
		} else {
			if (A < B) {
				pll r = solve(step + 1, 1, -1);
				return ret = MP((A - '0')*ten + r.X, (B - '0')*ten + r.Y);
			} else if (A > B) {
				pll r = solve(step + 1, -1, 1);
				return ret = MP((A - '0')*ten + r.X, (B - '0')*ten + r.Y);
			}
		}
		pll r = solve(step + 1, a, b);
		return ret = MP((A - '0')*ten + r.X, (B - '0')*ten + r.Y);
	}
	return ret;
}

void print(LL n, char* s, int len) {
	repd(i, len) {
		s[i] = (n % 10) + '0';
		n /= 10;
	}
	s[len] = 0;
}

int main()
{
	int TC;
	scanf("%d", &TC);
	FOR(T, 1, TC)
	{
		scanf("%s %s", line[0], line[1]);
		len = strlen(line[0]);
		CLEAR(ans);
		//clear dp
		memset(dp, -1, sizeof(dp));
		pll r = solve(0, 0, 0);
		print(r.X, ans[0], len);
		print(r.Y, ans[1], len);
		printf("Case #%d: %s %s\n", T, ans[0], ans[1]);
	}

	return 0;
}