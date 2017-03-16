#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

struct coor{
	int x, y, h;
} tmp;
queue<coor> q;

int floor[105][105], ceil[105][105], t[105][105], dx[]={-1,1,0,0}, dy[]={0,0,-1,1};

int cango(int x, int y, int x1, int y1, int h){
	if(ceil[x1][y1]-floor[x][y]<50) return 0;
	if(ceil[x][y]-floor[x1][y1]<50) return 0;
	if(ceil[x1][y1]-floor[x1][y1]<50) return 0;
	if(ceil[x1][y1]-h<50) return -1;
	return 1;
}

coor pack(int x, int y, int h){
	coor a;
	a.x=x; a.y=y; a.h=h;
	return a;
}

int main(){
	int T, time=0, i, j, n, m, h, x, y, need;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &h, &n, &m);
		memset(floor, 0, sizeof(floor));
		memset(ceil, 0, sizeof(ceil));
		for(i=1; i<=n; i++)
			for(j=1; j<=m; j++)
				scanf("%d", &ceil[i][j]);
		for(i=1; i<=n; i++)
			for(j=1; j<=m; j++){
				scanf("%d", &floor[i][j]);
				t[i][j]=1000000000;
			}

		q.push(pack(1, 1, h));
		t[1][1]=0;
		while(!q.empty()){
			tmp=q.front(); q.pop();
			x=tmp.x; y=tmp.y; h=tmp.h;
			//printf("now x = %d, y = %d\n", x, y);
			for(i=0; i<4; i++){
				if(t[x+dx[i]][y+dy[i]]!=0 && cango(x, y, x+dx[i], y+dy[i], h)==1){
					q.push(pack(x+dx[i], y+dy[i], h));
					t[x+dx[i]][y+dy[i]]=0;
				}
			}
		}

		for(i=1; i<=n; i++)
			for(j=1; j<=m; j++)
				if(t[i][j]==0){
					q.push(pack(i, j, h));
					//printf("now insert x, y = (%d, %d)\n", i, j);
				}

		while(!q.empty()){
			tmp=q.front(); q.pop();
			x=tmp.x; y=tmp.y; h=tmp.h;
			if(h<0) h=0;
			//printf("now x = %d, y = %d\n", x, y);
			if(t[x][y]>=t[n][m]) continue;
			for(i=0; i<4; i++){
				if(!cango(x, y, x+dx[i], y+dy[i], h)) continue;
				if(cango(x, y, x+dx[i], y+dy[i], h)==1)
					need=0;
				else
					need=h-ceil[x+dx[i]][y+dy[i]]+50;
				//printf("need = %d\n", need);
				if(h-need-floor[x][y]>=20) need+=10;
				else need+=100;
				//printf("need = %d\n" ,need);
				if(t[x+dx[i]][y+dy[i]]>t[x][y]+need){
					q.push(pack(x+dx[i], y+dy[i], h-need));
					t[x+dx[i]][y+dy[i]]=t[x][y]+need;
				}
			}
		}

		printf("Case #%d: %f\n", ++time, double(t[n][m])/10);
	}
    return 0;
}
