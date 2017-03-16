#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <string.h>
#include <set>
using namespace std;
typedef __int64 LL;
set<string>S;
int maxL;
void pre(){
	freopen("c.in","r",stdin);
	string x;
	maxL=0;
	while(cin>>x){
		if(x == "****")break;
		S.insert(x);
		maxL = max(maxL,(int)x.length());
	}
	return;
}
int dp[1000 + 5];
int pos[15];
string tmp;
int curidx = 0;
string cc;
void dfs(int idx,int cnt) {
	 if(idx >= tmp.length()) {
	 	string chk = "";
	 	int ff = 0;
	 	for(int j = 0;j < tmp.length();j++) {
			chk += tmp[j];
			if(tmp[j] != cc[j])ff++;
			if(dp[curidx-j] == -1) continue;
			if(S.find(chk) != S.end()) {
				if(dp[curidx+1] == -1 || dp[curidx+1] > dp[curidx-j]+ff){
					dp[curidx+1]=dp[curidx-j]+ff;
				}
			} 
		}
		 return;
	 }
	 for(char j = 'a';j <= 'z';j++) {
	 	 char t = tmp[idx];
	 	 tmp[idx] = j;
	 	 if(idx + 5 >= tmp.length()) {
		  	dfs(tmp.length(),cnt+(j!=t));
  		 }else{
		 	for(int i = idx+5;i < tmp.length();i++) {
		 		pos[i]=1;
			 	dfs(i,cnt+(j!=t));
			 	pos[i]=0;
			 }  
   		 }
	 	 tmp[idx] = t;
	 }
}
int main(){
	pre();
	int t,cas=0;
	scanf("%d",&t);
	while(t--){
		string str;
		cin>>str;
		string strt = "";
		for(int i = str.length()-1;i>= 0;i--)strt+=str[i];
		str=strt;
		memset(dp,-1,sizeof(dp));
		dp[0]=0;
		for(int i = 0;i < str.length();i++){
				tmp = "";
				for(int j = i;j >=max(0,i-maxL+1);j--) tmp += str[j];
				curidx = i;
				cc = tmp;
				for(int j = 0;j < tmp.length();j++){ 
					dfs(j,0);	
				}
		}
		printf("Case #%d: %d\n",++cas,dp[str.length()]);
	}

	return 0;
}