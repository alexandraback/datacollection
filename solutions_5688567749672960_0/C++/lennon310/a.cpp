#include<iostream>
#include<algorithm>
#include<cstring>
#include <string>
#include<vector>
#include <queue>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll solve(ll x){
	if (x<=20) return x;
	if (x<100){
		ll d = x/10;
		ll res = 10+d+1;
		ll d2 = x%10;
		res += (d2-1);
		return res;
	}
	if (x<1000){
		ll res = solve(99)+1;
		if (x<=200) return res+x-100;
		ll d = x/100;
		res += d+1;
		ll d2 = x%100;
		res += (d2-1);
		return res;
	}
	if (x<10000){
		ll res = solve(999)+1;
		if (x<=2000) return res+x-1000;
		ll d = x/1000;
		res += d+1;
		ll d2 = x%1000;
		res += (d2-1);
		return res;
	}
	if (x<100000){
		ll res = solve(9999)+1;
		if (x<=20000) return res+x-10000;
		ll d = x/10000;
		res += d+1;
		ll d2 = x%10000;
		res += (d2-1);
		return res;
	}
	if (x<=1000000){
		ll res = solve(99999)+1;
		if (x<=200000) return res+x-100000;
		ll d = x/100000;
		res += d+1;
		ll d2 = x%100000;
		res += (d2-1);
		return res;
	}
}
int dp[1000001];
int main(){
    freopen("input1.txt","r",stdin);
  // freopen("A-small-attempt1.in","r",stdin);
   //freopen("A-large.in","r",stdin);
   // freopen("output1.txt","w",stdout);
    
    int t;
    cin >> t;
	for(int i=0;i<=1000000;i++) dp[i] = i;
    for(int i = 1; i < 1000000; i++) {
		string s = std::to_string(i);
		reverse(s.begin(), s.end());
		int rtmp = std::stoi(s);
		dp[i+1] = min(dp[i+1],dp[i]+1);
		dp[rtmp] = min(dp[rtmp], dp[i] + 1);
	}
    for(int ti=1;ti<=t;ti++){
		cout << "Case #"<<ti<<": ";
        cin>>n;
		if (n<=20) {
			cout << n << "\n";
			continue;
		}
		cout << dp[n] << "\n";

    }
    return 0;
}
