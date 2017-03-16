#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

struct Node{
		int x,y,v;
}data[10010];

int T,n,m;
int aim[111][111],pre[111][111];

bool cmp(Node a,Node b){
	return a.v<b.v;
}

int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	for (int caseT=1;caseT<=T;caseT++){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++){
				scanf("%d",&aim[i][j]);
				pre[i][j]=100;
				data[(i-1)*m+j].x=i;
				data[(i-1)*m+j].y=j;
				data[(i-1)*m+j].v=aim[i][j];
			}
		sort(data+1,data+1+n*m,cmp);
		bool can=true;
		for (int i=1;i<=n*m;i++){
			int x=data[i].x,y=data[i].y;
			if (pre[x][y]==data[i].v) continue;
			bool flag=true;
			for (int j=1;j<=n;j++)
				if (aim[j][y]>aim[x][y]) flag=false;
			if (flag){
				for (int j=1;j<=n;j++)
					pre[j][y]=min(pre[j][y],aim[x][y]);
				continue;
			}
			flag=true;
			for (int j=1;j<=m;j++)
				if (aim[x][j]>aim[x][y]) flag=false;
			if (flag){
				for (int j=1;j<=n;j++)
					pre[x][j]=min(pre[x][j],aim[x][y]);
				continue;
			}
			can=false; break;
		}
		if (can) printf("Case #%d: YES\n",caseT);
		else printf("Case #%d: NO\n",caseT);
	}
	return 0;
}
