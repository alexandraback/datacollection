#include<stdio.h>
#include<queue>
using namespace std;

int a[128][128],b[128][128];
int d[128][128];
int n,m,H;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int valid(int x,int y) {
	return x>=0 && y>=0 && x<n && y<m;
}

int main() {
	int N,cs=0;
	for(scanf("%d",&N);N--;) {
		scanf("%d %d %d",&H,&n,&m);
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&b[i][j]);
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) d[i][j]=1000000000;
		d[0][0]=0;
		pq.push(make_pair(0,0));
		while(!pq.empty()) {
			int t=pq.top().first,x=pq.top().second/m,y=pq.top().second%m;
			pq.pop();
			if (t!=d[x][y]) continue;
			int h=H-t,nx,ny;
			for(int i=0;i<4;i++) if(valid(nx=x+dir[i][0],ny=y+dir[i][1])) {
				if (a[nx][ny]-b[nx][ny]<50 || a[x][y]-b[nx][ny]<50 || a[nx][ny]-b[x][y]<50) continue;
				int w=b[nx][ny];
				if (w<h) w=h;
				int tt=0;
				if (a[nx][ny]-w<50) tt=w+50-a[nx][ny];
				w-=tt;
				int dt=0;
				if (w-b[x][y]>=20) dt=10; else dt=100;
				if (!t && !tt) dt=0;
				if (t+tt+dt<d[nx][ny]) d[nx][ny]=t+tt+dt,pq.push(make_pair(d[nx][ny],nx*m+ny));
			}
		}
		printf("Case #%d: %d.%d\n",++cs,d[n-1][m-1]/10,d[n-1][m-1]%10);
	}
	return 0;
}
