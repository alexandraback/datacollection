#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <set>
//#include <map>
#include <functional>
#include <cmath>

#define fi first
#define se second
#define fo(i,a,b) for (int i = a; i <= b; i ++)
#define fd(i,a,b) for (int i = a; i >= b; i --)
#define SQR(x) ((x)*(x))
#define mkp make_pair
#define pb push_back
#define Fill(x, y) memset(x, y, sizeof(x))

using namespace std;

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;
typedef pair <DB, DB> PD;
typedef pair <PI, PI> PIII;

int Read()
 {
	char c; while (c = getchar(), (c != '-') && (c < '0' || c > '9'));
	bool neg = (c == '-'); int ret = (neg ? 0 : c - 48);
	while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - 48;
	return neg ? -ret : ret;
 }
 
const int MAXN = 10000005;

LL a[MAXN];
LL A, B;
int cnt;

LL rev(LL x)
 {
	LL ret = 0;
	while (x) ret *= 10, ret += (x % 10), x /= 10;
	return ret;
 }
 
void init()
 {
	fo (i, 1, 9999999) if (rev(i) == i)
	 {
		LL ii = (LL) i * (LL) i;
		if (rev(ii) == ii) a[++ cnt] = ii;
	 }
	a[++cnt] = 1 + (LL) 1e14;
 }
 
int main()
 {
	freopen("C.in", "r", stdin), freopen("C.out", "w", stdout);
	init();
	int cases = Read(); fo (cas, 1, cases)
	 {
		cin >> A >> B;
		int ca = upper_bound(a + 1, a + cnt + 1, A - 1) - a, cb = upper_bound(a + 1, a + cnt + 1, B) - a - 1;
		printf("Case #%d: %d\n", cas, cb - ca + 1);
	 }
	return 0;
 }
