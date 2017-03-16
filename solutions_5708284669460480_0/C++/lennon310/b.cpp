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
int K,L,S;
int nCr(int n, int r){
	int ans = 1;
	if (r==0 || r==n) return 1;
	for(int i=1;i<=r;i++){
		ans *= (n-i+1);
		ans /= i;
	}
	return ans;
}
double dp[101][101];
string x = "";
string s1,s2;
int cnt = 0, ans = 0, tmp = 0;
void solve(){
	if (x.length() == S){
		tmp = 0;
		for(int i=0;i<S;i++){		
			if (x.substr(i, L) == s2){
				cnt++;
				tmp++;
			}
		}		
		ans = max(ans, tmp);
		return;
	}
	for(int i=0;i<K;i++){
		x += s1[i];
		solve();
		x.pop_back();
	}
}
int main(){
  //  freopen("input1.txt","r",stdin);
   freopen("B-small-attempt1.in","r",stdin);
  // freopen("A-large-practice.in","r",stdin);
    freopen("output1.txt","w",stdout);
    
    int t;
    cin >> t;
	
    for(int ti=1;ti<=t;ti++){
		cout << "Case #"<<ti<<": ";
        cin>>K>>L>>S;
		
		cin>>s1;
		cin>>s2;
		map<char,int> mp;
		for(int i=0;i<s1.length();i++){
			if (mp.count(s1[i])) mp[s1[i]]++;
			else mp[s1[i]] = 1;
		}
		bool ok = true;
		for(int i=0;i<s2.length();i++){
			if (!mp.count(s2[i])){
				ok = false;
				break;
			}
		}
		if (!ok || S<s2.length()){
			printf("%.7f\n",0.0);
			continue;
		}
		cnt = 0;
		ans = 0;
		solve();
		printf("%.7f\n",abs(1.0*ans-1.0*cnt/pow(K,S)));
		/*double odd = 1.0;
		for(int i=0;i<s2.length();i++){
			double tmp = 1.0*mp[s2[i]]/s1.length();
			odd *= tmp;
		}
		if (S==s2.length()){
			printf("%.7f\n",1.0-odd);
			continue;
		}
		if (s2.length()==1){
			odd = 0.0;
			double tmp = 1.0*mp[s2[0]]/s1.length();
			for(int i=1;i<=S;i++){
				odd += i*nCr(S,i)*tmp*(1-tmp);
			}
			printf("%.7f\n",1.0*S-odd);
			continue;
		}
		odd = 0.0;
		double tmp = 1.0*mp[s2[0]]/s1.length();
		dp[1][0] = 0.0;
		for(int j=1;j<=S;j++){
			odd = 0.0;
			/*for(int i=1;i<=j;i++){
				odd += i*nCr(j,i)*tmp*(1-tmp);
				
			}*/
		/*	odd = tmp*1.0*pow(tmp,i-1);
			dp[1][j] = odd;
		}
		for(int i=2;i<=s2.length();i++){
			for(int j=i+1;j<=S;j++){
				double pr = (1.0*mp[s2[i-1]])/s1.length();
				dp[i][j] = dp[i-1][j]*(1-pr) + (1+dp[i-1][j-1])*pr;
			}
		}
		//printf("%.7f\n",dp[s2.length()][S]);
		printf("%.7f\n",1.0*(S-s2.length()+1)-dp[s2.length()][S]);*/
    }
    return 0;
}
