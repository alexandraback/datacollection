#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=100;
const int INF=0x3f3f3f3f;
const int dx[4]={0,-1,0,1};
const int dy[4]={-1,0,1,0};
const int LIMIT=50;
const int FAST=20;
int H,row,col;
struct Square {
	int ceiling,floor;
} map[MAXN+10][MAXN+10];
int d[MAXN+10][MAXN+10];
bool inQueue[MAXN+10][MAXN+10];
struct Position {
	Position(const int &xx=0,const int &yy=0)
		:x(xx),y(yy) {}
	int x,y;
};
vector<Position> starts;
void ReadIn()
{
	scanf("%d%d%d",&H,&row,&col);
	for (int i=1;i<=row;i++)
		for (int j=1;j<=col;j++)
			scanf("%d",&map[i][j].ceiling);
	for (int i=1;i<=row;i++)
		for (int j=1;j<=col;j++)
			scanf("%d",&map[i][j].floor);
}
bool inRange(const int &x,const int &y)
{
	return 1<=x && x<=row && 1<=y && y<=col;
}
void BFS()
{
	memset(d,0x3f,sizeof(d));
	memset(inQueue,false,sizeof(inQueue));
	d[1][1]=0;
	inQueue[1][1]=true;
	starts.clear();
	starts.push_back(Position(1,1));
	for (int i=0;i<starts.size();i++) {
		int ox=starts[i].x,oy=starts[i].y;
		for (int f=0;f<4;f++) {
			int x=ox+dx[f],y=oy+dy[f];
			if (inRange(x,y) && !inQueue[x][y] && 
					map[x][y].ceiling-max(map[x][y].floor,H)>=LIMIT && 
					map[x][y].ceiling-max(map[ox][oy].floor,H)>=LIMIT &&
					map[ox][oy].ceiling-max(map[x][y].floor,H)>=LIMIT)
			{
				d[x][y]=0;
				inQueue[x][y]=true;
				starts.push_back(Position(x,y));
			}
		}
	}
}
void SPFA()
{
	queue<Position> q;
	for (int i=0;i<starts.size();i++) {
		q.push(starts[i]);
	}
		for (int j=1;j<=col;j++)
	while (!q.empty()) {
		int ox=q.front().x,oy=q.front().y;
		q.pop();
		inQueue[ox][oy]=false;
		for (int f=0;f<4;f++) {
			int x=ox+dx[f],y=oy+dy[f];
			int t=d[ox][oy];
			if (!inRange(x,y) || 
					map[x][y].ceiling-map[x][y].floor<LIMIT || 
					map[x][y].ceiling-map[ox][oy].floor<LIMIT ||
					map[ox][oy].ceiling-map[x][y].floor<LIMIT) 
				continue;
			int wait=max(0,(H-t)-(map[x][y].ceiling-LIMIT));
			int leavingHeight=max(map[ox][oy].floor,H-t-wait);
			int moveTime=leavingHeight-map[ox][oy].floor>=FAST?10:100;
			if (d[x][y]>d[ox][oy]+wait+moveTime) {
				d[x][y]=d[ox][oy]+wait+moveTime;
				if (!inQueue[x][y]) {
					inQueue[x][y]=true;
					q.push(Position(x,y));
				}
			}

		}
	}
}
int main()
{
	int cases;
	scanf("%d",&cases);
	for (int c=1;c<=cases;c++) {
		ReadIn();
		BFS();
		SPFA();
		printf("Case #%d: %d.%d\n",c,d[row][col]/10,d[row][col]%10);
	}
	return 0;
}
