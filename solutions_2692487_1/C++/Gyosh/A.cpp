#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <map>

#define REP(a,b) for (int a=0; a<b; a++)
#define FOR(a,b,c) for (int a=b; a<=c; a++)
#define FORD(a,b,c) for (int a=b; a>=c; a--)
#define RESET(a,b) memset(a, b, sizeof a)

#define INF 1023123123
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define PII pair<int,int> 
#define PDD pair<double,double>

#define __ puts("")
#define MAX 2000
using namespace std;

int nkasus;
int aw,n;
int ar[1000];
int dp[21][2100];

int rek(int x, int sz){
	if (x == n){
		return 0;
	}else if (dp[x][sz] != -1){
		return dp[x][sz];
	}else{
		dp[x][sz] = INF;
		
		if (sz > ar[x]){
			dp[x][sz] = rek(x+1,sz + ar[x]);
		}else{
			dp[x][sz] = 1 + rek(x+1, sz);
			if (2*sz < MAX) dp[x][sz] = min(dp[x][sz], rek(x,2*sz-1)+1);
		}
		return dp[x][sz];
	}	
}

int cari(){
	// no way can eat
	if (aw == 1) return n;

	int cur = aw;
	int ret = n;
	int op = 0;
	REP(i,n){
		if (cur > ar[i]){
			cur += ar[i];
		}else{
			while (cur <= ar[i]){
				op++;
				cur = 2*cur - 1;
			}
			cur += ar[i];
		}
			
		ret = min(ret, op + n-i-1);
	}
	
	return ret;
}

int main(){
	scanf("%d", &nkasus);
	REP(jt,nkasus){
		scanf("%d%d", &aw, &n);
		REP(i,n){
			scanf("%d", &ar[i]);
		}
		
		sort(ar, ar + n);
		
		RESET(dp,-1);
		printf("Case #%d: %d\n", jt+1, cari());
	}
	
	return 0;
}
