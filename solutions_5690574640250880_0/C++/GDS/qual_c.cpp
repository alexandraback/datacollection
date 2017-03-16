#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C, M;
vector< vector< char > > result;
vector< vector< bool > > visited;
pair<int, int> click;

void printResult() {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) cout << result[i][j];
		cout << endl;
	}
}

bool inMatrix(int i, int j) {
	return i >= 0 and j >= 0 and i < R and j < C;
}

bool isZero(int k, int l) {
	for (int i = k-1; i <= k+1; ++i) {
		for (int j = l-1; j <= l+1; ++j) {
			if (inMatrix(i, j) and result[i][j] == '*') return false;
		}
	}
	return true;
}


void resetVisits(queue< pair<int, int> > &r) {
	while (not r.empty()) {
		pair<int, int> p = r.front();
		visited[p.first][p.second] = false;
		r.pop();
	}
}

bool isSolution() {
	queue< pair<int, int> > q, r;
	q.push(click);
	while (not q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		r.push(p);
		int k = p.first, l = p.second;
		visited[k][l] = true;
		if (isZero(k, l)) {
			for (int i = k-1; i <= k+1; ++i) {
				for (int j = l-1; j <= l+1; ++j) {
					if (inMatrix(i, j) and not visited[i][j]) q.push(pair<int, int>(i, j));
				}
			}
		}
	}
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (not visited[i][j]) {
				resetVisits(r);
				return false;
			}
		}
	}
	return true;
}

bool findZero(int &x, int &y) {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (isZero(i, j)) {
				x = i;
				y = j;
				return true;
			}
		}
	}
	return false;
}

bool analyze() {
	int x, y;
	if (not findZero(x, y)) return false;
	click = pair<int, int>(x, y);
	result[x][y] = 'c';
	bool res = isSolution();
	if (not res) result[x][y] = '.';
	return res;
}

bool start(int k, int l, int numMines) {
	if (numMines == M) return analyze();
	else {
		int i = k;
		for (int j = l; j < C; ++j) { //first row
			visited[i][j] = true;
			result[i][j] = '*';
			if (start(i, j+1, numMines + 1)) return true;
			visited[i][j] = false;
			result[i][j] = '.';
		}
		for (i = k+1; i < R; ++i) { //rest of rows
			for (int j = 0;  j < C; ++j) {
				visited[i][j] = true;
				result[i][j] = '*';
				if (start(i, j+1, numMines + 1)) return true;
				visited[i][j] = false;
				result[i][j] = '.';
			}
		}
	}
	return false;
}

int main() {
	int T;
	cin >> T;
	for (int k = 1; k <= T; ++k) {
		cin >> R >> C >> M;
		result = vector< vector< char > >(R, vector< char > (C, '.'));
		visited = vector< vector< bool > >(R, vector< bool > (C, false));
		bool possible = false;
		if (M == R*C - 1) {
			for (int i = 0; i < R; ++i) {
				for (int j = 0; j < C; ++j) result[i][j] = '*';
			}
			result[R-1][C-1] = 'c';
			possible = true;
		}
		else possible = start(0, 0, 0);
		cout << "Case #" << k << ':' << endl;
		if (possible) printResult();
		else cout << "Impossible" << endl;
	}
}