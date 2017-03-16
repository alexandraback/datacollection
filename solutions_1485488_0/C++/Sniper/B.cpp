#include <cstdio>
#include <deque>
using namespace std;

double ceil[100][100];
double floor[100][100];
int H,N,M;

const double INF = 1e9;
const double eps = 1e-8;
const int dirx[] = {-1,0,1,0};
const int diry[] = {0,-1,0,1};

double dp[100][100];

bool directmove(int fromx,int fromy,int tox,int toy,double t){
	if(ceil[tox][toy] - floor[fromx][fromy] < 50)	return 0;
	if(ceil[tox][toy] - floor[tox][toy] < 50)	return 0;
	if(ceil[fromx][fromy] - floor[tox][toy] < 50)	return 0;
	double h = ((H>=10*t)?(H-10*t):0);
	if(ceil[tox][toy] - h < 50)	return 0;
	return 1;
}

double move(int fromx,int fromy,int tox,int toy,double t){
	if(ceil[tox][toy] - floor[fromx][fromy] < 50)	return -1;
	if(ceil[tox][toy] - floor[tox][toy] < 50)	return -1;
	if(ceil[fromx][fromy] - floor[tox][toy] < 50)	return -1;
	double h = ((H>=10*t)?(H-10*t):0);
	double cost = 0;
	if(ceil[tox][toy] - h < 50){
		double wait = (50 - (ceil[tox][toy] - h)) / 10;
		t += wait;
		cost += wait;
	}
	h = ((H>=10*t)?(H-10*t):0);
	if(h - floor[fromx][fromy] >= 20)	cost += 1;
	else	cost += 10;
	return cost;
}

void bfs_zero(){
	deque<pair<int,int> > Q;
	Q.push_back(make_pair<int,int>(0,0));
	while(!Q.empty()){
		const int x = Q.front().first;
		const int y = Q.front().second;
		Q.pop_front();
		for(int d=0;d<4;++d){
			const int nextx = x+dirx[d];
			const int nexty = y+diry[d];
			if(nextx>=0 && nextx<N && nexty>=0 && nexty<M && dp[nextx][nexty] > 0 && directmove(x,y,nextx,nexty,0)){
				dp[nextx][nexty] = 0;
				Q.push_back(make_pair<int,int>(nextx,nexty));
				//printf("zero : %d %d\n",nextx,nexty);
			}
		}
	}
}

void bfs(){
	deque<pair<int,int> > Q;
	for(int i=0;i<N;++i)	for(int j=0;j<M;++j){
		if(dp[i][j] == 0)	Q.push_back(make_pair<int,int>(i,j));
	}
	while(!Q.empty()){
		const int x = Q.front().first;
		const int y = Q.front().second;
		const int cost = dp[x][y];
		Q.pop_front();
		for(int d=0;d<4;++d){
			const int nextx = x+dirx[d];
			const int nexty = y+diry[d];
			if(nextx>=0 && nextx<N && nexty>=0 && nexty<M){
				double movecost = move(x,y,nextx,nexty,cost);
				if(movecost >= 0 && cost + movecost < dp[nextx][nexty]){
					dp[nextx][nexty] = cost + movecost;
					Q.push_back(make_pair<int,int>(nextx,nexty));
				}
			}
		}
	}
	/*
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			printf("%lf\t",dp[i][j]);
		}
		printf("\n");
	}*/
}

double gao(){
	for(int i=0;i<N;++i)	for(int j=0;j<M;++j)	dp[i][j] = INF;
	dp[0][0] = 0;
	bfs_zero();
	bfs();
	return dp[N-1][M-1];
}

int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t){
		scanf("%d%d%d",&H,&N,&M);
		for(int i=0;i<N;++i)	for (int j=0;j<M;++j)	scanf("%lf",&ceil[i][j]);
		for(int i=0;i<N;++i)	for (int j=0;j<M;++j)	scanf("%lf",&floor[i][j]);
		gao();
		printf("Case #%d: %.1lf\n",t,dp[N-1][M-1]);
	}
}
