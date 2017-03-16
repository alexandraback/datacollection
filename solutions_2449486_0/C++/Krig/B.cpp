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

int stmp;
#define scanf stmp=scanf


const int MAX = 100;
const int INF = 1000000001;

int arr[MAX][MAX];
int ver[MAX], hor[MAX];

int n, m;

bool solve() {
	REP(i,n)
		REP(j,m)
			if(hor[i] > arr[i][j] && ver[j] > arr[i][j])
				return false;
	return true;
}

int main(int argc, char *argv[]) {
	int Z;
	scanf("%d", &Z);
	FOR(z,1,Z)
	{
		printf("Case #%d: ", z);
		scanf("%d %d", &n, &m);
		fill(hor, hor+n, 0);
		fill(ver, ver+m, 0);
		REP(i,n)
			REP(j,m)
			{
				scanf("%d", arr[i]+j);
				hor[i] = max(hor[i], arr[i][j]);
				ver[j] = max(ver[j], arr[i][j]);
			}
		printf("%s\n", solve() ? "YES" : "NO");
	}
	return 0;
}

