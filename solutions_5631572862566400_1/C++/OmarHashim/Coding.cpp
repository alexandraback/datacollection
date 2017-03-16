#include<bits/stdc++.h>
using namespace std;

#define scl(x) scanf("%lld",&x)
#define sc(x)  scanf("%d",&x)
#define ll long long
#define lop(i,n) for(int i=0;i<n;++i)
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

const int mN=1010;
int adjList[mN];
int n,t,st,vis[mN],ssval[mN];
bool sa7bsa7bo[mN];
int dfs(int cur){
	if(vis[cur])return -50000;
	if(cur==st)return 0;
	vis[cur]=1;
	return 1+dfs(adjList[cur]);
}
void dfs2(int cur,int v){
	if(sa7bsa7bo[cur]){
		ssval[cur]=max(ssval[cur],v);
		return ;
	}
	if(vis[cur])return ;
	vis[cur]=1;
	dfs2(adjList[cur],v+1);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("i.txt","r",stdin);
	freopen("o.txt","w",stdout);
#endif
	sc(t);
	lop(C,t){
		memset(ssval,0,sizeof ssval);
		memset(sa7bsa7bo,0,sizeof sa7bsa7bo);
		sc(n);
		lop(i,n){
			sc(adjList[i]);
			--adjList[i];
		}
		int out1=0;
		lop(i,n){
			memset(vis,0,sizeof vis);
			st=i;
			out1=max(out1,dfs(adjList[i])+1);
		}
		lop(i,n){
			if(adjList[adjList[i]]==i){
				sa7bsa7bo[i]=1;
			}
		}
		lop(i,n){
			memset(vis,0,sizeof vis);
			dfs2(i,0);
		}
		int out2=0;
		lop(i,n){
			if(sa7bsa7bo[i])out2+=1+ssval[i];
		}
		printf("Case #%d: %d\n",C+1,max(out1,out2));
	}
}
