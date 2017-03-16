#include <iostream>
#include <cstring>

using namespace std;

int M, N, found = 0;
int map[10][10];
int tag[10][10];
char buf[10][10];

inline int proc(int x, int y)
{
	if (x < 0 || x >= M) return 0;
	if (y < 0 || y >= N) return 0;
	return map[x][y];
}

inline int calc(int x, int y)
{
	return proc(x-1,y-1) | proc(x-1,y) | proc(x-1,y+1)
		|  proc(x,y-1) | proc(x,y) | proc(x,y+1)
		|  proc(x+1,y-1) | proc(x+1,y) | proc(x+1,y+1);
}

int floodfill(int x, int y)
{
	if (x < 0 || x >= M) return 0;
	if (y < 0 || y >= N) return 0;
	if (tag[x][y]) return 0;
	if (map[x][y]) return 0;
	tag[x][y] = 1;
	if (calc(x,y)) return 1;
	floodfill(x-1,y-1);
	floodfill(x-1,y);
	floodfill(x-1,y+1);
	floodfill(x+1,y-1);
	floodfill(x+1,y);
	floodfill(x+1,y+1);
	floodfill(x,y-1);
	floodfill(x,y+1);
	return 1;
}

void DFS(int x, int y, int r)
{
	if (found) return;
	if (x == M && r == 0) {
		memset(tag, 0, sizeof(tag));
		int ans = 0;
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				if (floodfill(i, j))
					ans ++;
		if (ans != 1) return; 
		found = 1;
		int c = 1;
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				if (map[i][j] == 0) {
					buf[i][j] = '.';
				} else {
					buf[i][j] = '*';
				}
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				if (buf[i][j] == '.' && !calc(i, j) && c) {
					buf[i][j] = 'c';
					c = 0;
				}
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				if (buf[i][j] == '.' && c) {
					buf[i][j] = 'c';
					c = 0;
				}
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j)
					cout << buf[i][j];
			cout << endl;
		}
		return;
	}
	if (M * N - x * N - y < r) return;
	if (y + 1 < N) {
		map[x][y] = 0;
		DFS(x, y + 1, r);
		if (r) {
			map[x][y] = 1;
			DFS(x, y + 1, r - 1);
		}
	} else {
		map[x][y] = 0;
		DFS(x + 1, 0, r);
		if (r) {
			map[x][y] = 1;
			DFS(x + 1, 0, r - 1);
		}
	}
}

int process(int k)
{
	int m;
	cin >> M >> N >> m;
	found = 0;	
	cout << "Case #" << k << ":" << endl;
	DFS(0, 0, m);
	if (!found) cout << "Impossible" << endl;
}

int main()
{
	int k;
	cin >> k;
	for (int i = 1; i <= k; ++i)
		process(i);
}

