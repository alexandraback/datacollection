#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int F[200][200], C[200][200];

int in[200][200];
double dist[200][200];
int inf[200][200];
int dir[4][2]={ {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int link(int x, int y, int nx, int ny){
	if(C[nx][ny]-F[nx][ny]<50) return 0;
	if(C[nx][ny]-F[x][y]<50) return 0;
	if(C[x][y]-F[nx][ny]<50) return 0;
	return 1;
}
double spfa(int N, int M, int H){
	queue<int> Q;
	memset(in, 0, sizeof(in));
	memset(inf, 0, sizeof(inf));
	in[1][1]=1;
	dist[1][1]=0; inf[1][1]=1;
	Q.push(1); Q.push(1);

	while(!Q.empty()){
		int x=Q.front(); Q.pop();
		int y=Q.front(); Q.pop();
		in[x][y]=0;
		for(int i=0; i<4; i++){
			int nx=x+dir[i][0], ny=y+dir[i][1];
			if(nx<1 || nx>N || ny<1 || ny>M) continue;
			if(!link(x, y, nx, ny)) continue;
			if(C[nx][ny]-H<50) continue;
			double t=0;
			if(!inf[nx][ny] || dist[nx][ny]>dist[x][y]+t){
				dist[nx][ny]=dist[x][y]+t;
				inf[nx][ny]=1;
				if(!in[nx][ny]){
					in[nx][ny]=1;
					Q.push(nx); Q.push(ny);
				}
			}
		}
	}
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++) if(inf[i][j]){
			Q.push(i); Q.push(j);
			in[i][j]=1;
		}
	while(!Q.empty()){
		int x=Q.front(); Q.pop();
		int y=Q.front(); Q.pop();
		in[x][y]=0;
		for(int i=0; i<4; i++){
			int nx=x+dir[i][0], ny=y+dir[i][1];
			if(nx<1 || nx>N || ny<1 || ny>M) continue;
			if(!link(x, y, nx, ny)) continue;
			double ch=H-10*dist[x][y];
			double t=0;
			double nh;
			if(C[nx][ny]-50>=ch) {
				t=0; nh=ch;
			}else {
				t=(ch-C[nx][ny]+50)*1.0/10;
				nh=C[nx][ny]-50;
			}
			if(nh-F[x][y]>=20) t+=1;
			else t+=10;
			if(!inf[nx][ny] || dist[nx][ny]>dist[x][y]+t){
				dist[nx][ny]=dist[x][y]+t;
				inf[nx][ny]=1;
				if(!in[nx][ny]){
					in[nx][ny]=1;
					Q.push(nx); Q.push(ny);
				}
			}
		}
	}
	return dist[N][M];
}
int main(){
	freopen("B-large(1).in", "r", stdin);
	freopen("boutlarge.txt", "w", stdout);
	int T; cin>>T;
	for(int cas=1; cas<=T; cas++){
		int H, N, M; cin>>H>>N>>M;
		int i, j;
		for(i=1; i<=N; i++)
			for(int j=1; j<=M; j++) cin>>C[i][j];
		for(i=1; i<=N; i++)
			for(int j=1; j<=M; j++) cin>>F[i][j];
		double result=spfa(N, M, H);
		printf("Case #%d: %.9lf\n", cas, result);
	}
	return 0;
}