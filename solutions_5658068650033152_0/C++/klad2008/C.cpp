#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#define LL long long
using namespace std;
class poi{public:int x,y;}q[510];
int N,M,l,r,ans,T,K;
bool use[21][21],vis[21][21];
const int fx[4]={0,0,1,-1};
const int fy[4]={1,-1,0,0};
void dfs(int x,int y){
	if (x>N){
		l=1;r=0;
		memset(vis,false,sizeof(vis));
		for (int i=1;i<=M;i++){
			if (!use[1][i])q[++r].x=1,q[r].y=i,vis[1][i]=true;
			if (!use[N][i])q[++r].x=N,q[r].y=i,vis[N][i]=true;
		}
		for (int i=1;i<=N;i++){
			if (!use[i][1])q[++r].x=i,q[r].y=1,vis[i][1]=true;
			if (!use[i][M])q[++r].x=i,q[r].y=M,vis[i][M]=true;
		}
		for (;l<=r;l++){
			poi t=q[l],tt;
			for (int k=0;k<4;k++)
			if (t.x+fx[k]&&t.x+fx[k]<=N)
			if (t.y+fy[k]&&t.y+fy[k]<=M){
				tt.x=t.x+fx[k];
				tt.y=t.y+fy[k];
				if (!vis[tt.x][tt.y]&&!use[tt.x][tt.y]){
					q[++r]=tt;
					vis[tt.x][tt.y]=true;
				}
			}
		}
		int sum=0;
		for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
		if (!vis[i][j])sum++;
		if (sum>=K){
			sum=0;
			for (int i=1;i<=N;i++)
			for (int j=1;j<=M;j++)
			if (use[i][j])sum++;
			ans=min(ans,sum);
		}
		return;
	}
	if (y<M)dfs(x,y+1);
	else dfs(x+1,1);
	use[x][y]=true;
	if (y<M)dfs(x,y+1);
	else dfs(x+1,1);
	use[x][y]=false;
}
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++){
		scanf("%d%d%d",&N,&M,&K);
		ans=2e9;
		dfs(1,1);
		printf("Case #%d: %d\n",tt,ans);
	}
}
