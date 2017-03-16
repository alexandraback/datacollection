#include<unordered_set>
#include<unordered_map>
#include<functional>
#include<algorithm>
//#include<iostream>
#include<numeric>
#include<cassert>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
//#include<cmath>
#include<set>
#include<map>
using namespace std;

typedef long long LL;
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

int __stmp;
#define scanf __stmp=scanf


const int INF = 1000000001;
const int MAX = 100000;

int n;

int solve1(VI A, VI B) {
	int ret = 0;
	int j = 0;
	REP(i,n)
	{
		if(B[j] < A[i]) {
			ret++;
			j++;
		}
	}
	return ret;
}

int solve2(VI A, VI B) {
	int ret = 0;
	set<int> S(ALL(B));
	for(int i : A)
	{
		auto it = S.upper_bound(i);
		if(it == S.end()) {
			ret++;
			S.erase(S.begin());
		} else {
			S.erase(it);
		}
	}
	return ret;
}

int main(int argc, char *argv[]) {
	int Z;
	scanf("%d", &Z);
	FOR(z,1,Z)
	{
		printf("Case #%d: ", z);
		scanf("%d", &n);
		VI A, B;
		REP(i,n)
		{
			int a;
			scanf(" %*c%*c%d", &a);
			A.PB(a);
		}
		REP(i,n)
		{
			int a;
			scanf(" %*c%*c%d", &a);
			B.PB(a);
		}
		sort(ALL(A));
		sort(ALL(B));
		printf("%d %d\n", solve1(A, B), solve2(A, B));
	}
	return 0;
}

