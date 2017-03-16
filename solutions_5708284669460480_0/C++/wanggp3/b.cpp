#include <bits/stdc++.h>
using namespace std;
int K,L,S;
int maxt;
double ans;
string key,target;
void dfs(int i,string str){
	if(i==S){
		int cnt=0;
		for(int j = 0;j < S; j++){
			if(str.substr(j,L) == target)cnt++;
		}
		maxt = max(maxt,cnt);
		ans+=cnt*1.0;
	}else{
		for(int j = 0;j<K;j++){
			dfs(i+1,str+key[j]);
		}
	}
}
void solve(){
	scanf("%d%d%d",&K,&L,&S);
	cin>>key>>target;
	maxt = 0;
	ans=0;
	dfs(0,"");
	double pw = 1.0;
	for(int i=0;i<S;i++)pw=pw*K;
	ans = ans / pw;
	printf("%.7lf\n",1.0*maxt - ans);
}
int main(){
	int T;
	scanf("%d",&T);
	for(int cas=0;cas<T;cas++){
		printf("Case #%d: ",cas+1);
		solve();
	}
	return 0;
}	
