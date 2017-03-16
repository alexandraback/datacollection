#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <fstream>
#include <sstream>

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

double SolveTestCase() {
	int level, n, m;
	cin >> level >> n >> m;
	vector< vector<int> > floor(n, vector<int> (m, 0));
	vector< vector<int> > ceil(n, vector<int> (m, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> ceil[i][j];
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> floor[i][j];
		}

	const int inf = 1 << 28;
	vector< vector<int> > dist(n, vector<int> (m, inf));
	vector< vector<bool> > used(n, vector<bool> (m, false));
	dist[0][0] = 0;

	for (int t = 0; t <= m * n; t++) {
		int minX = -1; int minY = -1;
		int minDist = inf;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dist[i][j] < minDist && !used[i][j]) {
					minDist = dist[i][j];
					minY = i;
					minX = j;
				}
			}
		}
		if (minX == -1 || minY == -1) break;
		used[minY][minX] = true;
		for (int d = 0; d < 4; d++) {
			int newX = minX + dx[d];
			int newY = minY + dy[d];
			if (newX > -1 && newX < m && newY > -1 && newY < n) {
				int newDist = 0;
				if (floor[newY][newX] > ceil[minY][minX] - 50) continue;
				if (floor[newY][newX] > ceil[newY][newX] - 50) continue;
				if (floor[minY][minX] > ceil[newY][newX] - 50) continue;
				int wait = max(0, level - minDist - (ceil[newY][newX] - 50));
				int move = 10;
				if (level - minDist - wait < floor[minY][minX] + 20) move = 100;
				if (wait == 0 && minDist == 0) move = 0;
				dist[newY][newX] = min(dist[newY][newX], minDist + wait + move);
			}
		}
	}

	return dist[n - 1][m - 1] / 10.0;
}

template <class T> 
void PrintAnswerToTestCase(T answer, int testCase) {
	cout.precision(18);
	cout << "Case #" << testCase << ": " << answer << endl;
}

int main() {

	//freopen("input.txt", "r", stdin);
	freopen("small.in", "r", stdin);
	//freopen("large.in", "r", stdin);
	
	freopen("output.txt", "w", stdout);
	
	int numCases;
	cin >> numCases;

	for (int testCase = 1; testCase <= numCases; testCase++) {
		cerr << "Case #" << testCase << endl;
		PrintAnswerToTestCase(SolveTestCase(), testCase);
	}
	return 0;
}