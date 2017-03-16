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

const int MAXN = 2002;

int main()
{
	char line[MAXN];
	int cnt[26];
	int num[10][26] = {};
	int check[10] = {};
	int det[10][10] = {};
	int ans[10];

	char* name[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
	rep(i, 10) {
		int len = strlen(name[i]);
		rep(j, len) {
			int ch = name[i][j] - 'A';
			++num[i][ch];
			check[i] |= 1 << ch;
		}
	}
	int d = (1 << 10) - 1;
	rep(step, 10) {
		if (d == 0)
			break;
		int d2 = 0;
		rep(i, 10)if ((d >> i) & 1) {
			det[step][i] = check[i];
			rep(j, 10)if (i != j && ((d >> j) & 1))
				det[step][i] &= ~check[j];
			if (det[step][i])d2 |= 1 << i;
		}
		d &= ~d2;
	}

	int TC;
	scanf("%d", &TC);
	FOR(T, 1, TC)
	{
		scanf("%s", line);
		CLEAR(cnt), CLEAR(ans);
		for (char* p = line; *p; ++p)
			++cnt[*p - 'A'];
		rep(step, 10) {
			rep(i, 10)if (det[step][i]) {
				int ch = ctz(det[step][i]);
				int j = cnt[ch] / num[i][ch];
				if (j) {
					ans[i] += j;
					for (int c = check[i]; c; c &= c - 1) {
						int ch2 = ctz(c);
						cnt[ch2] -= j*num[i][ch2];
					}
				}
			}
		}
		rep(i, 26)if (cnt[i])
			throw "error";

		int len = 0;
		rep(i, 10)if (ans[i]) {
			memset(line + len, '0' + i, ans[i]);
			len += ans[i];
		}
		line[len] = 0;
		printf("Case #%d: %s\n", T, line);
	}

	return 0;
}