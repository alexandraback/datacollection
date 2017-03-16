#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[1001][1001];
int visited [1001];

void dfs(int k,int n){
	visited[k]++;
	//cout<<k<<" "<<visited[k]<<"\n";
	int i,j;
	//for(i=0;i<n;i++)for(j=0;j<n;j++) cout<<a[i][j]<<" ";
	for(i=0;i<n;i++){
		if(a[k][i]==1&&visited[i]<=1&&i!=k) {
		//cout<<"hello";
		dfs(i,n);
		}
	}
}
int main(){
int T;
cin>>T;
int tc;
for(tc=1;tc<=T;tc++){
	int n;
	cin>>n;
	int i,j;
	memset(a,0,sizeof a);
	for(i=0;i<n;i++){
		int m;
		cin>>m;
		int j,x;
		for(j=1;j<=m;j++){
			cin>>x;
			a[i][x-1]=1;
		}
	}
	memset(visited,0,sizeof visited);
	bool found = false;
	for(i=0;i<n;i++){
		if(visited[i]==0){
			//for(i=0;i<n;i++)for(j=0;j<n;j++) cout<<a[i][j]<<" ";
			dfs(i,n);
			//for(i=0;i<n;i++)for(j=0;j<n;j++) cout<<a[i][j]<<" ";
			for(j=0;j<n;j++) if(visited[j]>1){
			found=true;
			break;
			}
			if(found) break;
		}
		memset(visited,0,sizeof visited);
		//for(j=0;j<n;j++) if(visited[j]>1)visited[j]=1;
	}
	if (found)
	printf("Case #%d: Yes\n",tc);
	else
	printf("Case #%d: No\n",tc);
}
return 0;
}
