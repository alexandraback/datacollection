#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long int uint64;
#define MAXN 110

int N, M;

struct TYPE{
	uint64 n;
	uint64 t;
};

TYPE a[MAXN], b[MAXN];

uint64 dp[MAXN][MAXN];
bool isfind[MAXN][MAXN];

//uint64 DP(int x, int y){
//	if( x == -1 || y == -1 ) return 0;
//
//	if(isfind[x][y]) return dp[x][y];
//
//	dp[x][y] = 0;
//	if( a[x].t == b[y].t ){
//		dp[x][y] += min(a[x].n, b[y].n);
//		//printf("=> %d, %d, %lld\n", x, y, dp[x][y]);
//	}
//
//	dp[x][y] += max(DP( x - 1, y ), DP( x, y - 1 ));
//
//	isfind[x][y]= true;
//	printf("%d, %d, %lld\n", x, y, dp[x][y]);
//	return dp[x][y];
//}

uint64 count( int x, int xx, int y, int yy ){
	// use x type for fund
	uint64 n1[MAXN] = {0};
	uint64 n2[MAXN] = {0};

	for( int i = x; i < xx; i++ ){
		n1[a[i].t] += a[i].n;
		//printf("a %lld, %lld\n", a[i].t, a[i].n);
	}
	for( int i = y; i < yy; i++ ){
		//printf("b %lld, %lld\n", b[i].t, b[i].n);
		n2[b[i].t] += b[i].n;
	}
	uint64 v = 0;
	for( int i = 0;i < MAXN; i++ ){
		v = max( v, min(n1[i], n2[i]));
	}
	//printf("%lld\n", v);
	return v;
}

uint64 DP(int x, int y){
	if( x == N || y == M ) return 0;

	if(isfind[x][y]) return dp[x][y];

	dp[x][y] = 0;
	uint64 changN = 0;
	//uint64 nowa_t = a[x].t;
	//uint64 nowb_t = b[y].t;

	for( int i = x + 1; i <= N; i++ ){
		for( int j = y + 1; j <= M; j++ ){
			changN = 0;
			uint64 v = count(x, i, y, j);

		//	printf("[%d %d], [%d %d], %lld\n", x, i, y, j, v);
			dp[x][y] = max( dp[x][y], DP(i, j) + v );
		}
	}

//	// go M
//	for( int i = y + 1; i <= M; i++ ){
//		if( nowa_t == b[i - 1].t ){
//			changN += b[i - 1].n;
//		}
//		uint64 tmp = min( a[x].n, changN );
//		//printf("go M %lld %lld [%d %d] with [%d:%lld] %lld %lld\n", nowa_t, b[i - 1].t, y, i, x, a[x].n, changN, tmp);
//		dp[x][y] = max( dp[x][y], DP(x + 1, i) + tmp );
//
//	}
//
//	// go N
//	changN = 0;
//	for( int i = x + 1; i <= N; i++ ){
//		if( nowb_t == a[i - 1].t ){
//			changN += a[i - 1].n;
//		}
//		uint64 tmp = min( b[y].n, changN );
//		dp[x][y] = max( dp[x][y], DP(i, y + 1) + tmp );
//		//printf("go N %lld %lld [%d %d] with [%d:%lld] %lld %lld\n", nowb_t, b[i - 1].t, y, i, x, a[x].n, changN, tmp);
//	}

	isfind[x][y] = true;
	//printf("%d, %d, %lld\n", x, y, dp[x][y]);
	//fflush(stdout);
	return dp[x][y];
}

int main() {
	int cases;		// number of cases
	int caseID = 1;	// case ID, start from 1

	freopen("CS.txt", "r", stdin);
	freopen("oCut.txt", "w", stdout);
	scanf("%d", &cases);
	while (cases--) {
		memset(dp, 0, sizeof(dp));
		memset(isfind, false, sizeof(isfind));

		scanf("%d%d", &N, &M);
		for( int i = 0;i < N; i++ ){
            cin >> a[i].n >> a[i].t;
			//scanf("%lld%lld", &a[i].n, &a[i].t);
		}
		for( int i = 0;i < M; i++ ){
            cin >> b[i].n >> b[i].t;
			//scanf("%lld%lld", &b[i].n, &b[i].t);
		}
		//count(0, 1, 0, 1);
		printf("Case #%d: ", caseID++, DP(0, 0));
		cout << DP(0, 0) << endl;
	}
	return 0;
}
