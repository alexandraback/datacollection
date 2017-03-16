#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn (1005)
using namespace std;

queue<int>Qx,Qy;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int H,N,M,test;
int Ceil[maxn][maxn],Floor[maxn][maxn];
double F[maxn][maxn];
bool vis[maxn][maxn];

bool canMove(int x1,int y1,int x2,int y2,double nowtime,double &t){
	if (Floor[x1][y1]+50>Ceil[x2][y2]) return false;
	if (Floor[x2][y2]+50>Ceil[x2][y2]) return false;
	if (Floor[x2][y2]+50>Ceil[x1][y1]) return false;
	if (H-10*nowtime+50>Ceil[x2][y2]) t=(H-(Ceil[x2][y2]-50))/10.0-nowtime;
		else t=0;
	return true;
}
double getTime(int x,int y,double t){
	if (H-t*10-20>=Floor[x][y]) return 1.0;
		else return 10.0;
}
int main(){
	freopen("i.txt","r",stdin);
	int cnt=1;
	for (scanf("%d",&test);test--;cnt++){
		printf("Case #%d: ",cnt);
		scanf("%d%d%d",&H,&N,&M);
		for (int i=0;i<N;i++)
			for (int j=0;j<M;j++) scanf("%d",&Ceil[i][j]);
		for (int i=0;i<N;i++)
			for (int j=0;j<M;j++) scanf("%d",&Floor[i][j]);
		for (int i=0;i<N;i++)
			for (int j=0;j<M;j++) F[i][j]=1e20;
		for (;!Qx.empty();Qx.pop(),Qy.pop());
		memset(vis,0,sizeof(vis));
		F[0][0]=0;
		vis[0][0]=true;
		Qx.push(0);
		Qy.push(0);
		for (;!Qx.empty();Qx.pop(),Qy.pop()){
			int x=Qx.front(),y=Qy.front();
			vis[x][y]=false;
			for (int d=0;d<4;d++){
				int tmpx=x+dx[d],tmpy=y+dy[d];
				double nowtime=F[x][y],t;
				if (tmpx>=N || tmpx<0 || tmpy<0 || tmpy>=M) continue;
				if (canMove(x,y,tmpx,tmpy,nowtime,t) && t==0){
					double tmptime=getTime(x,y,nowtime+t);
					if (F[tmpx][tmpy]>0){
						F[tmpx][tmpy]=0;
						if (!vis[tmpx][tmpy]){
							vis[tmpx][tmpy]=true;
							Qx.push(tmpx);
							Qy.push(tmpy);
						}
					}
				}
			}
		}
		for (;!Qx.empty();Qx.pop(),Qy.pop());
		memset(vis,0,sizeof(vis));
		for (int i=0;i<N;i++)
			for (int j=0;j<M;j++) if (F[i][j]==0){
				Qx.push(i);
				Qy.push(j);
				vis[i][j]=true;
			}
		for (;!Qx.empty();Qx.pop(),Qy.pop()){
			int x=Qx.front(),y=Qy.front();
			vis[x][y]=false;
			for (int d=0;d<4;d++){
				int tmpx=x+dx[d],tmpy=y+dy[d];
				double nowtime=F[x][y],t;
				if (tmpx>=N || tmpx<0 || tmpy<0 || tmpy>=M) continue;
				if (canMove(x,y,tmpx,tmpy,nowtime,t)){
					double tmptime=getTime(x,y,nowtime+t);
					if (F[tmpx][tmpy]>nowtime+t+tmptime){
						F[tmpx][tmpy]=nowtime+t+tmptime;
						if (!vis[tmpx][tmpy]){
							vis[tmpx][tmpy]=true;
							Qx.push(tmpx);
							Qy.push(tmpy);
						}
					}
				}
			}
		}
		printf("%.6lf\n",F[N-1][M-1]);
	}
	return 0;
}
