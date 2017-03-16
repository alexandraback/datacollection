#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
int N;
int A[1010];
vector<int> E[1010];
int V[1010];
int bfs(int start){
	queue<pair<int,int> > q;
	q.push({start,1});
	V[start]=1;
	int last=1;
	while(q.size()>0){
		pair<int,int> pos=q.front();
		q.pop();
		last=pos.second;
		for(int i=0;i<E[pos.first].size();i++){
			if(V[E[pos.first][i]]==0){
				q.push({E[pos.first][i],pos.second+1});
				V[E[pos.first][i]]=1;
			}
		}
	}
	return last;
}
int solve(){
	int mx=0;
	for(int i=1;i<=N;i++){
		memset(V,0,sizeof(V));
		int j=i;
		int cnt=0;
		while(V[j]==0){
			V[j]=1;
			j=A[j];
			cnt++;
		}
		if(j==i){
			mx=max(mx,cnt);
		}
	}
	memset(V,0,sizeof(V));
	int tot=0;
	vector<int> ds;
	for(int i=1;i<=N;i++){
		if(i==A[A[i]] && i<A[i]){
			for(int j=0;j<E[i].size();j++){
				if(E[i][j]==A[i]){
					E[i].erase(E[i].begin()+j);
				}
			}

			for(int j=0;j<E[A[i]].size();j++){
				if(E[A[i]][j]==i){
					E[A[i]].erase(E[A[i]].begin()+j);
				}
			}
			int v1=bfs(i);
			int v2=bfs(A[i]);
			tot=tot+v1+v2;
		}
	}
	mx=max(tot,mx);
	return mx;
}
int main(int argc, char const *argv[]){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		for(int i=0;i<1001;i++){
			E[i].clear();
		}
		cin >> N;
		for(int i=0;i<N;i++){
			cin >> A[i+1];
			E[A[i+1]].push_back(i+1);
		}
		int ans = solve();
		printf("Case #%d: %d\n",t+1,ans);
	}
	return 0;
}