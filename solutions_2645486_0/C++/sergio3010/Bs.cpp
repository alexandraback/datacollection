#include <bits/stdc++.h>



using namespace std;




#define fr(i,a,b) for(int i=a;i<b;++i)
typedef long long ll;



int dp[100][100];

int t,e,r,n, v[1010];

int go(int onde, int en){
	if(dp[onde][en] != -1) return dp[onde][en];
	if(onde == n) return dp[onde][en] = 0;
	dp[onde][en] = 0;
	fr(i,0,en+1){
		dp[onde][en] = max(dp[onde][en], i*v[onde] + go(onde+1, min(e, en-i+r)));
	}
	return dp[onde][en];
}


int cas = 1;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&e,&r,&n);
		fr(i,0,n){
			scanf("%d",&v[i]);
		}
		memset(dp, -1, sizeof dp);
		printf("Case #%d: %d\n",cas,go(0,e));
		cas++;
	}
	return 0;
}












































