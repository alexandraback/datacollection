#include <cstdio>
#define FOR(i,b,e) for(int i=(b); i<=(e); ++i)
using namespace std;
typedef long long LL;

const int S = 39;
const LL INF = 1e18;
const LL T[S+1] = {1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004,INF};

inline int f(LL x)
{
	int r = 0;
	while (T[r] <= x) ++r;
	return r;
}
inline int f(LL x, LL y) { return f(y)-f(x-1); }


int main()
{
	int Q; scanf("%d", &Q);
	FOR(q, 1, Q) {
		LL x, y; scanf("%lld%lld", &x, &y);
		printf("Case #%d: %d\n", q, f(x, y));
	}
	
	return 0;
}
