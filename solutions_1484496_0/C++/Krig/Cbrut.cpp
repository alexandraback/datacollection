#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
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

int stmp;
#define scanf stmp=scanf


const int MAX = 20;
const int INF = 1000000001;

int tab[MAX];

int n, sum;

void solve() {
	VI dp(sum+1, -1);
	REP(mask,1<<n)
	{
		int s = 0;
		REP(i,n)
			if(mask & (1<<i))
				s += tab[i];
		if(dp[s] != -1) {
			REP(i,n)
				if(mask & (1<<i))
					printf("%d ", tab[i]);
			printf("\n");
			REP(i,n)
				if(dp[s] & (1<<i))
					printf("%d ", tab[i]);
			printf("\n");
			return;
		}
		dp[s] = mask;
	}
	printf("Impossible\n");
}

int main(int argc, char *argv[]) {
	int Z;
	scanf("%d", &Z);
	FOR(z,1,Z)
	{
		printf("Case #%d:\n", z);
		scanf("%d", &n);
		sum = 0;
		REP(i,n)
		{
			scanf("%d", tab+i);
			sum += tab[i];
		}
		solve();
	}
	return 0;
}

