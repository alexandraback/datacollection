//Problem A. Password Problem
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;
#define PB push_back
#define MP make_pair
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define foreach(itr, cont) for (typeof(cont.begin()) itr = cont.begin(); itr != cont.end(); itr++)
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int c[101][101], f[101][101], visited[101][101];
double time[101][101];
int dx[] = { 0, 0, 1, -1};
int dy[] = { 1,-1, 0, 0};
int main() {
	int T;

	ifstream in("B-small-attempt1.in");
	//ofstream out("B-small-attempt0.out");
	FILE *out = fopen("B-small-attempt1.out", "w");
	
	//ifstream in("C-large.in");
	//ofstream out("C-large.out");

	in >> T;
	for (int cs = 1; cs <= T; cs ++) {
		//out << "Case #" << cs << ": ";
		fprintf(out, "Case #%d: ", cs);

		int N, M, H;
		in >> H >> N >> M;

		for (int i = 0; i < N; i ++) for (int j = 0; j < M; j ++) in >> c[i][j];
		for (int i = 0; i < N; i ++) for (int j = 0; j < M; j ++) in >> f[i][j];
		memset(visited, 0, sizeof(visited));

		queue <pair<double, pair<int, int> > > q;
		q.push(MP(0.0, MP(0, 0)));
		while (!q.empty()) {
			pair<double, pair<int, int> > cur = q.front();
			q.pop();
			double t = cur.first;
			int x = cur.second.first;
			int y = cur.second.second;
			visited[x][y] = 1;
			time[x][y] = t;

			for (int k = 0; k < 4; k ++) {
				int xx = x + dx[k];
				int yy = y + dy[k];
				if (xx < 0 || xx >= N) continue;
				if (yy < 0 || yy >= M) continue;
				if (visited[xx][yy]) continue;
				if (c[xx][yy] - f[xx][yy] < 50) continue;
				if (c[xx][yy] - f[x][y] < 50) continue;
				if (c[x][y] - f[xx][yy] < 50) continue;

				double tt = (H - c[xx][yy] + 50.0) / 10.0;
				tt = max(tt, t);
				double water = H - tt * 10.0;
				if (tt != 0.0) {
					if (water - f[x][y] < 20) tt += 10.0;
					else tt += 1.0;
				}

				q.push(MP(tt, MP(xx, yy)));
			}
		}

		if (visited[N-1][M-1]) {
			//out << time[N-1][M-1] << endl;
			fprintf(out, "%.6lf\n", time[N-1][M-1]);
		}

	}
	return 0;
}
