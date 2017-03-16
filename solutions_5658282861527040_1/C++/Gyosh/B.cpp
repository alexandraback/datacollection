#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>

#define REP(a,b) for (int a = 0; a < b; a++)
#define FOR(a,b,c) for (int a = b; a <= c; a++)
#define RESET(a,b) memset(a,b,sizeof a)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define PII pair<int,int>
#define INF 2123123123

#define LL long long
using namespace std;

int T;
int A,B,K;
LL dp[33][2][2][2];

int getbit(int a, int b){
	return (a >> b) & 1;
}

LL rek(int x, int daha, int dahb, int dahk){
	if (x < 0){
		return daha & dahb & dahk;
	}else if (dp[x][daha][dahb][dahk] != -1){
		return dp[x][daha][dahb][dahk];
	}else{
		LL &ret = dp[x][daha][dahb][dahk] = 0;

		int sa, sb, sk;
		FOR(a,0,1){
			FOR(b,0,1){
				sa = daha;
				sb = dahb;
				sk = dahk;

				bool ok = 0;
				if ((daha || (getbit(A,x) >= a)) && 
				    (dahb || (getbit(B,x) >= b)) &&
				    (dahk || (getbit(K,x) >= (a & b))) ){
					ok = 1;
				}

				if (!ok) continue;

				if ((getbit(A,x) > 0) && (a == 0)){
					sa = 1;
				}
				if ((getbit(B,x) > 0) && (b == 0)){
					sb = 1;
				}
				if ((getbit(K,x) > 0) && ((a & b) == 0)){
					sk = 1;
				}


				ret += rek(x-1, sa, sb, sk);
			}
		}

		printf("%d %d %d %d = %lld\n", x, daha, dahb, dahk, ret);
		return ret;
	}
}

int main(){		
	scanf("%d", &T);
	REP(jt,T){
		scanf("%d%d%d", &A, &B, &K);

		RESET(dp,-1);
		printf("Case #%d: %lld\n", jt+1, rek(31,0,0,0));
	}
	return 0;
}
