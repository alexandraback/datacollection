#include<bits/stdc++.h>
#define md 1000000007
#define ll unsigned long long
#define gc getchar//_unlocked
using namespace std;
ll dp[1000100];
ll reverse(ll no1){
	ll n=0;
	ll no=no1;
	while(no){
		n=n*(10)+no%10;
		no/=10;
	}
	return n;
}
int main()
{
	dp[1]=1;
	for(int i=2;i<=1000000;i++){
		ll x=reverse(i);
		if(x<i && i%10 ){
			dp[i]=min(dp[i-1],dp[x])+1;
		}
		else{
			dp[i]=dp[i-1]+1;
		}
		
	}
	#ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
	   freopen("out2.txt","w",stdout);		
		#endif
		int test;
		ll no;
		ll count;
		scanf("%d",&test);
		for(int tst=1;tst<=test;tst++){
			printf("Case #%d: ",tst);
			scanf("%lld",&no);
			printf("%lld\n",dp[no]);
			
			
		}
	
    return 0;
}