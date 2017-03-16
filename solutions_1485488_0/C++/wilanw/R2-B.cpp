#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int ceilT[101][101];
int floorT[101][101];
int visitTime[101][101][2];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

class Node {
public:
	int waterHeight;
	int x;
	int y;
	int t;
	int tick;
	Node() { }
	Node(int w, int _x, int _y, int _t, int _tick) : waterHeight(w), x(_x), y(_y), t(_t), tick(_tick) { }
};

bool operator<(const Node& lhs, const Node& rhs) {
	if (lhs.t != rhs.t) return lhs.t > rhs.t;
	if (lhs.tick != rhs.tick) return lhs.tick < rhs.tick;
	if (lhs.waterHeight != rhs.waterHeight) return lhs.waterHeight < rhs.waterHeight;
	if (lhs.x != rhs.x) return lhs.x < rhs.x;
	return lhs.y < rhs.y;
}

int main() {
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int H, N, M; cin >> H >> N >> M;
		// ceiling
		memset(ceilT,0,sizeof(ceilT));
		memset(floorT,0,sizeof(floorT));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int val; cin >> val;
				ceilT[i][j] = val;
			}
		}
		// floor
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int val; cin >> val;
				floorT[i][j] = val;
			}
		}
		for (int i = 0; i < 101; i++) for (int j = 0; j < 101; j++) for (int k = 0; k < 2; k++) visitTime[i][j][k] = 9000000;
		priority_queue<Node, vector<Node> > pq;
		pq.push(Node(H, 0, 0, 0, 0));
		double best = 0.0;
		bool ok = false;
		while (!pq.empty()) {
			Node n = pq.top(); pq.pop();
			//cout << "X: " << n.x << " Y: " << n.y << " Time: " << n.t << " Tick: " << n.tick << " Water Level: " << n.waterHeight << "\n";
			if (n.x == N-1 && n.y == M-1) {
				// finished
				best = n.t;
				ok = true;
				break;
			}
			visitTime[n.x][n.y][n.tick] = n.t;
			// compute possibilities
			for (int dir = 0; dir < 4; dir++) {
				int mx = n.x + dx[dir];
				int my = n.y + dy[dir];
				// check if in grid
				if (mx < 0 || my < 0 || mx >= N || my >= M) continue;	// outside
				int nextCeiling = ceilT[mx][my];
				int nextFloor = floorT[mx][my];
				if (nextCeiling - nextFloor < 50) continue;	// impossible to 50cm height
				int waterLevel = n.waterHeight;
				int curFloor = floorT[n.x][n.y];
				int curCeiling = ceilT[n.x][n.y];
				if (curCeiling - nextFloor < 50) continue;
				if (nextCeiling - curFloor < 50) continue;	// impossible to fit inside from current
				// ok or use water/time
				if (nextCeiling - waterLevel >= 50) {
					// can move without waiting
					int nT = n.t;
					//cout << "X: " << n.x << " Y: " << n.y << " Time: " << n.t << " Tick: " << n.tick << " Water Level: " << n.waterHeight << "\n";
					//cout << "Move without waiting...\n";
					if (n.tick != 0) {
						if (waterLevel - curFloor >= 20) {
							nT += 10;
							//waterLevel = max(n.waterHeight-10,0);
							waterLevel = max(n.waterHeight-10,0);
						} else {
							nT += 100;
							//waterLevel = max(n.waterHeight-100,0);
							waterLevel = max(n.waterHeight-100,0);
						}
					}
					//cout << "Added to queue: water h: " << n.waterHeight << " x: " << mx << " y: " << my << " time: " << nT << " tick: " << n.tick << "\n";
					if (visitTime[mx][my][n.tick] > nT) pq.push(Node(waterLevel, mx, my, nT, n.tick));
				} else {
					// need to wait
					// how long?
					//cout << "X: " << n.x << " Y: " << n.y << " Time: " << n.t << " Tick: " << n.tick << " Water Level: " << n.waterHeight << "\n";
					//cout << "Move WITH waiting...\n";
					int reqLevel = nextCeiling - 50;
					if (reqLevel < 0) {
						continue;	// impossible to fill
					}
					int waitTime = (waterLevel - reqLevel);
					// now move
					waterLevel = reqLevel;
					//cout << "Wait time was: " << waitTime << "\n";
					int nT = n.t + waitTime;
					if (waterLevel - curFloor >= 20) {
						nT += 10;
						waterLevel = max(waterLevel-10,0);
					} else {
						nT += 100;
						waterLevel = max(waterLevel-100,0);
					}
					//cout << "Added to queue: water h: " << waterLevel << " x: " << mx << " y: " << my << " time: " << nT << " tick: " << 1 << "\n";
					if (visitTime[mx][my][1] > nT) pq.push(Node(waterLevel, mx, my, nT, 1));
				}
			}
		}
		best /= 10.0;
		printf("Case #%d: %.6f\n",t+1,best);
		//cout << "Case #" << (t+1) << ": " << best << "\n";
	}
	return 0;
}