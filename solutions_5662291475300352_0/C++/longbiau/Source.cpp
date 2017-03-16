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

#define MAX_N 10005
#define MAX_M 5005
#define MAXX 0x3f
#define UPPER 2147483647LL
#define INF ((1 << 30) - 1)
#define BINF ((1LL << 62) - 1LL)
#define NONE -1
#define NIL 0
// }

/////////////////////////////////////////////////////////////
int D[MAX_N], H[MAX_N], M[MAX_N];
int N;
int Solve(){
	if (N == 1){
		return 0;
	}
	else{
		return 1;
	}
}
/////////////////////////////////////////////////////////////
int main(){
	RF("input.txt");
	WF("output.txt");

	int T;
	scanf("%d", &T);
	for (int _ = 1; _ <= T; _++){
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d %d %d", D + i, H + i, M + i);
		printf("Case #%d: %d\n", _, Solve());
	}
	return 0;
}