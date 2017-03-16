#include <bits/stdc++.h>
using namespace std;
const int maxn=2500;
int T,pt,N,l,r,ans1,ans2;
int in[1010],st[1010],ne[1010],go[1010],q[1010],a[1010];
void Add(int x,int y){ne[++pt]=st[x];st[x]=pt;go[pt]=y;}
int dfs(int x,int p){
	int dep=1;
	for (int i=st[x];i;i=ne[i])
		if (go[i]!=p)
			dep=max(dep,dfs(go[i],x)+1);
	return dep;
}
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++){
		memset(st,0,sizeof(st));pt=0;
		scanf("%d",&N);
		for (int i=1;i<=N;i++){
			scanf("%d",&a[i]);
			in[a[i]]++;
			Add(a[i],i);
		}
		l=1;r=0;
		for (int i=1;i<=N;i++)if (!in[i])q[++r]=i;
		for (;l<=r;l++){
			int x=q[l];in[a[x]]--;
			if (!in[a[x]])q[++r]=a[x];
		}
		ans1=ans2=0;
		for (int i=1;i<=N;i++)
			if (in[i]){
				q[l=r=1]=i;in[i]--;
				for (;l<=r;l++){
					int x=q[l];
					if (a[x]==q[1])break;
					in[a[x]]--;
					q[++r]=a[x];
				}
				if (r>2){ans1=max(ans1,r);continue;}
				int t1=dfs(q[1],q[2]);
				int t2=dfs(q[2],q[1]);
				ans2+=t1+t2;
			}
		printf("Case #%d: %d\n",tt,max(ans1,ans2));
	}
}