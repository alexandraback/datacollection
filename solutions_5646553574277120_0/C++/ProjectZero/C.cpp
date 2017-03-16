#include <bits/stdc++.h>
using namespace std;

int C,D,V;
int min_ans;

map <int,bool> dp;
int A[50],B[50];

bool test(int bitmask){
	if(dp.count(bitmask) && dp[bitmask] == true) return true;

	memset(A,0,sizeof A);
	for(int j=0;j<=V;j++) A[j] = B[j];
	A[0] = true;
	for(int i=1;i<=V;i++){
		if(((1<<i)&bitmask) == 0) continue;
		for(int j=V;j>=i;j--) A[j] |= A[j-i];
	}

	bool answer = true;
	for(int i=1;i<=V;i++) if(A[i] == 0) answer = false;
	return dp[bitmask] = answer;
}

void solve(int bitmask,int ans){
	// printf("bitmask = %d\n",bitmask);
	if(bitmask == (1<<(V+1))-1){
		min_ans = min(min_ans,ans);
		return; 
	}

	for(int i=1;i<=V;i++) if(A[i] == 0){
		A[i] = 1;
		memset(B,0,sizeof B);
		B[0] = true;
		for(int j=1;j<=V;j++) B[j] = (bitmask&&(1<<j));
		for(int j=V;j>=i;j--) B[j] |= B[j-i];
		for(int j=0;j<=V;j++) if(B[j]) bitmask |= (1<<j);

		solve(bitmask,ans+1);
		A[i] = 0;
	}
}

void run(int test){
	dp.clear();
	scanf("%d %d %d",&C,&D,&V);
	
	int bitmask = 0;
	memset(A,0,sizeof A);
	memset(B,0,sizeof B);
	B[0] = true;
	for(int i=1;i<=D;i++){
		int x; scanf("%d",&x);
		A[x] = true;
		for(int j=V;j>=x;j--){
			B[j] |= B[j-x];
			// if(B[j]) printf("j = %d true\n",j);
		}
	}
	bitmask = 0;
	for(int j=0;j<=V;j++){
		if(B[j]) bitmask |= (1<<j);
	}
	min_ans = 1e9;
	solve(bitmask,0);
	printf("Case #%d: %d\n",test,min_ans);
}

int main(){
	freopen("C-small-attempt2.in","r",stdin);
	freopen("C-small-attempt2.out","w",stdout);
	int T; scanf("%d",&T);
	for(int i=1;i<=T;i++) run(i);
	return 0;
}