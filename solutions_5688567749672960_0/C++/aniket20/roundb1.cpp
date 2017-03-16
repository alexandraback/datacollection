#include<bits/stdc++.h>
#define ll long long
#define N 1000000007
#define maxs 100005
#define mins 1005
#define pb push_back
using namespace std;

ll power(ll a,ll b)
{
	ll t=1;
	while(b>0){
		if(b&1){
			t=(t*a);
		}
		a=a*a;
		b>>=1;
	}
	return t;
}

ll rev(ll i)
{
	ll t=0;
	while(i>0){
		t=t*10+i%10;
		i=i/10;
	}
	return t;
}

ll dp[maxs*10];

int main()
{
	int t;
	ll n,i;
	ll cnt=1;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		dp[1]=1;
		for(i=2;i<=n;i++){
			dp[i]=INT_MAX;
		}
		for(i=1;i<=n;i++){
			dp[i+1]=min(dp[i+1],dp[i]+1);
			dp[rev(i)]=min(dp[rev(i)],dp[i]+1);
		}
		printf("Case #%lld: %lld\n",cnt,dp[n]);
		cnt++;
	}
	return 0;
}
