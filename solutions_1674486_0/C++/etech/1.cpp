//Besm Allah

#include<iostream>
using namespace std;

const int N=1000 +10;
int n;
int adj[N][N];
int cnt[N];
int counter;
int lst[N];
int place[N];
bool mark[N];
void dfs(int v){
	mark[v] = 1;
	for(int i= 0 ; i < cnt[v] ; i++){

		int u = adj[v][i];
		if(!mark[u])
			dfs(u);
	}
	place[v]=counter;
	lst[counter--]=v;
}

int main(){
	int T;int cse = 0;
	cin>>T;
	int dyn[N];
	while(T--){
		cse++;
		cin>>n;
		counter=n-1;
		for(int i = 1 ; i <= n ; i++){
			mark[i]=0;
		}
		for(int i = 1; i <= n ; i ++){
			cin>>cnt[i];
			for(int j = 0 ; j < cnt[i]; j++)
				cin>>adj[i][j];
		}
		for(int i = 1 ; i <= n  ; i++)
			if(!mark[i])
				dfs(i);
		bool answer=false;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j<= n ; j++)
				dyn[j] = 0;
			dyn[i] = 1;
			for(int j=0 ; j < n ; j++){
				int v = lst[j];
				for(int t = 0 ; t < cnt[v] ; t++){
					int u = adj[v][t];
					if(place[u] > place[v]){
						dyn[u]+=dyn[v];
						if(dyn[u] >= 2){
								cout<<"Case #"<<cse<<": Yes"<<endl;
								answer=true;
								goto here;
						}
					}
				}
			}
		/*	cout<<"salam "<<i<<endl;
			for(int j = 1 ; j <= n ; j++)
				cout<<j<<" "<<dyn[j]<<endl;
			cout<<"------------"<<endl;
		*/}

		here:
			if(!answer)
				cout<<"Case #"<<cse<<": No"<<endl;
	}
}
