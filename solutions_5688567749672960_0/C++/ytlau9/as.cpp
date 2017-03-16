#include<bits/stdc++.h>
#define LL long long 
#define PI acos(-1)
#define x first
#define y second
#define PII pair<int,int>
#define F(x,y,z) for(int (x)=(y);(x)<(z);(x)++)
#define pb push_back
#define mp make_pair
using namespace std;

int T,n,ans,dp[1000010];

int flip(int x){
    int ret = 0;
    while(x){ ret = ret*10+x%10; x/=10; }
    return ret;
}


int main(){
    scanf("%d", &T);
    for(int qwe=1; qwe<=T;qwe++){
	scanf("%d", &n);	
	for(int i=0; i<=n;i++) dp[i] = 1<<28;
	dp[1] = 1;
	for(int i=1; i<=n;i++){
	    if(dp[i]+1< dp[i+1]) dp[i+1] = dp[i]+1;
	    if(dp[i]+1 < dp[flip(i)]) dp[flip(i)] = dp[i]+1;
	}
	printf("Case #%d: %d\n", qwe, dp[n]);
    }
    return 0;
}
