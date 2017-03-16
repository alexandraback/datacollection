#include <bits/stdc++.h>

using namespace std;


int Reverse(int n){
	int ans = 0;
	while(n){
		ans *=10;
		ans += n%10;
		n/=10;
	}
	return ans;
}

vector<bool> vis;
int bfs(int n){
	queue<int> q;
	vis.clear();
	vis.resize(6654321,0);
	vis[1] = 1;
	q.push(1);
	int lvl = 0;
	while(q.size()){
		int sz = q.size();
		lvl++;
		while(sz--){
			int cur = q.front();
			q.pop();
			if(cur == n)return lvl;

			int r = Reverse(cur);
			if(!vis[r]){
				vis[r]=1;
				q.push(r);
			}
			int nxt = cur+1;
			if(!vis[nxt]){
				vis[nxt] = 1;
				q.push(nxt);
			}
		}
	}
	return n;
}

int main(){
	freopen("in.in","rt",stdin);
	freopen("out.out","wt",stdout);
	int t;
	cin>>t;
	int cs = 0;
	while(t--){
		int n;
		cin>>n;
		cout<<"Case #"<<++cs<<": ";
		cout<<bfs(n)<<endl;
	}

}
