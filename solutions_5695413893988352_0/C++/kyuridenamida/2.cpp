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
void solve(){
	string a,b;
	cin >> a >> b;
	int L = a.size();
	pair<long long,pair<string,string> > ans = {2e18,{"",""}};
	for(int i = 0 ; i <= L ; i++){
		string s,t;
		for(int j = 0 ; j < i ; j++){
			if( a[j] == '?' and b[j] == '?' ) s += "0", t += "0";
			else if( a[j] == '?' ) s += b[j], t += b[j];
			else if( b[j] == '?' ) s += a[j], t += a[j];
			else s += a[j], t += b[j];
		}
		if( s != t ) continue;
		if( i == L ){
			cout << s << " " << t << endl;
			return;
		}else{
			for(int k = 0 ; k < 10 ; k++){
				for(int l = 0 ; l < 10 ; l++){
					for(int p = 0 ; p < 2 ; p++){
						if( a[i] == '?' or a[i] == k + '0' ){
							if( b[i] == '?' or b[i] == l + '0' ){
								string S = s;
								string T = t;
								S += k + '0';
								T += l + '0';
								
								char X = p ? '9' : '0';
								char Y = !p ? '9' : '0';
								
								for(int m = i+1 ; m < L ; m++){
									S += a[m] == '?' ? X : a[m];
									T += b[m] == '?' ? Y : b[m];
								}
								long long W,O;
								stringstream ss(S + " " + T);
								ss >> W >> O;
								ans = min(ans,{abs(W-O),{T,S}});
							}
						}
						
					}

				}
			}
		}
	}
	cout << ans.second.second << " " << ans.second.first << endl;
}
int main(){
	int T;
	cin >> T;
	int t = 1;
	while(T--){
		printf("Case #%d: ",t++);
		solve();
	}
}