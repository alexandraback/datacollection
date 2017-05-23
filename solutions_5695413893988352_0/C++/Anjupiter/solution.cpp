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

template<typename T> T ipow(T n, int k) {
	T res = 1;
	while (k-- > 0)res *= n;
	return res;
}

void print(int n, char* s, int len) {
	repd(i, len) {
		s[i] = (n % 10) + '0';
		n /= 10;
	}
	s[len] = 0;
}

//a is origin
bool isok(char* a, char* b, int len) {
	rep(i, len)if (a[i] != '?' && a[i] != b[i]) {
		return false;
	}
	return true;
}

int main()
{
	int TC;
	scanf("%d", &TC);
	FOR(T, 1, TC)
	{
		scanf("%s %s", line[0], line[1]);
		len = strlen(line[0]);
		int ten = ipow(10, len);
		int gap = ten, a = 0, b = 0;
		rep(i, ten) {
			print(i, ans[0], len);
			if (!isok(line[0], ans[0], len))continue;
			rep(j, ten) {
				print(j, ans[1], len);
				if (!isok(line[1], ans[1], len))continue;
				int g = abs(i - j);
				if (gap > g) {
					gap = g, a = i, b = j;
				} else if (gap == g) {
					if (i < a)a = i, b = j;
					else if (i == a && j < b)a = i, b = j;
				}
			}
		}
		print(a, ans[0], len);
		print(b, ans[1], len);
		printf("Case #%d: %s %s\n", T, ans[0], ans[1]);
	}

	return 0;
}