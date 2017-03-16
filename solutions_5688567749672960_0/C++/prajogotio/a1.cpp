#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <string>
using namespace std;

long long N;
long long pow10[20];
long long dp[20];
int main(){
	pow10[0]=1;
	for(int i=1;i<20;++i){
		pow10[i]=pow10[i-1]*10LL;
	}
	dp[0]=1;
	dp[1]=10;
	for(int i=2;i<20;++i){
		int j = i-1;
		dp[i] = dp[i-1]+(pow10[j/2]-1LL)*10LL+1LL+pow10[j-j/2]-1LL+9LL;
	}

	int TC;
	scanf("%d",&TC);
	for (int tt=1;tt<=TC;++tt){
		printf("Case #%d:", tt);
		scanf("%lld",&N);
		if(N<=19){
			printf(" %lld\n",N);
			continue;
		}
		int sz = 0;
		long long x = N;
		int a[20];
		while(x){
			a[sz++] = x%10LL;
			x/=10LL;
		}
		long long ans = dp[sz-1];
		int mid = sz/2;
		bool flip = false;
		for (int i=mid;i<sz;++i){
			ans += a[i]*pow10[sz-i-1];
			if(i!=sz-1 && i != mid && a[i]>0)flip=true;
			if(i==mid && sz%2==0 && a[i]>0)flip=true;
		}
		ans += (N%pow10[mid]) - 1LL;
		if(flip||a[sz-1]>1)ans++;
		printf(" %lld\n",ans);
	}
	return 0;
}