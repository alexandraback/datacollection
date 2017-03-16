#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define maxn 1005
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

int head[maxn],t[maxn * 2],next[maxn * 2],sum;

int low[maxn],dfn[maxn],tim;

int stack[maxn],totscc,p[maxn],fa[maxn];

bool ins[maxn];

int T,n,ans;

int head1[maxn],t1[maxn * 2],next1[maxn * 2],sum1;

void dfs(int w,int fa){
	dfn[w]=low[w]=++tim;
	stack[++stack[0]]=w;
	ins[w]=1;
	for(int tmp=head[w];tmp;tmp=next[tmp]) {
		if (tmp==fa) continue;
		if (!dfn[t[tmp]]) {
			dfs(t[tmp],tmp);
			low[w]=min(low[w],low[t[tmp]]);
		}
		else if (ins[t[tmp]]) low[w]=min(low[w],dfn[t[tmp]]);
	}
	if (dfn[w]==low[w]) {
		++totscc;
		int size=0;
		while (stack[stack[0]]!=w) {
			size++;
			int tmp=stack[stack[0]];
			ins[tmp]=0;
			p[tmp]=totscc;
			stack[0]--;
		}
		size++;
		ans=max(ans,size);
		int tmp=stack[stack[0]];
		ins[tmp]=0;
		p[tmp]=totscc;
		stack[0]--;
	}
}

void insert(int x,int y){
	t[++sum]=y;
	next[sum]=head[x];
	head[x]=sum;
}

void insert1(int x,int y){
	t1[++sum1]=y;
	next1[sum1]=head1[x];
	head1[x]=sum1;
}

int dfs1(int w,int totdis){
	int ret=totdis;
	for(int tmp=head1[w];tmp;tmp=next1[tmp]) 
		if (t1[tmp]!=fa[w]) 
			ret=max(ret,dfs1(t1[tmp],totdis+1));
	return ret;
}

int main(){
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	scanf("%d",&T);
	fo(kk,1,T) {
		ans=0;
		mem(head,0);
		mem(head1,0);
		mem(low,0);
		mem(dfn,0);
		mem(stack,0);
		mem(p,0);
		mem(ins,0);
		mem(fa,0);
		sum=0;
		sum1=0;
		scanf("%d",&n);
		fo(i,1,n) {
			int x;
			scanf("%d",&x);
			fa[i]=x;
			insert(i,x);
			insert1(x,i);
		}
		fo(i,1,n) if (dfn[i]==0) dfs(i,0);
		int tmp=0;
		fo(i,1,n) {
			if (fa[fa[i]]!=i) continue;
			tmp+=dfs1(i,1)+dfs1(fa[i],1);
		}
		ans=max(ans,tmp / 2);
		printf("Case #%d: %d\n",kk,ans);
	}
	return 0;
}
