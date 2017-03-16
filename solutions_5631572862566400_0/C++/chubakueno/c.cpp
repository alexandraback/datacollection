#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int bff[1005];
int vis[2505];
int lc[2505];
int depth[2505];
int dfs(int x, int curd){
	if(vis[x]){
		if(lc[x]==-1) lc[x]=abs(curd-depth[x]);
		else return lc[x];
	}
	vis[x]=1;
	depth[x]=curd;
	return lc[x]=dfs(bff[x],curd+1);
}
int main(){
	int t;
	cin>>t;
	for(int z=1;z<=t;++z){
		int n;
		cin>>n;
		vector<int> vec;
		memset(vis,0,sizeof vis);
		memset(lc,-1,sizeof lc);
		for(int j=0;j<n;++j){
			cin>>bff[j];
			--bff[j];
		}
		int ori[10],arr[10];
		for(int i=0;i<n;++i)
			ori[i]=i;
		int ans=0;
		for(int i=1;i<(1<<n);++i){
			int ptr=0;
			for(int j=0;j<n;++j){
				if(i&(1<<j))
					arr[ptr++]=ori[j];
			}
			do{
				bool ok=true;
				for(int j=0;j<ptr;++j){
					int aux=bff[arr[j]];
					if(!(aux==arr[(j+1)%ptr]||aux==arr[(j+ptr-1)%ptr])){
						ok=false;
						break;
					}
				}
				if(ok) ans=max(ans,ptr);
			}while(next_permutation(arr,arr+ptr));
		}
		printf("Case #%d: %d\n",z,ans);
	}
}