#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ofstream fout ("1BB.out");
    ifstream fin ("1BB.in");
	int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		int H,N,M;
		fin >> H >> N >> M;
		int roof[100][100],floor[100][100];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				fin >> roof[i][j];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				fin >> floor[i][j];
		double dist[100][100];
		for(int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				dist[i][j] = 99999999;
		dist[0][0] = 0;
		priority_queue<pair<double,pair<int,int> > > todo;
		todo.push(make_pair(0,make_pair(0,0)));
		while (!todo.empty()) {
			double time = -todo.top().first;
			int r = todo.top().second.first;
			int c = todo.top().second.second;
			todo.pop();
			if (time > dist[r][c]) continue;
			int rc[4] = {-1,1,0,0};
			int cc[4] = {0,0,-1,1};
			for (int i = 0; i < 4; i++) {
				int tr = r+rc[i];
				int tc = c+cc[i];
				if (tr < 0 || tc < 0 || tr >= N || tc >= M) continue;
				if (roof[tr][tc]-floor[tr][tc] < 50 || roof[tr][tc]-floor[r][c] < 50 || roof[r][c]-floor[tr][tc] < 50) continue;
				double newtime = time;
				if (roof[tr][tc]-(H-time*10) < 50) {
					newtime = (double)(H-roof[tr][tc]+50)/10;
				}
				if (H-newtime*10-floor[r][c] < 20) newtime += 10;
				else newtime += 1;
				if (newtime < dist[tr][tc]) {
					if (time == 0 && roof[tr][tc]-(H-time*10) >= 50)
						dist[tr][tc] = 0;
					else dist[tr][tc] = newtime;
					todo.push(make_pair(-dist[tr][tc],make_pair(tr,tc)));
				}
			}
		}
		fout.precision(100);
		fout << "Case #" << t << ": " << dist[N-1][M-1] << endl;
	}
    return 0;
}