#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int	dx[]={0,1,0,-1},
			dy[]={1,0,-1,0};
int F[128][128],C[128][128],T[128][128],H,n,m;
double solve(){
	scanf("%d%d%d",&H,&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&C[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			scanf("%d",&F[i][j]);
			T[i][j]=999999999;
		}
	queue<pair<int,int> > p,q;
	int x,y,t,h,a,b,c,d,w;
	p.push(make_pair(1,1));
	for(;p.size();p.pop()){
		x=p.front().first;
		y=p.front().second;
		T[x][y]=0;
		q.push(make_pair((x<<7|y),0));
		for(int k=0;k<4;++k){
			a=x+dx[k];
			b=y+dy[k];
			if(a==0 || b==0 || a>n || b>m || !T[a][b])continue;
			if(min(C[x][y],C[a][b])<max(max(F[x][y],F[a][b]),H)+50)continue;
			p.push(make_pair(a,b));
		}
	}
	for(;q.size();q.pop()){
		x=q.front().first>>7;
		y=q.front().first&127;
		t=q.front().second;
		h=H-t;
		for(int k=0;k<4;++k){
			a=x+dx[k];
			b=y+dy[k];
			if(a==0 || b==0 || a>n || b>m )continue;
			if(min(C[x][y],C[a][b])<max(F[x][y],F[a][b])+50)continue;
			c=min(C[x][y],C[a][b])-50;
			w=max(0,h-c);
			c=h-w;
			d=w+t+((c>=F[x][y]+20)?10:100);
			if(d<T[a][b]){
				T[a][b]=d;
				q.push(make_pair((a<<7|b),d));
			}
		}
	}	
	return T[n][m]*0.1;
}
int main(){
	int T,ti;
	for(scanf("%d",&T),ti=1;ti<=T;++ti){
		printf("Case #%d: %.1lf\n",ti,solve());
	}
}