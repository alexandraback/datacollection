#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<queue>
#define INF 2147483647
using namespace std;

int n, m, h;
int fmap[102][102], cmap[102][102];
int p[102][102];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
class node{
	public:
		int x, y, d;
		bool operator<(node a)const{
			return d > a.d;
		}
};
int main(void){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		scanf("%d%d%d",&h,&n,&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&cmap[i][j]);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&fmap[i][j]);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				p[i][j] = INF;
		
		queue<node> pq;
		priority_queue<node> q;
		p[0][0] = 0;
		pq.push((node){0, 0, 0});
		for(node c;!pq.empty();pq.pop()){
			c = pq.front();
			q.push(c);
			for(int i=0;i<4;i++){
				int x = c.x+dx[i];
				int y = c.y+dy[i];
				if(x<0||y<0||x>=m||y>=n) continue;
				if(p[y][x] == 0) continue;
				if(cmap[y][x]-max(h, max(fmap[y][x], fmap[c.y][c.x])) < 50) continue;
				if(cmap[c.y][c.x]-fmap[y][x] < 50) continue;
				p[y][x] = 0;
				pq.push((node){x, y, 0});
			}
		}
		
		for(node c;!q.empty();){
			c = q.top();
			q.pop();
			//printf("c: %d %d %d\n", c.x, c.y, c.d);
			for(int i=0;i<4;i++){
				int x = c.x+dx[i];
				int y = c.y+dy[i];
				int d = c.d + max(0, h-c.d-(cmap[y][x]-50));
				if(x<0||y<0||x>=m||y>=n) continue;
				if(cmap[y][x]-max(fmap[y][x], fmap[c.y][c.x]) < 50) continue;
				if(cmap[c.y][c.x]-fmap[y][x] < 50) continue;
				if(h-d-fmap[c.y][c.x] < 20) d += 100;
				else d += 10;
				if(p[y][x] <= d) continue;
				p[y][x] = d;
				q.push((node){x, y, d});
				//printf("x: %d, y: %d, d: %d\n", x, y, d);
			}
			/*for(int i=0;i<n;i++,puts(""))
				for(int j=0;j<m;j++)
					printf("%d ", p[i][j]);
			puts("-------------------------------");
			getchar();*/
		}
		printf("Case #%d: %f\n", tt, 0.1*p[n-1][m-1]);
	}
	return 0;
}
