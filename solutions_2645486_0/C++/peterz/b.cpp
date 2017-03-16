#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;
#define PII pair<int,int>
#define X first
#define Y second
#define PB push_back
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FOE(i,a,b) for (int i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,n)
int n, m, e, r;
int v[100], dp[100][100];
int find(int x, int y){
	if (x >= n) return 0;
	if (dp[x][y] != -1) return dp[x][y];
	int ret = 0;
	FOE(i,0,y){
		ret = max(ret, v[x] * i + find(x + 1, min(e, y - i + r)));
	}
	return dp[x][y] = ret;
}
int main(){
	int T;
	scanf("%d", &T);
	FOE(cc,1,T){
		scanf("%d%d%d", &e, &r, &n);
		FOR(i,0,n) scanf("%d", v + i);
		memset(dp, -1, sizeof(dp));
		printf("Case #%d: %d\n", cc, find(0, e));
	}
	return 0;
}

