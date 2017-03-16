#include <iostream>
#include <cmath>
using namespace std;
#define INF 1e12
#define EPS 1e-6
#define MAX_ITERS 20*20

int N, M;
double H;
double ceilingh[20][20];
double floorh[20][20];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

double earliest_arrival[20][20];

bool invalid(int x2, int y2) {
	if (0 <= x2 && x2 < N && 0 <= y2 && y2 < M)
		return false;
	return true;
}

double water_depth(int x, int y, double t) {
	double water_height = H - 10.0 * t;
	if (water_height < floorh[x][y])
		return 0.0;
	else
		return water_height - floorh[x][y];
}

bool cangetto(int x2, int y2, int x1, int y1, double t) {
	double water_height = H - 10.0 * t;
	double base1 = max(water_height, floorh[x1][y1]);
	double base2 = max(water_height, floorh[x2][y2]);
	double minh = min(ceilingh[x1][y1], ceilingh[x2][y2]);
	double opening = minh - max(base1, base2);
	if (opening >= 50.0 - EPS)
		return true;
	return false;
}

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		cin >> H >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				cin >> ceilingh[i][j];
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				cin >> floorh[i][j];
		}
		
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				earliest_arrival[i][j] = INF;
		
		//see where we can get BEFORE tide starts going down
		earliest_arrival[0][0] = 0;
		
		for (int iter = 0; iter < MAX_ITERS; iter++) {
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++) {
					// try all 4 directions
					int x1 = i, y1 = j;
					for (int d = 0; d < 4; d++) {
						int x2 = x1 + dx[d], y2 = y1 + dy[d];
						if (invalid(x2, y2))
							continue;
						if (cangetto(x2, y2, x1, y1, 0))
							earliest_arrival[x2][y2] = min(earliest_arrival[x2][y2], earliest_arrival[x1][y1]);
					}
				}
		}
		
		//now the tide has started falling...
		for (int iter = 0; iter < MAX_ITERS; iter++) {
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++) {
					// try all 4 directions
					int x1 = i, y1 = j;
					for (int d = 0; d < 4; d++) {
						int x2 = x1 + dx[d], y2 = y1 + dy[d];
						if (invalid(x2, y2))
							continue;
						// find the earliest time we can get from (x1,y2) --> (x2,y2)
						// binary search over t's, don't forget to add walk/vs kayak time (1 or 10)
						// first possible leaving time is earliest_arrival at (x1,y1)
						// last possible leaving time is ... INF works?
						// find the earliest time... if water at (x1,y2) > 20 + EPS, time is + 1, else + 10
						double a = earliest_arrival[x1][y1];
						double b = INF;
						while (fabs(b-a) > EPS) {
							double m = .5 * (a+b);
							if (cangetto(x2, y2, x1, y1, m))
								b = m;
							else
								a = m;
						}
						double t = b;
						if (water_depth(x1, y1, t+EPS) >= 20.0 - 1e-4)
							earliest_arrival[x2][y2] = min(earliest_arrival[x2][y2], 1.0 + t);
						else
							earliest_arrival[x2][y2] = min(earliest_arrival[x2][y2], 10.0 + t);
					}
				}
		}
		
		double res = earliest_arrival[N-1][M-1]; //trying to get to [N-1][M-1]...
		cout << "Case #" << icase << ": " << res << endl;
	}
	return 0;
}
