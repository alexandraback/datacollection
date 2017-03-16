#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
using namespace std;
#define FOR(i,s,e) for (int i=s;i<e;i++)
#define FOE(i,s,e) for (int i=s;i<=e;i++)
#define FOD(i,s,e) for (int i=s;i>=e;i--)
#define SET(a,e) memset(a,e,sizeof(a))
#define LL long long
#define pb push_back

int T,dp[1000055],N,C,V;

LL rev(int num) {
	vector<int> A;
	while (num>0) {	
		A.pb(num%10);
		num/=10;
	}
	int ret=0;
	FOR(i,0,A.size()) ret=ret*10+A[i];
	return ret;
}



int main () {
	
	FOE(i,1,1000000) dp[i]=i;
	
	FOE(i,1,1000000) {
		dp[rev(i)]=min(dp[rev(i)],dp[i]+1);
		dp[i+1]=min(dp[i+1],dp[i]+1); 
	}
	
//	FOE(i,1,23) printf("dp[%d] = %d\n",i,dp[i]);
	
	scanf("%d",&T);
	
	FOE(tc,1,T) {
		scanf("%d",&N);
		printf("Case #%d: %d\n",tc,dp[N]);
	}
	
	return 0;
}

