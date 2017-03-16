#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

vector<int> edge[100];
char str[100][7];
int n,m;
int ans[50];
int ans1[50];
int bo[50],t,b[12];
int L,F;

int check(){
	for (int i=1; i<=n*5; ++i)
		if (ans1[i]<ans[i]) return 1;
		else if (ans1[i]>ans[i]) return 0;
	return 1;
}

void dfs(int x,int num){
	if (num==n){
		if (check()) memcpy(ans,ans1,sizeof(ans));
		return ;
	}
	for (int i=0; i<edge[x].size(); ++i){
		int y=edge[x][i];
		/*if (y==L && !F){
			b[++t]=y;
			F=1;
			dfs(y,num);
			--t;
			F=0;
			continue;
			}*/
		if (bo[y]) continue;
		b[++t]=y;
		bo[y]=1;
		for (int j=1; j<=5; ++j) ans1[num*5+j]=str[y][j-1]-'0';
		dfs(y,num+1);
		bo[y]=0;
		--t;
	}
	if (t>1){
		int bb[12];
		memcpy(bb,b,sizeof(bb));
		int tt=t;
		--t;
		dfs(b[t],num);
		memcpy(b,bb,sizeof(b));
		t=tt;
	}
}

int main(){
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	int T,Tnum=0;
	scanf("%d",&T);
	for (;T;--T){
		scanf("%d%d",&n,&m);
		for (int i=1; i<=n*5; ++i) ans[i-1]=9;
		for (int i=1; i<=n; ++i) edge[i].clear();
		for (int i=1; i<=n; ++i) scanf("%s",str[i]);
		memset(bo,0,sizeof(bo));
		for (int i=1; i<=m; ++i){
			int x,y;
			scanf("%d%d",&x,&y);
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		for (int i=1; i<=n; ++i){
			bo[i]=1;
			t=1; b[1]=i;
			L=i; F=0;
			for (int j=1; j<=5; ++j) ans1[j]=str[i][j-1]-'0';
			dfs(i,1);
			bo[i]=0;
		}
		printf("Case #%d: ",++Tnum);
		for (int i=1; i<=n*5; ++i) printf("%d",ans[i]);
		printf("\n");
	}
}
