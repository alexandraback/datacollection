#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
bool vis[1000010];
int reverse(int u){
	int c=0;
	while(u!=0){
		c=c*10+u%10;
		u/=10;
	}
	return c;
}
int main(){
	int cases;
	cin>>cases;
	int tc=1;
	while(cases--){
		int n;cin>>n;
		memset(vis,0,sizeof vis);
		queue<pair<int,int> >q;
		q.push({1,1});
		while(!q.empty()){
			pair<int,int> u=q.front();
			q.pop();
			if(vis[u.first])continue;
			vis[u.first]=true;
			if(u.first==n){
				cout<<"Case #"<<tc++<<": "<<u.second<<"\n";
				break;
			}
			q.push({reverse(u.first),u.second+1});
			q.push({u.first+1,u.second+1});
		}
	}
}
