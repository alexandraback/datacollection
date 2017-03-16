#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int perm[10];
int ppp[10];
int T;
int E,R,N;
int v[11];
int ans;
void dfs(int pos,int cure){
	if(pos==N){
		memcpy(ppp,perm,sizeof(ppp));
		sort(ppp,ppp+N);
		int tans=0;
		for(int i=0;i!=N;i++){
			tans+=v[i]*ppp[i];
		}
		ans=max(ans,tans);
		return;
	}
	for(int i=0;i<=cure;i++){
		perm[pos]=i;
		dfs(pos+1,min(cure-i+R,E));
	}
}
int main(){
#ifdef LOCAL
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	int cc=1;
	cin>>T;
	while(cc<=T){
		ans=0;
		cin>>E>>R>>N;
		for(int i=0;i!=N;i++){
			cin>>v[i];
		}
		sort(v,v+N);
		dfs(0,E);
		cout<<"Case #"<<cc++<<": "<<ans<<endl;
	}
}
