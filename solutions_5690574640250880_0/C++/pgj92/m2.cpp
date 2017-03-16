#include <iostream>
using namespace std;

const int _MAX = 50 * 50;
int T, R, C, M;
char grid[_MAX];
bool visited[_MAX];
bool DONE = false;


int pos(int x, int y)
{
	return x * C + y;
}

void printGrid()
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cout << grid[pos(i,j)];
		cout << endl;
	}
}

bool inGrid(int x, int y)
{
	return x >= 0 && x < R && y >= 0 && y < C;
}

bool isZero(int x, int y)
{
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if (inGrid(x + i, y + j)) {
				if (grid[pos(x + i,y + j)] == '*')
					return false;
			}

	return true;
}

int oneShot(int x, int y)
{
	if (!inGrid(x,y))
		return 0;

	//visited
	if (visited[pos(x,y)] == true)
		return 0;

	visited[pos(x,y)] = true;

	//Nothing more to reveal
	if (!isZero(x, y))
		return 1;

	//(x,y) is zero
	int sum = 0;
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if (inGrid(x + i, y + j)) {
				sum += oneShot(x + i, y + j);
			}

	return sum + 1;
}

bool tryOneShot()
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (grid[pos(i,j)] == '.') {
				for (int k = 0; k < R * C; k++)
					visited[k] = false;

				if (oneShot(i, j) == R*C - M) {
					grid[pos(i,j)] = 'c';
					return true;
				}
			}
		}
	}

	return false;
}

void bt(int i, int m)
{
	if (i == R*C) {
		if (tryOneShot()) {
			DONE = true;
		}
		return;
	}

	if (m > 0) {
		grid[i] = '*';
		bt(i+1, m-1);
		if (DONE)
			return;
	}

	if (R*C - i > m) {
		grid[i] = '.';
		bt(i+1, m);
	}
}

void solve(int tc)
{
	cin >> R >> C >> M;

	DONE = false;
	bt(0, M);
	cout << "Case #" << tc << ": " << endl;
	if (DONE)
		printGrid();
	else
		cout << "Impossible" << endl;
}

int main()
{
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve(i);
	}

	return 0;
}