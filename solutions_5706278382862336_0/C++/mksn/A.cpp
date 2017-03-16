#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#else
#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#endif
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <string>
#include <iostream>
#define FOR(x,y,z) for (int x=(y); x<=(z); ++x)
#define FORD(x,y,z) for(int x=(y); x>=(z); --x)
#define REP(x,y) for (int x=0; x<(y); ++x)
#if defined(__GNUC__) && __cplusplus < 201103L
#define FOREACH(y,x) for (typeof((x).begin()) y = (x).begin(); y != (x).end(); ++y)
#else
#define FOREACH(y,x) for (auto y = (x).begin(); y != (x).end(); ++y)
#endif
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((int)(x).size())
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
const int INF = 1000000001;

inline int Pow2(int exp) { return 1 << exp; }

template<typename T>
inline T Pow2(int exp) { return (T)1 << exp; }

int Log2(ULL x, bool ceil)
{
	unsigned long r;
#ifdef __GNUC__
	r = 63 - __builtin_clzll(x);
#else
	_BitScanReverse64(&r, x);
#endif
	return r + (ceil && x > Pow2<ULL>(r));
}

LL GCD(LL x, LL y)
{
	while (y != 0) {
		LL z = x%y;
		x = y;
		y = z;
	}
	return x;
}

int main(int argc, char** argv)
{
	int tc;
	scanf("%d", &tc);
	FOR(tccc,1,tc) {
		LL p,q;
		scanf("%lld/%lld", &p, &q);
		LL g = GCD(p, q);
		p /= g;
		q /= g;
		int x = Log2(p, false);
		int y = Log2(q, false);
		printf("Case #%d: ", tccc);
		if (Pow2<LL>(y) != q) printf("impossible");
		else printf("%d", y-x);
		printf("\n");
	}

#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}
