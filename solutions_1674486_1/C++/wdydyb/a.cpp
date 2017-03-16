#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#include<set>
#define all(c) c.begin(),c.end()
#define pb push_back
#define uni(c) c.erase(unique(all(c)),c.end())
using namespace std;
int n;
map<int,int> mp;
map<int,bool> used;
int s;
bool f(int now,vector<vector<int> > v){
	
	if(used[now])
		return false;
	
	if(mp[now]){
		return true;
	}
	mp[now]++;
	used[now]=true;
	for(int i=0;i<v[now].size();i++){
		if(!used[v[now][i]]&&f(v[now][i],v)){
			return true;
		}
	}
	
	return false;
}

int main(){
	int t;
	cin>>t;
	int cnt=1;
	while(t--){
		cin>>n;
		vector<vector<int> > v(n);
		int x,y;
		for(int i=0;i<n;i++){
			cin>>x;
			for(int j=0;j<x;j++){
				cin>>y;
				v[i].pb(y-1);
			}
		}
		cout<<"Case #"<<cnt++<<": ";
		for(int i=0;i<n;i++){
			mp.clear();
			for(int j=0;j<v[i].size();j++){
				used.clear();
				used[i]=true;
				bool flag=f(v[i][j],v);
				if(flag){
					cout<<"Yes"<<endl;
					goto end;
				}
			}
		}
		cout<<"No"<<endl;
		end:;
	}
	return 0;
}