#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>


using namespace std;

void once() {
	int n, m;
	double h;
	int sh[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	cin >> h >>  n >> m;
	vector<vector<double> > ceil, floor;
	vector<vector<bool> >  used;
	vector<vector<double> > answ;
	map<int, map<int, int> > qc;
	ceil.resize(n); floor.resize(n); used.resize(n); answ.resize(n);
	for(int i = 0; i < n; i++) {
		ceil[i].resize(m);
		floor[i].resize(m);
		used[i].resize(m);
		answ[i].resize(m, 1e15);
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> ceil[i][j];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> floor[i][j];

	deque<int> xq, yq;
	deque<double> tq;
	xq.push_back(0); yq.push_back(0); qc[0][0]++;
	tq.push_back(0.0);
	
	while(xq.size()) {
		int x = xq.front();
		int y = yq.front();
		double t = tq.front();
		xq.pop_front(); yq.pop_front(); tq.pop_front();
		if(t >= answ[x][y])
			continue;		
	        answ[x][y] = t;
		used[x][y] = true;
		for(int i = 0; i < 4; i++) {
			int nx = x + sh[i][0];
			int ny = y + sh[i][1];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
	//			cerr << x << " " << y << " -> "  << nx << " " << ny << "(" << n << " " << m << ")" << endl;
				if((ceil[nx][ny] - floor[nx][ny]) < 50 || (ceil[nx][ny] - floor[x][y]) < 50) { 
	//				cerr << "FUCK" << endl;
					continue;
				}
				if(ceil[x][y] - floor[nx][ny] < 50) {
	//				cerr << "SHIT" << endl;
					continue;
				}
				double nt = max(t, (h - ceil[nx][ny] + 50.0) / 10.0);
				if(nt != 0.0){
				if((h - (nt * 10.0) - 20.0) >= floor[x][y])
					nt += 1.0;
				else
					nt += 10.0;
				
				if(nt > answ[nx][ny])
					continue;
				}
				if(!used[nx][ny]) {
					xq.push_back(nx);
					yq.push_back(ny);
					tq.push_back(nt);
				} else {
					xq.push_front(nx);
					yq.push_front(ny);
					tq.push_front(nt);
				}
				
			
			} 
		}
	}
/*	cout << endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			cout << answ[i][j] << " ";
		cout << endl;
	}*/
	printf("%.6lf", answ[n - 1][m - 1]);
}

int main() {
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		once();
		cout << endl;
	}
	return 0;
}