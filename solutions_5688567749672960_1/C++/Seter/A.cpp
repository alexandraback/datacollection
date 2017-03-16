//Orz Sevenkplus
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <complex>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#define un using namespace
un std;
#define pb push_back
#define pf pop_front

#define mp make_pair

#define c0 first
#define c1 second
#define sqr(x) ((x)*(x))
#define clr(x) memset(x, 0, sizeof(x))
#define clr1(x) memset(x, -1, sizeof(x))
#define clr80(x) memset(x, 0x80, sizeof(x))
#define clr7F(x) memset(x, 0x7F, sizeof(x))

#define LL long long
#ifdef __unix__
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif
#define pii pair<int, int>
#define pip pair<int, pii>
#define vi vector<int>
#define vpi vector<pii>
#define pq priority_queue

template<typename T>
inline bool chkmin(T &a, T b){return a > b ? a = b, 1 : 0;}
template<typename T>
inline bool chkmax(T &a, T b){return a < b ? a = b, 1 : 0;}

#define P 1000000007

LL r(LL x) {
	char z[16];
	sprintf(z, LLD, x);
	LL p = 1, y = 0;
	for (int i = 0; z[i]; i++) {
		y += p * (z[i] - '0');
		p *= 10;
	}
	return y;
}

LL solve(LL n) {
	if (n < 10)
		return n;
	char z[16];
	sprintf(z, LLD, n);
	int l = strlen(z);
	LL p = 1;
	for (int t = (l + 1) >> 1; t--; )
		p *= 10;
	LL m = n % p;
	if (m == 0)
		return solve(n - 1) + 1;
	if (m != 1)
		return solve(n - (m - 1)) + (m - 1);
	LL rn = r(n);
	if (rn == n)
		return solve(n - 1) + 1;
	else
		return solve(rn) + 1;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int _ = 1; _ <= t; _++) {
		LL n;
		scanf(LLD, &n);
		printf("Case #%d: "LLD"\n", _, solve(n));
	}
	return 0;
}
