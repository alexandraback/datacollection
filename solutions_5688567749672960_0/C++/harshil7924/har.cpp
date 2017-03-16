#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define f first
#define s second
#define mod 1000000007
#define inf 1e8

#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define f first
#define mp make_pair
#define s second
#define rep(i,n) for(int i=0;i<n;i++)
#define M 360360
int dp[1000011];
int rev(int k){
	vector<int>v;
	while(k>0){
		v.pb(k%10);
		k/=10;
	}
	reverse(v.begin(),v.end());
	int g=0;
	while(v.back()==0) v.pop_back();
	reverse(v.begin(),v.end());
	for(auto x:v){
		g+=x;
		g*=10;
	}
	g/=10;
	return g;
}
void calc(){
	rep(i,1000001) dp[i]=inf;
	dp[1]=1;
	ll h;
	for(int i=1;i<=1000001;i++){
		h=rev(i);
		dp[i+1]=min(dp[i+1],dp[i]+1);
		if(h>i){
			dp[h]=min(dp[h],dp[i]+1);
		}
	}
}
int main(){
freopen("A-small-attempt0.in","r",stdin);
freopen("output.txt","w",stdout);
int t,n;
cin>>t;
calc();
int cnt=0;
while(t--){
	cnt++;
	cin>>n;
	cout<<"Case #"<<cnt<<": "<<dp[n]<<"\n";
}
}
