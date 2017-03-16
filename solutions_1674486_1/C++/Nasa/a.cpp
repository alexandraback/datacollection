#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;


#define MAX 1001
int visited[MAX],adjlist[MAX][MAX],adjc[MAX],di[MAX];

int dfs(int x, int p){
	int i;
	if (visited[x]) return false;
	visited[x]=1;
	for (i=0; i<adjc[x]; i++){
		if (adjlist[x][i]!=p && (i || adjlist[x][i]!=adjlist[x][i-1]))
			if (!dfs(adjlist[x][i],x)) 
				return 0;
	}
	return 1;
}

int M=0;
int q[1000000],qh,qt;
int dfs2(int x){
	M++;
	qh=qt=0;
	q[qt++]=x;
	while(qh<qt){
		x=q[qh++];
		if (visited[x]==M) return 0;
		visited[x]=M;
		for (int i=0; i<adjc[x]; i++)
			q[qt++]=adjlist[x][i];
	}	
	return 1;
}

int main(){
	int mx,t,u,n,m,i,j,k,a,b,s,ss;
	cin>>t;
	for (u=0; u<t; u++){
		cin>>n;
		for (i=0; i<n; i++)
			adjc[i]=0;
		for (i=0; i<n; i++){
			cin>>m;
			di[i]=m;
			for (j=0; j<m; j++){
				cin>>a;
				a--;
				adjlist[a][adjc[a]++]=i;
			}
		}
		for (i=0; i<n; i++){
			if (di[i]==0) if (!dfs2(i)) break;
		}
		cout<<"Case #"<<(u+1)<<": ";
		if (i==n) cout<<"No"; else cout<<"Yes";
		cout<<endl;
	}
	return 0;
}
