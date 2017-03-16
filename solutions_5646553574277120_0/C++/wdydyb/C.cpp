#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
using namespace std;
vector<bool> d;
vector<int> coin;
int C,D,V;
map<int,bool> mp;
void search(int now,int cnt){
	if(now==D){
		if(cnt<=V)
		d[cnt]=true;
		return;
	}
	search(now+1,cnt+coin[now]);
	search(now+1,cnt);
}
int main(){
	int t,p=1;
	cin>>t;
	
	while(t--){
		int ans=0;
		cin>>C>>D>>V;
		coin.resize(D);
		d.resize(V+1);
		fill(d.begin(),d.end(),false);
		mp.clear();
		for(int i=0;i<D;i++){
			cin>>coin[i];
			mp[coin[i]]=true;
		}
		search(0,0);
		for(int i=1;i<=V;i++){
			if(!d[i]){
				ans++;
				int add;
				for(int j=1;j<=i;j++){
					if(j==i){
						add=j;
						mp[j]=true;
						coin.push_back(j);
						break;
					}
					if(!mp[j]){
						add=j;
						mp[j]=true;
						coin.push_back(j);
						break;
					}
				}
				vector<bool> tmp=d;
				for(int j=0;j+add<=V;j++){
					if(tmp[j]){
						d[j+add]=true;
					}
				}
				//cout<<i<<" "<<add<<endl;
			}
		}
		cout<<"Case #"<<p<<": "<<ans<<endl;
		p++;
		
	}
	
	return 0;
}