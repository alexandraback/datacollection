#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

#define N 1004
#define M 1003
#define ll long long
#define inf 1<<29
#define mod 20100501
#define lson (id<<1)
#define rson (id<<1|1)

#define eps 1e-8
#define pii pair<int,int>
#define pdd pair<double,double>
#define It map<unsigned,string>::iterator
#define MP(i,j) make_pair(i,j)

int n,m;
//int a[N],b[N];
bool used[N];

struct Node{
	int a,b;
	friend bool operator<(const Node& x,const Node& y){
		if(x.b!=y.b)
			return x.b<y.b;
		else
			return x.a<y.a;
	}
}node[N];
int ans=inf;
bool va[N],vb[N];

void dfs(int step,int star,int oknum){
	if(oknum==n){
		ans=min(ans,step);
		return;
	}
	if(step>=ans)
		return;
	if(n-oknum+step>=ans)
		return;
	//a
	for(int i=0;i<n;i++){
		if(!va[i] && !vb[i] && star>=node[i].a){
			va[i]=true;
			dfs(step+1,star+1,oknum);
			va[i]=false;
		}
	}
	//b
	for(int i=0;i<n;i++){
		if(!vb[i] && star>=node[i].b){
			vb[i]=true;
			if(va[i])
				dfs(step+1,star+1,oknum+1);
			else
				dfs(step+1,star+2,oknum+1);
			vb[i]=false;
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif

	int cas,pcas=1;
	scanf("%d",&cas);
	while(cas--){
		scanf("%d",&n);
		memset(va,false,sizeof(va));
		memset(vb,false,sizeof(vb));
		for(int i=0;i<n;i++)
			scanf("%d%d",&node[i].a,&node[i].b);
		sort(node,node+n);
		ans=inf;
		dfs(0,0,0);
		if(ans==inf)
			printf("Case #%d: Too Bad\n",pcas++);
		else
			printf("Case #%d: %d\n",pcas++,ans);
	}
	return 0;
}

