#include<iostream>
#include<cstdio>

using namespace std;

int dp[10][10];

int n ;
int E,R;
int v[10];
int solve(int e, int cur){
	if(dp[e][cur]!=-1) return dp[e][cur];
	if(cur==n-1) return e*v[cur];
 	
 	int &res = dp[e][cur];
 	res = 0;
 	for(int i = 0; i <= e ; i++){
 		res = max(res, v[cur]*(i) + solve(min(E,e-i+R),cur+1));
 	}
 	return res;
}

int main(){
	int t;
	scanf("%d",&t);
	for(int cs = 1; cs<=t ;cs++){
		scanf("%d%d%d",&E,&R,&n);
		for(int i = 0 ; i < 10 ; i++) for(int j = 0 ; j < 10 ; j++) dp[i][j] = -1;

		for(int i =0 ; i < n ; i++) scanf("%d",&v[i]);
		printf("Case #%d: %d\n",cs,solve(E,0));
	}
}