// #include C/C++ {
#include <bits/stdc++.h>
// }
using namespace std;
// #typedef {
typedef long long int64;
typedef unsigned long long uint64;
typedef pair <int, int> PII;
typedef pair <int64, int64> PLL;
typedef pair <double, double> PDD;
// }

// #parameter{
#define LEN 2
#ifdef DEBUG_MODE

#define TYPE decltype
#define RF(filename) {freopen((filename), "r", stdin);}
#define WF(filename) {freopen((filename), "w", stdout);}
#define DEBUG printf

#else

#define TYPE __typeof
#define RF(filename) {;}
#define WF(filename) {;}
#define DEBUG(...)

#endif

// #define {
#define SZ(a) ((int)(a).size())
#define X first
#define Y second
#define MP make_pair
#define L(x) ((x)<<1)
#define R(x) ((x)<<1 | 1)
#define max3(x, y, z) (max(max((x), (y)), (z)))
#define min3(x, y, z) (min(min((x), (y)), (z)))
#define BIT(x, i) (((x) >> (i)) & 1)
#define ALL(it) (it).begin(), (it).end()
#define FOR(it, c) for( TYPE((c).begin()) it = (c).begin(); it != (c).end(); it++)
/////////////////////////////////////////////////////////////
const double PI = acos(-1.0);
const double EPS = 1e-6;

#define MAX_N 205
#define MAX_M 5005
#define MAXX 0x3f
#define UPPER 2147483647LL
#define INF ((1 << 30) - 1)
#define BINF ((1LL << 62) - 1LL)
#define NONE -1
#define NIL 0
// }

/////////////////////////////////////////////////////////////
int64 Solve(int64 x){
	//printf("~ %lld\n", x);
	if (x == 0LL)
		return 0LL;
	vector <int> V;
	for (int64 tmp = x; tmp > 0; tmp /= 10)
		V.emplace_back((int)(tmp % 10));
	int remain = (SZ(V) + 1) >> 1;
	int take = SZ(V) - remain;
	assert(SZ(V) - take >= 0);
	int64 now = 0LL;
	for (int i = SZ(V) - 1; i >= SZ(V) - take; i--)
		now = 10LL * now + V[i];
	for (int i = 0; i < remain - 1; i++)
		now *= 10LL;
	now = 10LL * now + 1LL;

	int64 rev = 0LL;
	for (int64 tmp = now; tmp > 0; tmp /= 10)
		rev = 10LL * rev + tmp % 10;
	//printf("{ %lld %lld\n", now, rev);
	int64 res = x - now;
	if (now > x){
		return 1LL + Solve(x - 1);
	}
	else if (rev < now){
		//puts("aaa");
		return res + 1 + Solve(rev);
	}
	else if (rev == now){
		//puts("bbb");
		return res + 1LL + Solve(now - 1);
	}
	else{
		//puts("cccc");
		return min(res + Solve(now), res + 1 + Solve(now - 1LL));
	}
}
/////////////////////////////////////////////////////////////
int main(){
	RF("input.txt");
	WF("output.txt");

	int T;
	scanf("%d", &T);
	for (int _ = 1; _ <= T; _++){
		int64 N;
		scanf("%lld", &N);
		printf("Case #%d: %lld\n", _, Solve(N));
	}
	return 0;
}