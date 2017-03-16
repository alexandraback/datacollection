#include <stdio.h>
#include <map>
#include <queue>
#include <string>
using namespace std;

int H, N, M;
int tak[101][101];
int golv[101][101];
int g[101][101];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int canBeHereAt(int fromx, int fromy, int tox, int toy, int curTime, bool waitAllowed){
	if(tox<0 || tox>=M || toy<0 || toy>=N)return -1;
	if(tak[toy][tox] - golv[fromy][fromx] < 50)return -1;
	if(tak[toy][tox] - golv[toy][tox] < 50)return -1;
	if(tak[fromy][fromx] - golv[toy][tox] < 50)return -1;
	int startMoveTime;
	int curWaterLevel = H - curTime;
	if(tak[toy][tox] - curWaterLevel < 50) {
		if(!waitAllowed)return -1;
		int saknas = 50 - (tak[toy][tox] - curWaterLevel);
		startMoveTime = curTime+saknas;
	} else {
		startMoveTime = curTime;
	}
	int startMoveWaterLevel = H - startMoveTime;
	if(startMoveWaterLevel - golv[fromy][fromx] >= 20)return startMoveTime+10;
	return startMoveTime+100;
}

void run(int fall){
	scanf("%d %d %d", &H, &N, &M);
	for(int y=0;y<N;y++){
		for(int x=0;x<M;x++){
			scanf("%d", &tak[y][x]);
			g[y][x] = -1;
		}
	}
	for(int y=0;y<N;y++){
		for(int x=0;x<M;x++){
			scanf("%d", &golv[y][x]);
		}
	}
	g[0][0] = 0;


	queue<pair<int, int> > q;
	q.push(make_pair(0,0));
	while(!q.empty()){
		pair<int, int> nu = q.front();
		q.pop();
		int nux = nu.first;
		int nuy = nu.second;
		for(int dir=0;dir<4;dir++){
			int tox = nux+dx[dir];
			int toy = nuy+dy[dir];
			if(tox<0 || tox>=M || toy<0 || toy>=N)continue;
			if(g[toy][tox] > -0.1)continue;
			int timeAtTo = canBeHereAt(nux, nuy, tox, toy, 0, false);
			if(timeAtTo>0){
				g[toy][tox] = 0;
				q.push(make_pair(tox, toy));
			}
		}
	}


	priority_queue<pair<int, pair<int, int> > > Q;
	for(int y=0;y<N;y++){
		for(int x=0;x<M;x++){
			if(g[y][x] > -0.1){
				g[y][x] = -1;
				Q.push(make_pair(0, make_pair(x,y)));
				//printf("gratis g[%d][%d]\n", y, x);
			}
		}
	}

	while(!Q.empty()){
		pair<int, pair<int, int> > nu = Q.top();
		Q.pop();
		
		int curTime = nu.first;
		if(curTime<0)curTime*=-1;
		int nux = nu.second.first;
		int nuy = nu.second.second;
		if(g[nuy][nux] > -0.1)continue;
		g[nuy][nux] = curTime;
		//printf("g[%d][%d] = %0.3lf\n", nuy, nux, curTime);
		if(nuy == N-1 && nux == M-1)break;
		for(int dir=0;dir<4;dir++){
			int tox = nux+dx[dir];
			int toy = nuy+dy[dir];
			if(tox<0 || tox>=M || toy<0 || toy>=N)continue;
			if(g[toy][tox] > -0.1)continue;
			int timeAtTo = canBeHereAt(nux, nuy, tox, toy, curTime, true);
			if(timeAtTo>0){
				Q.push(make_pair(-timeAtTo, make_pair(tox, toy)));
				//printf("Q.push(make_pair(%.3lf, make_pair(%d, %d)))\n", timeAtTo, tox, toy);
			}
		}
	}
	printf("Case #%d: %0.1lf\n", fall, g[N-1][M-1]/10.0);
}


int main(){
	int T;
	scanf("%d", &T);
	for(int i=0;i<T;i++){
		run(i+1);
	}	
}