#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
	int e,n,cnt;
	node(int _e,int _n,int _cnt):
		e(_e),n(_n),cnt(_cnt){}
};
const int N = 20;
int v[N],R,E,sz;
int bfs(){
	queue<node>Q;
	Q.push(node(E,1,0));
	int ans=-1;
	while(!Q.empty()){
		node p=Q.front();Q.pop();
		int e=p.e,n=p.n,cnt=p.cnt;
		if(n==sz+1){
			ans=max(ans,cnt);
			continue;
		}
		for(int i=0;i<=e;i++){
			Q.push(node(min(e-i+R,E),n+1,cnt+i*v[n]));
		}
	}
	return ans;
}
int main(){
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		scanf("%d%d%d",&E,&R,&sz);
		for(int i=1;i<=sz;i++)scanf("%d",&v[i]);
		int ans=bfs();
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
