#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


int dfs2(int i,vector<int> adj2[],int ans){
	if(adj2[i].size()==0)return ans;
	else{
	int temp=0;
	for(int j=0;j<adj2[i].size();j++){
				int abc=dfs2(adj2[i][j],adj2,ans++);
				if(abc>temp)
					temp=abc;
			}
	}
}
int dfs(int adj[],int visited[],int i,int ans,int vislocal[],int NUM,vector<int> adj2[]){
	if(vislocal[i]!=-1){
		if(i==adj[adj[i]]){
			int temp=0;
			for(int j=0;j<adj2[adj[i]].size();j++){
				if(i!=adj2[adj[i]][j]){
				int abc=dfs2(adj2[adj[i]][j],adj2,1);
				if(abc>temp)
					temp=abc;
				}
			}
			return temp+ans;
		}
		else
			return ans-vislocal[i];
	}
	else{
		visited[i] = 1;
		vislocal[i] = ans;
		ans++;
		dfs(adj,visited,adj[i],ans,vislocal,NUM,adj2);
	}
}



int dfs_util(int adj[],int N,vector<int> adj2[]){
	int ans=0;
	int visited[N+1];
	for(int i=1;i<=N;i++)
		visited[i]=0;
	for(int i=1;i<=N;i++){
		int vislocal[N+1];
		for(int j=1;j<=N;j++)
			vislocal[j] =-1;
			int temp = dfs(adj,visited,i,0,vislocal,i,adj2);
			if(temp>ans)
				ans = temp;
	}
	return ans;
}
int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int N;
		cin >> N;
		int adj[N+1];
		vector<int> adj2[N+1];
		for(int j=0;j<N;j++){
			cin >> adj[j+1];
			adj2[adj[j+1]].push_back(j+1);
		}
		int ans = dfs_util(adj,N,adj2);
		cout << "Case #"<< (i+1)<<": " <<ans << endl;
	}
	
}
