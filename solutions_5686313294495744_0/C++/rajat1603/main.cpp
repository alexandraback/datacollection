#include "bits/stdc++.h"
using namespace std;
const int N = 18;
int t;
int tc = 0;
int n;
string str1[N];
string str2[N];
int dp[1 << N];
int solve(int mask){
	if(dp[mask] != -1){
		return dp[mask];
	}
	int res = 0;
	set < string > s1;
	set < string > s2;
	s1.clear();
	s2.clear();
	for(int i = 1 ; i <= n ; ++i){
		if(mask & (1 << i)){
			s1.insert(str1[i]);
			s2.insert(str2[i]);
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!(mask & (1 << i))){
			res = max(res , solve(mask | (1 << i)));
			if(s1.find(str1[i]) != s1.end()){
				if(s2.find(str2[i]) != s2.end()){
					res = max(res , 1 + solve(mask | (1 << i)));
				}
			}
		}
	}
	return dp[mask] = res;
}
int main(){
	cin >> t;
	while(t--){
		++tc;
		cout << "Case #" << tc << ": "; 
		cin >> n;
		for(int i = 1 ; i <= n ; ++i){
			str1[i] = "";
			str2[i] = "";
			cin >> str1[i] >> str2[i];
		}
		memset(dp , -1 , sizeof(dp));
		cout << solve(0) << endl;
	}
}