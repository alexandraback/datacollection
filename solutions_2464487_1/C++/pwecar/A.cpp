#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <cmath>

#define Fill(x,y) memset(x, y, sizeof(x))
#define Cpy(x,y) memcpy(x, y, sizeof(x))
#define fi first
#define se second
#define pb push_back
#define fo(i,a,b) for (int i = a; i <= b; i ++)
#define fd(i,a,b) for (int i = a; i >= b; i --)
#define SQR(x) ((x)*(x))
#define mkp make_pair

using namespace std;

typedef double DB;
typedef long long LL;
typedef pair <LL, LL> PL;
typedef pair <int, int> PI;
typedef pair <DB, DB> PD;
typedef pair <PI, PI> PIII;
typedef pair <PD, DB> LINE;

int Read()
 {
	char c; while (c = getchar(), (c != '-') && (c < '0' || c > '9'));
	bool neg = (c == '-'); int ret = (neg ? 0 : c - 48);
	while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - 48;
	return neg ? -ret : ret;
 }

LL R, T;

LL SumSquare(LL n)
 {
	LL n2 = n + 1, n3 = n + n + 1;
	if (n % 2) n2 /= 2; else n /= 2;
	if (!(n % 3)) n /= 3;
	else if (!(n2 % 3)) n2 /= 3;
	else n3 /= 3;
	return n * n2 * n3;
 }
 
int main()
 {
	freopen("A.in", "r", stdin), freopen("A.out", "w", stdout);
	int cases = Read(); fo (cas, 1, cases)
	 {
		cin >> R >> T;
		LL l = 1, r = min(T / (2 * R), 707106780LL), ans = 0;
		while (l <= r)
		 {
			LL mid = (l + r) / 2;
			LL s = 2 * mid * R + SumSquare(mid + mid - 1) - 8 * SumSquare(mid - 1);
			if (s <= T) ans = mid, l = mid + 1; else r = mid - 1;
		 }
		 
		printf("Case #%d: %lld\n", cas, ans);
	 }
 }
