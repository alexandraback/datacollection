#include <bits/stdc++.h>
using namespace std;

/*
( "THREE", "NINE"
*/

int dp[1<<16];

vector< pair<string,string> > vs;
int dfs(int bit){
	if( dp[bit] != -1 ) return dp[bit];
	set<string> fr,bk;
	for(int i = 0 ; i < vs.size() ; i++){
		if( bit >> i & 1 ) fr.insert(vs[i].first),bk.insert(vs[i].second);
	}
	int ans = 0;
	for(int i = 0 ; i < vs.size() ; i++){
		if( !(bit>>i&1) ){
			ans = max( ans , (fr.count(vs[i].first) and bk.count(vs[i].second)) + dfs(bit|(1<<i)) );
		}
	}
	return dp[bit] = ans;
}
int solve(){
	memset(dp,-1,sizeof(dp));
	int n;
	cin >> n;
	vs.clear();
	for(int i = 0 ; i < n ; i++){
		string a,b;
		cin >> a >> b;
		vs.push_back({a,b});
	}
	return dfs(0);
	
	
	
	
	
	
	
	
	
	
}
int main(){
	int T;
	cin >> T;
	int t = 1;
	while(T--){
		printf("Case #%d: ",t++);
		cout << solve() << endl;
	}
}