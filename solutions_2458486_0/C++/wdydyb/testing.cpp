#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#define pb push_back
using namespace std;
typedef pair<int,map<int,int> > P;
vector<int> kn;
vector<vector<int> > gt;
int n;

map<P,vector<int> > dp;
vector<int> cal(int vis,map<int,int> key){
	if(dp[P(vis,key)].size()!=0){
		return dp[P(vis,key)];
	}
	vector<int> ret;
	
	if((1<<n)-1==vis){
		return dp[P(vis,key)]=ret;
	}
	for(int i=0;i<n;i++){
		if(!((1<<i)&vis)&&key[kn[i]]){
			key[kn[i]]--;
			for(int j=0;j<(int)gt[i].size();j++){
				key[gt[i][j]]++;
			}
			ret=cal((1<<i)|vis,key);
			if(!(ret.size()==1&&ret[0]==-1)){
				ret.pb(i);
				return dp[P(vis,key)]=ret;
			}
			key[kn[i]]++;
			for(int j=0;j<(int)gt[i].size();j++){
				key[gt[i][j]]--;
			}
		}
	}
	ret.clear();
	ret.pb(-1);
	return dp[P(vis,key)]=ret;
	
}
int main(){
	int T;
	cin>>T;
	int cnt=0;
	while(T--){
		int k;
		dp.clear();
		cin>>k>>n;
		map<int,int> key;
		for(int i=0;i<k;i++){
			int x;
			cin>>x;
			key[x]++;
		}
		kn.resize(n);
		gt.clear();
		gt.resize(n);
		for(int i=0;i<n;i++){
			int x;
			cin>>kn[i]>>x;
			for(int j=0;j<x;j++){
				int y;
				cin>>y;
				gt[i].pb(y);
			}
		}
		
		vector<int> ans=cal(0,key);
		
		cout<<"Case #"<<++cnt<<":";
		if(ans[0]==-1){
			cout<<" IMPOSSIBLE"<<endl;
			continue;
		}
		for(int i=ans.size()-1;i>=0;i--){
			cout<<" "<<ans[i]+1;
		}
		cout<<endl;
		
	}
	return 0;
}