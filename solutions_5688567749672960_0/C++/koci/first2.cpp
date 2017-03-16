#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <cassert>

#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define vi vector<int>
#define fs first
#define sec second

#define maxn 100000

using namespace std;
typedef long long ll;

const ll MOD = 1000000007LL;

ll reverse(ll x){
	vector <ll> tmp;
	while(x>0){
		tmp.pb(x%10);
		x/=10;
	}
	ll rez=0;
	FOR(i,tmp.size()){
		rez*=10;
		rez+=tmp[i];
	}
	return rez;
}

int dp[1000002];

void precalc(){
	FOR(i,1000001)dp[i]=1000001;
	dp[1]=1;
	dp[0]=1;
	FORR(i,2,1000001){
		if(dp[i-1]+1<dp[i])dp[i]=dp[i-1]+1;
		ll r = reverse(i);
		if(r>1000000)continue;
		if(dp[r]>dp[i]+1)dp[r]=dp[i]+1;
	}
}

void solve(int zap){
	ll n;
	cin >> n;
	cout << "Case #"<<zap<<": " << dp[n] << "\n";
}

int main(){
	precalc();
	int t;
	cin >> t;
	FORR(i,1,t+1){
		solve(i);
	}
	return 0;
}
