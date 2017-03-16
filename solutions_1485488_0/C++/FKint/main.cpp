#include <cstdio>
#include <queue>
using namespace std;
#define MAX_N 100
#define MAX_M 100
#define MAX_VAL 999999999
//const int directions[8 ][2]={
//	{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,-1},{-1,1},{-1,0}
//};
const int directions[4][2]={
	{1,0},{-1,0},{0,1},{0,-1}
};
int h,n,m;
int ceiling_heights[MAX_N][MAX_M];
int floor_heights[MAX_N][MAX_M];
double reachable[MAX_N][MAX_M];
bool accessible[MAX_N][MAX_M];
struct data{
	int row,col;
	double time;
	bool started;
	data(int row, int col, double time, bool started){
		this->row = row;
		this->col = col;
		this->time = time;
		this->started = started;
	}
	bool operator<(const data &d) const{
		return this->time > d.time;
	}
};
priority_queue<data> pq;
void add_to_queue(int row, int col, double time, bool started){
	pq.push(data(row,col,time,started));
}
void action(int row, int col, double time, bool started){
	if(time >= reachable[row][col])
		return;
	reachable[row][col]=time;
	if(row==n-1 && col == m-1){
		return;
	}
	double water = started?((double)h-time*10.0):(double)h;
	//for(int i = 0; i < 8; ++i){
	for(int i = 0; i < 4; ++i){
		if(!(row+directions[i][0]>=0 && row+directions[i][0]<n)){
			continue;
		}
		if(!(col+directions[i][1]>=0 && col+directions[i][1]<m)){
			continue;
		}
		if(!accessible[row+directions[i][0]][col+directions[i][1]])
			continue;
		if(ceiling_heights[row+directions[i][0]][col+directions[i][1]]-floor_heights[row][col]<50)
			continue;
		if(ceiling_heights[row][col]-floor_heights[row+directions[i][0]][col+directions[i][1]]<50)
			continue;
		//can start now
		if((double)ceiling_heights[row+directions[i][0]][col+directions[i][1]]-water>=50.0){
			if(!started){
				add_to_queue(row+directions[i][0], col+directions[i][1],0.0,false);
			}else{
				double tmp_time = (water-floor_heights[row][col])>=20?1:10;
				add_to_queue(row+directions[i][0], col+directions[i][1],time+tmp_time, true);
			}
		}
		//has to wait
		else{
			double time_to_wait = (water-(double)ceiling_heights[row+directions[i][0]][col+directions[i][1]]+50)/10.0;
			double tmp_time = (ceiling_heights[row+directions[i][0]][col+directions[i][1]]-70>=floor_heights[row][col])?1:10;
			add_to_queue(row+directions[i][0], col+directions[i][1], time+time_to_wait+tmp_time,true);
		}

		//if(max(water, (double)floor_heights[row+directions[i][0]][col+directions[i][1]])>(double)ceiling_heights[row+directions[i][0]][col+directions[i][1]]-50){
		
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		scanf("%d%d%d", &h, &n, &m);
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < m; ++k){
				scanf("%d", &ceiling_heights[j][k]);
				reachable[j][k]=MAX_VAL;
			}
		}
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < m; ++k){
				scanf("%d", &floor_heights[j][k]);
				accessible[j][k]=(ceiling_heights[j][k]-floor_heights[j][k])>=50;
			}
		}
		//reachable[0][0]=0.0;
		while(!pq.empty()){
			pq.pop();
		}
		pq.push(data(0,0,0.0,false));
		while(!pq.empty()){
			data d = pq.top();
			pq.pop();
			if(d.time >= reachable[n-1][m-1])
				break;
			action(d.row, d.col, d.time, d.started);
		}
		printf("Case #%d: %lf\n", i+1, reachable[n-1][m-1]);
	}
}
