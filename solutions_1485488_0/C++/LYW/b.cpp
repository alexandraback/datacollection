#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
struct State {
	int x, y;
	double t;
	
	State(int y_, int x_, double t_) {
		x = x_;
		y = y_;
		t = t_;
	}
	
	bool operator < (const State &rhs) const {
		return t > rhs.t;
	}
};

int H, N, M;
int C[100][100], F[100][100];
double Time[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};


double Can_move_basic(int y, int x, int wy, int wx, double t) {
	double c = C[y][x];
	double f = F[y][x];
	double wc = C[wy][wx];
	double wf = F[wy][wx];
	
	if (c - 50 < max(f, H - t * 10))
		return -1;
		
	if (wc - 50 < max(wf, H - t * 10))
		return -1;
	
	if (c - 50 < max(wf, H - t * 10))
		return -1;
		
	if (wc - 50 < max(f, H - t * 10))
		return -1;
	
		
	if (H - t * 10 >= f + 20)
		return t + 1;
	return t + 10;
}

double Can_move(int y, int x, int wy, int wx, double t) {
	double c = C[y][x];
	double f = F[y][x];
	double wc = C[wy][wx];
	double wf = F[wy][wx];
	
	double min_t = t;
	
	if (c - 50 < f || wc - 50 < wf)
		return -1;
	
	if (c - 50 < wf || wc - 50 < f)
		return -1;
	
	if (c - 50 < H - t * 10) 
		min_t = max(min_t, (H - (c - 50)) / 10.0);
	
	if (wc - 50 < H - t * 10) 
		min_t = max(min_t, (H - (wc - 50)) / 10.0);
		
	if (H - min_t * 10 >= f + 20)
		return min_t + 1;
	
	return min_t + 10;
}

int main(void) {
	int testnum;
	scanf("%d", &testnum);
	for (int testcase = 1; testcase <= testnum; testcase++) {
	
		double ans = 0;
		
		scanf("%d %d %d", &H, &N, &M);
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < M; j++)
				scanf("%d", &C[i][j]);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				scanf("%d", &F[i][j]);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				Time[i][j] = -1;
		
		priority_queue<State> Queue;
		// Before tide begins
		Queue.push(State(0, 0, 0.0));
		Time[0][0] = 0.0;
		
		while (!Queue.empty()) {
			State X = Queue.top();
			Queue.pop();
			
			for (int k = 0; k < 4; k++) {
				int wx = X.x + dx[k];
				int wy = X.y + dy[k];
				double wt = X.t;
				if (0 <= wx && 0 <= wy && wy < N && wx < M) {
					double wt = Can_move_basic(X.y, X.x, wy, wx, X.t);
					if (wt == -1)
						continue;
						
					if (Time[wy][wx] > wt || Time[wy][wx] == -1) {
						wt = 0;
						Time[wy][wx] = wt;
						Queue.push(State(wy, wx, wt));
					}
				}
			}					
		}	
		
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (Time[i][j] == 0)
					Queue.push(State(i, j, 0));
					
		while (!Queue.empty()) {
			State X = Queue.top();
			Queue.pop();
			
			for (int k = 0; k < 4; k++) {
				int wx = X.x + dx[k];
				int wy = X.y + dy[k];
				double wt = X.t;
				if (0 <= wx && 0 <= wy && wy < N && wx < M) {
					double wt = Can_move(X.y, X.x, wy, wx, X.t);
					if (wt == -1)
						continue;
						
					if (Time[wy][wx] > wt || Time[wy][wx] == -1) {
						Time[wy][wx] = wt;
						Queue.push(State(wy, wx, wt));
					}
				}
			}					
		}
		
		ans = Time[N - 1][M - 1];
		printf("Case #%d: %.1lf\n", testcase, ans);	
	}

	return 0;
}