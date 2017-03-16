#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <queue>

#define REP(a,b) for (int a = 0; a < b; a++)
#define FOR(a,b,c) for (int a = b; a <= c; a++)
#define RESET(a,b) memset(a,b,sizeof a)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define PII pair<int,int>
#define INF 2123123123

#define MAXN 1000005
#define LL long long
using namespace std;

int dp[MAXN];
queue<int> q;
int T,N;

int rev(int x){
	int ret = 0;
	while (x){
		ret = ret*10 + (x % 10);
		x /= 10;
	}
	return ret;
}

void relax(int u, int x){
	if (x >= MAXN) return;

	if (dp[x] == -1){
		dp[x] = dp[u] + 1;
		q.push(x);
	}
}

void fill(){
	RESET(dp,-1);
	q.push(0);
	dp[0] = 0;
	while (!q.empty()){
		int u = q.front();
		q.pop();

		relax(u, u+1);
		relax(u, rev(u));
	}
}

int main(){		
	fill();

	scanf("%d", &T);
	REP(jt,T){
		scanf("%d", &N);
		printf("Case #%d: %d\n", 1+jt, dp[N]);
	}

	return 0;
}
