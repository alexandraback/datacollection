#include<stdio.h>
int tc,tcn;
long long int n;
long long int powt[18];
long long int anst[18];
int digit[18];
int dlen;
long long int fa(long long int x){
	if(x<20)return x;
	x--;
	int i;
	long long int ans,tx=x;
	dlen=0;
	while(tx>0){
		digit[dlen]=tx%10;
		dlen++;
		tx/=10;
	}
	ans=0;
	for(i=0;i<dlen;i++){
		if(powt[i]<powt[dlen-1-i]){
			ans+=digit[i]*powt[i];
		}
		else{
			ans+=digit[i]*powt[dlen-1-i];
		}
	}
	if(ans>x-powt[dlen-1]){
		ans=x-powt[dlen-1];
	}
	ans+=anst[dlen-1];
	return ans+1;
}
long long int dp[1000000];
long long int rev(long long int x){
	long long int ans,t,tx;
	ans=0;
	t=1;
	tx=x;
	while(tx>0){
		tx/=10;
		t*=10;
	}
	while(x>0){
		t/=10;
		ans+=t*(x%10);
		x/=10;
	}
	return ans;
}
long long int fb(long long int x){
	int i;
	for(i=0;i<=x;i++){
		dp[i]=100000000000;
	}
	dp[0]=0;
	for(i=0;i<x;i++){
		if(dp[rev(i)]>dp[i]){
			dp[rev(i)]=dp[i]+1;
		}
		if(dp[i+1]>dp[i]){
			dp[i+1]=dp[i]+1;
		}
	}
	return dp[x];
}
int main(){
	int i;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	powt[0]=1;
	anst[0]=1;
	powt[1]=10;
	anst[1]=10;
	for(i=1;i<16;i++){
		powt[i+1]=powt[i]*10;
		anst[i+1]=anst[i]+powt[(i+1)/2]+powt[(i+2)/2]-1;
	}
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%lld",&n);
		printf("Case #%d: %lld\n",tc,fa(n));
	}
}