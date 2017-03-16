#include <cstdio>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>

using namespace std;

const int MAX_N = 105;

const int MAX_TIME = 200005;

int n, m, h;
int top[MAX_N][MAX_N], bottom[MAX_N][MAX_N];
bool reachable[MAX_N][MAX_N];
double dtime[MAX_N][MAX_N];

double cmp(const double &a, const double &b, double eps = 1e-16) {
	if (a + eps >= b) {
		if (b + eps >= a)
			return 0;
		return 1;
	}
	return -1;
}

struct scmp {
	bool operator () (const pair < int, int > &a, const pair < int, int > &b) {
		if (cmp(dtime[a.first][a.second], dtime[b.first][b.second]) != 0)
			return (cmp(dtime[a.first][a.second], dtime[b.first][b.second]) == -1);
		return a < b;
	}
};

double level_at(double t) {
	if (t <= 0)
		return 0;
	
	double ans = 10.0 * t;
	if (cmp(ans, (double) h) == 1)
		return h;
	else
		return ans;
}

double time_at_level(double l) {
	double low = 0, high = (double) MAX_TIME;
	for (int step = 0; step < 50; step++) {
		double mid = (low + high) / 2;

		if (cmp(level_at(mid), l) == -1)
			low = mid;
		else
			high = mid;
	}

	return low;
}

bool valid(int i, int j) {
	return (i >= 0 && j >= 0 && i < n && j < m);
}

void do_bfs() {
	queue < pair < int, int > > q;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		reachable[i][j] = false;
	
	q.push(make_pair(0, 0));
	reachable[0][0] = true;

	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		for (int di = -1; di <= 1; di++) for (int dj = -1; dj <= 1; dj++) {
			if ((di == 0 && dj == 0) || (di != 0 && dj != 0))
				continue;

			int ii = i + di;
			int jj = j + dj;
			if (valid(ii, jj) && !reachable[ii][jj]) {
				int mtop = min(top[i][j], top[ii][jj]);
				
				int mbottom = max(bottom[i][j], bottom[ii][jj]);
				mbottom = max(mbottom, h);

				if (mtop - mbottom >= 50) {
					reachable[ii][jj] = true;
					q.push(make_pair(ii, jj));
				}
			}
		}
	}

	return;

	printf("reachable: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d ", reachable[i][j]);
		printf("\n");
	}
}

bool can_reach(double t) {
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		dtime[i][j] = 2.0 * (double) MAX_TIME;
	dtime[n - 1][m - 1] = t;

	set < pair < int, int >, scmp > vert;
	vert.insert(make_pair(n - 1, m - 1));

	while (!vert.empty()) {
		set < pair < int, int >, scmp >::iterator it = vert.begin();
		int i = it->first;
		int j = it->second;
		vert.erase(it);

	//	printf("%d %d dtime %lf\n", i, j, dtime[i][j]);

		if (reachable[i][j])
			return true;

		for (int di = -1; di <= 1; di++) for (int dj = -1; dj <= 1; dj++) {
			if ((di == 0 && dj == 0) || (di != 0 && dj != 0))
				continue;

			int ii = i + di;
			int jj = j + dj;
			if (valid(ii, jj)) {
				double travel_time = 0;
				double time_up = time_at_level((double) (bottom[ii][jj] + 20)) - dtime[i][j];

				if (cmp(time_up, 1) == -1)
					time_up = 1;

				if (cmp(time_up, 10.0) != 1)
					travel_time = time_up;
				else
					travel_time = 10.0;

				double level_then = level_at(dtime[i][j] + travel_time);

				double mtop = (double) min(top[i][j], top[ii][jj]);
				
				double mbottom = (double) max(bottom[i][j], bottom[ii][jj]);
				mbottom = max(mbottom, level_then);

	//			printf("ii %d jj %d travel_time %lf time_up %lf mbottom %lf mtop %lf level_then %lf\n", 
	//					ii, jj, travel_time, time_up, mbottom, mtop, level_then);

				if (cmp(mtop - mbottom, 50.0) != -1) {
					double newdist = dtime[i][j] + travel_time;
					if (cmp(newdist, dtime[ii][jj]) == -1) {
						vert.erase(make_pair(ii, jj));
						dtime[ii][jj] = newdist;
						vert.insert(make_pair(ii, jj));
					}
				}
			}
		}
	}

	return false;
}

int main() {
	int tests; scanf("%d", &tests);
	for (int t = 1; t <= tests; t++) {
		scanf("%d %d %d", &h, &n, &m);

		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			scanf("%d", &top[i][j]);

		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			scanf("%d", &bottom[i][j]);

		do_bfs();

		double low = (double) -MAX_TIME, high = MAX_TIME;
		for (int step = 0; step < 50; step++) {
			double mid = (low + high) / 2;
			//printf("mid %lf\n", mid);

			if (can_reach(mid))
				low = mid;
			else
				high = mid;
		}

		printf("Case #%d: %.6lf\n", t, max(0.0, time_at_level(h) - low));
	}

	return 0;
}
