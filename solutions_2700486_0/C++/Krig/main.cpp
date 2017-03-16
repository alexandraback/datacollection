#include<functional>
#include<algorithm>
//#include<iostream>
#include<numeric>
#include<cassert>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<map>
using namespace std;

typedef unsigned long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b);i>=(e);--i)
#define FOReach(it,V) for(__typeof((V).begin()) it=(V).begin();it!=(V).end();++it)

#define PB push_back
#define ALL(V) (V).begin(),(V).end()
#define SIZE(V) ((int)(V).size())

#define MP make_pair
#define ST first
#define ND second

#define DBG

#ifdef DBG
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define debug(...)
#endif

int stmp;
#define scanf stmp=scanf


const int MAX = 100000;
const int INF = 1000000001;

LL fact(int n) {
	return n ? fact(n-1)*n : 1;
}

LL binom(int n, int k) {
	return fact(n)/fact(k)/fact(n-k);
}

int n, x, y, k;


double solve() {
	k = 1;
	while(k*(k+1)/2 <= n) k += 2;
	k -= 2;
	n -= k*(k+1)/2;
	if(x+y < k) return 1.;
	if(x+y > k+2 || x == 0) return 0.;
	++y;
	if(k+1 + y <= n) return 1.;
	long double res = 0.;
	long double d = pow(0.5, n);
	FOR(i,y,n) res += d * binom(n, i);
	return res;
}

int main(int argc, char *argv[]) {
	int Z;
	scanf("%d", &Z);
	FOR(z,1,Z)
	{
		printf("Case #%d: ", z);
		scanf("%d %d %d", &n, &x, &y);
		printf("%.8lf\n", solve());
	}
	return 0;
}

