// -*- compile-command: "g++ -g -Wall -Wextra -DLOCAL -std=c++11 -D_GLIBCXX_DEBUG a.cpp -oa && ./a " -*-
#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair
#define sz(v) ((in)(v).size())
#define all(v) (v).begin(),(v).end()
#define forn(i,n) for(int i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using LL=long long;
using in=LL;
using D=long double;
using vi=vector<int>;
using pi=pair<int,int>;
using pd=pair<D,D>;
using ti3=tuple<int,int,int>;
using vvi=vector<vi>;
using vpi=vector<pi>;
using vvpi=vector<vpi>;

LL rev(LL x){
	LL r=0;
	for(;x;x/=10)
		r=10*r+x%10;
	return r;
}
void solve(){
	LL n;
	cin>>n;
	vi dp(n+1,2*n);
	dp[0]=0;
	for(LL i=1;i<=n;i++){
		LL k=rev(i);
		dp[i]=min(dp[i],dp[i-1]+1);
		if(k<=n) dp[k]=min(dp[k],dp[i]+1);
	}
	cout<<dp[n]<<'\n';
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		cout<<"Case #"<<t<<": ";
		solve();
	}
}
