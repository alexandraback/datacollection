#include <cmath>
#include <ctime>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#define maxn 200
using namespace std;

const double eps=1e-8;
const double inf=1e30;

double h;
int duix[maxn*maxn],duiy[maxn*maxn];
int a[maxn][maxn],b[maxn][maxn];
double f[maxn][maxn];
bool visit[maxn][maxn];

double calc(int x,int y,int xx,int yy,double now){
	//cout<<x<<" "<<y<<" "<<xx<<" "<<yy<<" "<<now<<endl;
	if(b[xx][yy]+50>a[xx][yy])return inf*2;
	if(b[x][y]+50>a[xx][yy])return inf*2;
	if(b[xx][yy]+50>a[x][y])return inf*2;
	double hi=h-now*10;
	if(hi+50>a[xx][yy]+eps)now+=(hi+50-a[xx][yy])/10;
	if(now<eps)return 0;
	hi=h-now*10;
	if(hi-b[x][y]+eps>20)return now+1;else return now+10;
}

const int dx[4]={0,0,-1,1};
const int dy[4]={-1,1,0,0};

void solve(){
	int n,m,tot,head,tail,i,j,x,y,xx,yy;
	double temp;
	scanf("%lf%d%d",&h,&n,&m);
	tot=n*m;
	if(n==1 && m==1){
		printf("%.8f\n",0);
		return;
	}
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)scanf("%d",&a[i][j]);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j){
			scanf("%d",&b[i][j]);
			f[i][j]=inf;
			visit[i][j]=false;
		}
	head=0;tail=1;
	duix[1]=1;duiy[1]=1;
	f[1][1]=0;
	visit[1][1]=true;
	while(head!=tail){
		if(++head==tot)head=0;
		x=duix[head];y=duiy[head];
		for(i=0;i<=3;++i){
			xx=x+dx[i];
			yy=y+dy[i];
			if(xx<1 || xx>n || yy<1 || yy>m)continue;
			temp=calc(x,y,xx,yy,f[x][y]);
			if(temp+eps<f[xx][yy]){
				f[xx][yy]=temp;
				if(!visit[xx][yy]){
					visit[xx][yy]=true;
					if(++tail==tot)tail=0;
					duix[tail]=xx;duiy[tail]=yy;
				}
			}
		}
		visit[x][y]=false;
	}
	printf("%.8f\n",f[n][m]);
}

int main(){
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;++i){
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}