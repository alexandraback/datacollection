#include <bits/stdc++.h>
using namespace std;

long f[1005], ans, ans1, mx, N, T, its, visited[1005][1005];
vector<long> b[1005];

long dfs_back(long v, long l=0) {
	//cout<<"NBB = "<<v<<endl;
	int flag = 0;
	if(!visited[v][0]){
		visited[v][0] = 1;
		flag = 1;
	}
	long a = 1;
	long t=0;
	for(int i=0; i<b[v].size(); i++) {
		if(!visited[b[v][i]][0]) {
			//cout<<"BACK "<<b[v][i]<< " AND VISITED = "<<visited[b[v][i]];
			long x = dfs_back(b[v][i], l+1);
			if(x > t) t = x;
		}
	}
	if(flag)visited[v][0] = 0;
	return a+t;
}

long dfsonlyl(long v, long l, long itr) {
	//cout<<"N= "<<v<<endl;
	visited[v][0] = l+1;
	visited[v][itr] = l+1;
	if(visited[f[v]][0]) {
		if(visited[f[v]][itr] == l) {
			long dfsback;
			dfsback = dfs_back(v);
			ans1 = l+1+dfsback-1;
			//cout<<"DFSBACK1 = "<<dfsback-1<<endl;
			if(visited[f[v]][itr]==1) {
				dfsback = dfs_back(f[v])-1;
				//cout<<"DFSBACK2 = "<<dfsback<<endl;
				ans1+=dfsback;
			}
			//return 0;
		}
		else {
			ans1 = 0;
			//return 0;
		}
	}
	else {
		dfsonlyl(f[v], l+1, itr);
		//return 0;
	}
	visited[v][0] = 0;
	visited[v][itr] = 0;
}

long dfs(long v, long l) {
	//cout<<"N= "<<v<<endl;
	visited[v][0] = l+1;

	if(visited[f[v]][0]) {
		if(visited[f[v]][0] == l) {
			long dfsback;
			dfsback = dfs_back(v);
			ans = l+1+dfsback-1;
			//cout<<"DFSBACK1 = "<<dfsback-1<<endl;
			if(visited[f[v]][0]==1) {
				dfsback = dfs_back(f[v])-1;
				//cout<<"DFSBACK2 = "<<dfsback<<endl;
				ans+=dfsback;
			}
			ans1=0;
			long mx1=0;
			for(int k=0; k<N; k++) {
				if(!visited[k][0]){
					dfsonlyl(k, 0, its++);
					if(ans1>mx1) ans1 = mx1;
				}
			}
			ans+=ans1;
			//return 0;
		}
		else {
			ans = l+1-(visited[f[v]][0]-1);
			//return 0;
		}
	}
	else {
		dfs(f[v], l+1);
		//return 0;
	}
	visited[v][0] = 0;
	
}

int main(){
	cin>>T;
	long x;
	for(int t=0; t<T; t++) {
		its = 1;
		for(int i=0; i<1001; i++){
			b[i].clear();
		}
		for(int i=0; i<1000; i++){
			for(int j=0; j<50; j++){
				visited[i][j]=0;
			}
		}
		cin>>N;
		for(int i=0; i<N; i++) {
			cin>>x;
			f[i] = x-1;
			b[x-1].push_back(i);
		}
		mx = 0;
		ans = 0;
		for(int i=0; i<N; i++){
			dfs(i, 0);
			if(ans>mx)mx = ans;
		}
		cout<<"Case #"<<t+1;
		cout<<": "<<mx<<endl;
	}
}