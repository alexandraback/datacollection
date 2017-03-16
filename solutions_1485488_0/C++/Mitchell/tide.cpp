#include <bitset>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <deque>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <cstring>
#include <map>
using namespace std;
FILE * fout = fopen("B.out", "w");
FILE * fin = fopen("B.in", "r");
double mintime[100][100];
int C[100][100];
int F[100][100];
bool visited[100][100];
int H;
double calculate_time(double starttime, int ceil_begin, int ceil_end, int floor_begin, int floor_end){
	if(starttime == 0.0 && H <= ceil_end - 50 && floor_begin <= ceil_end - 50 && floor_end <= ceil_begin - 50 && floor_end <= ceil_end - 50){
		return 0.0;
	}
	if(floor_begin > ceil_end - 50 || floor_end > ceil_begin - 50 || floor_end > ceil_end - 50){
		return 100000000000.0;
	}
	double go_time = max(starttime, ((double)H - ((double)ceil_end - 50.0)) / 10.0 );
	if(H - go_time * 10.0 - floor_begin >= 20){
		return go_time + 1.0;
	} else {
		return go_time + 10.0;
	}
}
int main(){
	int T;
	fscanf(fin, "%d", &T);
	for(int casenum=0;casenum<T;casenum++){
		int N, M;
		fscanf(fin, "%d %d %d", &H, &N, &M);
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				fscanf(fin, "%d", &C[i][j]);
				visited[i][j] = false;
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				fscanf(fin, "%d", &F[i][j]);
			}
		}
		priority_queue<pair<double, pair<int, int> > > time;
		time.push( make_pair(0.0, make_pair(0, 0)) );
		while(!time.empty()){
			pair<double, pair<int, int> > b1 = time.top();
			time.pop();
			double tt = -b1.first;
			int x = b1.second.first;
			int y = b1.second.second;
			if(visited[x][y]){
				continue;
			}
			visited[x][y] = true;
			mintime[x][y] = tt;
			double tt1;
			if(x > 0){
				tt1 = calculate_time(tt, C[x][y], C[x-1][y], F[x][y], F[x-1][y]);
				time.push(make_pair(-tt1, make_pair(x-1, y)));
			}
			if(x + 1 < N){
				tt1 = calculate_time(tt, C[x][y], C[x+1][y], F[x][y], F[x+1][y]);
				time.push(make_pair(-tt1, make_pair(x+1, y)));
			}
			if(y > 0){
				tt1 = calculate_time(tt, C[x][y], C[x][y-1], F[x][y], F[x][y-1]);
				time.push(make_pair(-tt1, make_pair(x, y-1)));
			}
			if(y + 1 < M){
				tt1 = calculate_time(tt, C[x][y], C[x][y+1], F[x][y], F[x][y+1]);
				time.push(make_pair(-tt1, make_pair(x, y+1)));
			}
		}
		fprintf(fout, "Case #%d: %f\n", casenum + 1, mintime[N-1][M-1]);
		
	}
}
