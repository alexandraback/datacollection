#include <iostream>
using namespace std;

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <vector>
#include <map>
#include <string>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)

void openFiles() {
	freopen("test_small_3.in", "rt", stdin);
	freopen("test_small_3.out", "wt", stdout);	
}

void solve()
{
	int H, n, m; scanf("%d %d %d ", &H, &n, &m);
	vector<vector<int> > ceil(n, vector<int>(m));
	vector<vector<int> > floor(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d ", &ceil[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d ", &floor[i][j]);
		}
	}

	const int di[] = {-1, 1, 0, 0};
	const int dj[] = {0, 0, -1, 1};

	vector<vector<vector<int> > > reachable(n, vector<vector<int>>(m, vector<int>(4)));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				reachable[i][j][k] = true;

				int ii = i + di[k];
				int jj = j + dj[k];

				if (ii < 0 || jj < 0 || ii >= n || jj >= m) {
					reachable[i][j][k] = false;
					continue;
				}

				// cur floor vs adjacent ceil
				if (ceil[ii][jj] - floor[i][j] < 50) {
					reachable[i][j][k] = false;
				}

				// adj ceil vs adj floor
				if (ceil[ii][jj] - floor[ii][jj] < 50) {
					reachable[i][j][k] = false;
				}

				// cur ceil vs adj floor
				if (ceil[i][j] - floor[ii][jj] < 50) {
					reachable[i][j][k] = false;
				}

			}
		}
	}

	vector<vector<int> > visited(n, vector<int>(m, 0));
	visited[0][0] = 1;
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		pair<int, int> ij = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {

			if (!reachable[ij.first][ij.second][k]) continue;

			int ii = ij.first + di[k];
			int jj = ij.second + dj[k];

			if (ceil[ii][jj] - H < 50) continue;
			if (visited[ii][jj]) continue;

			visited[ii][jj] = 1;
			q.push(make_pair(ii, jj));

		}
	}
	
	set<pair<int, pair<int, int> >> heap;
	const int INF = 1000000000;
	vector<vector<int>> dist(n, vector<int>(m, INF));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j]) {
				heap.insert(make_pair(0, make_pair(i, j)));
				dist[i][j] = 0;
			}
		}
	}		

	while (!heap.empty()) {

		int d = heap.begin()->first;
		pair<int, int> ij = heap.begin()->second;
		heap.erase(heap.begin());

		for (int k = 0; k < 4; k++) {
			int ii = ij.first + di[k];
			int jj = ij.second + dj[k];
			
			if (!reachable[ij.first][ij.second][k]) continue;

			// where is the water now?
			int waterlevel = max(0, H - d);

			int dd = d;

			// wait for the water level to reduce before going
			if (ceil[ii][jj] - waterlevel < 50) {
				//cout << floor[ii][jj] << " " << waterlevel << " " << endl;

				int dlevel = (50 - (ceil[ii][jj] - waterlevel));
				dd += dlevel;
				waterlevel -= dlevel;
				assert(waterlevel >= 0);
			}

			// assume that water level is ok
			if ((waterlevel - floor[ij.first][ij.second]) >= 20) { dd += 10; } else { dd += 100; }

			if (dist[ii][jj] > dd) {
				heap.erase(make_pair(dist[ii][jj], make_pair(ii, jj)));
				dist[ii][jj] = dd;
				heap.insert(make_pair(dd, make_pair(ii, jj)));
			}
		}

	}

	int d = dist[n - 1][m - 1];

	// found the answer
	static int ntest = 0;
	printf("Case #%d: %.1lf\n", ++ntest, d/10.0 + 1e-7);

}

int main()
{
	openFiles();

	int n; scanf("%d ", &n);
	// make sure output directory exists MY_SOLUTION/output
	for (int i = 0; i < n; i++) {		
		solve();
	}
	
	return 0;
}