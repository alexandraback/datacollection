#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF (1 << 30)

int T, tt;
vector<vector<int> > floor;
vector<vector<int> > ceil;
vector<vector<int> > minTime; 	// in tenths of seconds
int water, nRows, nCols;
int currTime;									// in tenths of seconds

bool load() {
	if (tt == T) {
		return false;
	}
	floor.clear();
	ceil.clear();
	minTime.clear();
	currTime = 0;
	tt++;
	cin >> water;
	cin >> nRows;
	cin >> nCols;
	floor.resize(nRows, vector<int>(nCols, -1));
	ceil.resize(nRows, vector<int>(nCols, -1));
	minTime.resize(nRows, vector<int>(nCols, INF));
	for (int r = 0; r < nRows; r++) {
		for (int c = 0; c < nCols; c++) {
			cin >> ceil[r][c];
		}
	}
	for (int r = 0; r < nRows; r++) {
		for (int c = 0; c < nCols; c++) {
			cin >> floor[r][c];
		}
	}
	minTime[0][0] = 0;
	return true;
}

// assumes adjacency
int moveTime(int fromRow, int fromCol, int toRow, int toCol) {
	if (fromRow < 0 || fromCol < 0 || toRow < 0 || toCol < 0) {
		return INF;
	}
	if (fromRow >= nRows || fromCol >= nCols || toRow >= nRows || toCol >= nCols) {
		return INF;
	}
	int fromFloor = floor[fromRow][fromCol];
	int fromCeil = ceil[fromRow][fromCol];
	int toFloor = floor[toRow][toCol];
	int toCeil = ceil[toRow][toCol];
	if ((toCeil - water < 50) || (toCeil - fromFloor < 50) || (toCeil - toFloor < 50)) {
		return INF;
	}
	if (fromCeil - toFloor < 50) {
		return INF;
	}
	if (water - fromFloor >= 20) {
		return 10;
	} else {
		return 100;
	}
}

void timeZero() {
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();
		int rChange, cChange;
		int toRow, toCol;
		rChange = -1; cChange = 0;
		toRow = curr.first + rChange; toCol = curr.second + cChange;
		if (moveTime(curr.first, curr.second, toRow, toCol) < INF &&  minTime[toRow][toCol] == INF) {
			minTime[toRow][toCol] = 0;
			q.push(make_pair(toRow, toCol));
		}

		rChange = 1; cChange = 0;
		toRow = curr.first + rChange; toCol = curr.second + cChange;
		if (moveTime(curr.first, curr.second, toRow, toCol) < INF &&  minTime[toRow][toCol] == INF) {
			minTime[toRow][toCol] = 0;
			q.push(make_pair(toRow, toCol));
		}

		rChange = 0; cChange = -1;
		toRow = curr.first + rChange; toCol = curr.second + cChange;
		if (moveTime(curr.first, curr.second, toRow, toCol) < INF &&  minTime[toRow][toCol] == INF) {
			minTime[toRow][toCol] = 0;
			q.push(make_pair(toRow, toCol));
		}

		rChange = 0; cChange = 1;
		toRow = curr.first + rChange; toCol = curr.second + cChange;
		if (moveTime(curr.first, curr.second, toRow, toCol) < INF && minTime[toRow][toCol] == INF) {
			minTime[toRow][toCol] = 0;
			q.push(make_pair(toRow, toCol));
		}
	}
}

void printGrid() {
	for (int r = 0; r < nRows; r++) {
		for (int c = 0; c < nCols; c++) {
			printf("%d/%d(%d) ", ceil[r][c], floor[r][c], minTime[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}

void doMoves() {
	for (int r = 0; r < nRows; r++) {
		for (int c = 0; c < nCols; c++) {
			if (minTime[r][c] <= currTime) {
				int rChange, cChange;
				int toRow, toCol;
				rChange = -1; cChange = 0;
				toRow = r + rChange; toCol = c + cChange;
				if (moveTime(r, c, toRow, toCol) < INF && minTime[toRow][toCol] == INF) {
					minTime[toRow][toCol] = currTime + moveTime(r, c, toRow, toCol);
				}

				rChange = 1; cChange = 0;
				toRow = r + rChange; toCol = c + cChange;
				if (moveTime(r, c, toRow, toCol) < INF && minTime[toRow][toCol] == INF) {
					minTime[toRow][toCol] = currTime + moveTime(r, c, toRow, toCol);
				}

				rChange = 0; cChange = -1;
				toRow = r + rChange; toCol = c + cChange;
				if (moveTime(r, c, toRow, toCol) < INF && minTime[toRow][toCol] == INF) {
					minTime[toRow][toCol] = currTime + moveTime(r, c, toRow, toCol);
				}

				rChange = 0; cChange = 1;
				toRow = r + rChange; toCol = c + cChange;
				if (moveTime(r, c, toRow, toCol) < INF && minTime[toRow][toCol] == INF) {
					minTime[toRow][toCol] = currTime + moveTime(r, c, toRow, toCol);
				}
			}
		}
	}
}

int main() {
	cin >> T;
	tt = 0;
	while (load()) {
		timeZero();
		//printGrid();
		while (true) {
			doMoves();
			if (minTime[nRows-1][nCols-1] < INF) {
				printf("Case #%d: %lf\n", tt, minTime[nRows-1][nCols-1]/10.0);
				break;
			}
			++currTime;
			--water;
			//printf("WATER: %d, TIME: %d\n", water, currTime);
			//printGrid();
		}
	}
	return 0;
}
