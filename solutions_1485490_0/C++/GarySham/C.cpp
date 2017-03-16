#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define INF (1<<29)
#define eps (1e-8)
#define feq(x,y) (fabs(x-y)<eps)
#define flt(x,y) (((y)-(x))>eps)
#define fgt(x,y) (((x)-(y))>eps)
#define ll long long

struct node{
	int ty;
	ll num;

	void input(){
		scanf("%lld%d",&num,&ty);
	}
} a[105],b[105];

struct com{
	ll l,r;

	com(){}
	com(ll l,ll r):l(l),r(r){}
	bool operator<(const com &d)const{
		if (l==d.l) return r<d.r; else return l<d.l;
	}
};

int T,n,m,nt;
map<com,ll> dp[105][105];
map<com,int> visit[105][105];

void f(int x,int y,ll nx,ll ny){
	if (visit[x][y][com(nx,ny)]==nt) return;
	visit[x][y][com(nx,ny)]=nt;
	if (x>=n || y>=m){
		dp[x][y][com(nx,ny)]=0ll;
		return;
	}
	//printf("%d %d %lld %lld!!\n",x,y,nx,ny);

	//Same type
	if (a[x].ty==b[y].ty){
		if (nx>ny){
			f(x,y+1,nx-ny,b[y+1].num);
			dp[x][y][com(nx,ny)]=dp[x][y+1][com(nx-ny,b[y+1].num)]+ny;
			//printf("1: %d %d %lld %lld %lld\n",x,y,nx,ny,dp[x][y][com(nx,ny)]);
		}
		else if (ny>nx){
			f(x+1,y,a[x+1].num,ny-nx);
			dp[x][y][com(nx,ny)]=dp[x+1][y][com(a[x+1].num,ny-nx)]+nx;
			//printf("2: %d %d %lld %lld %lld\n",x,y,nx,ny,dp[x][y][com(nx,ny)]);
		}
		else{
			f(x+1,y+1,a[x+1].num,b[y+1].num);
			dp[x][y][com(nx,ny)]=dp[x+1][y+1][com(a[x+1].num,b[y+1].num)]+nx;
			//printf("3: %d %d %lld %lld %lld\n",x,y,nx,ny,dp[x][y][com(nx,ny)]);
		}
	}
	//Diff type
	else{
		f(x+1,y,a[x+1].num,ny); f(x,y+1,nx,b[y+1].num);
		dp[x][y][com(nx,ny)]=max(dp[x+1][y][com(a[x+1].num,ny)],dp[x][y+1][com(nx,b[y+1].num)]);
		//printf("4: %d %d %lld %lld %lld\n",x,y,nx,ny,dp[x][y][com(nx,ny)]);
	}
}

int main(){
	scanf("%d",&T);
	for (int t=1;t<=T;++t){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		nt=t;

		scanf("%d%d",&n,&m);
		for (int i=0;i<n;++i) a[i].input();
		for (int i=0;i<m;++i) b[i].input();
		f(0,0,a[0].num,b[0].num);
		printf("Case #%d: %lld\n",t,dp[0][0][com(a[0].num,b[0].num)]);
	}
	return 0;
}
