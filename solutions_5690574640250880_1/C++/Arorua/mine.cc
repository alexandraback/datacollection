#include <iostream>
#include <cstring>

using namespace std;

int M, N, found = 0;
int tag[64][64], map[64][64], k[64];
char buf[64][64];


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

void DFS(int x, int m, int r)
{
	if (found) return;
	if (r == 0) {
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				map[i][j] = 1;
		for (int i = 0; i < x; ++i) 
			for (int j = 0; j < k[i]; ++j)
				map[i][j] = 0;

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
	if ((M - x) * m < r) return;	
	for (int i = min(m, r); i > 0; --i) {
		k[x] = i;
		DFS(x + 1, i, r - i);
	}
}

int process(int k)
{
	int m;
	cin >> M >> N >> m;
	found = 0;	
	cout << "Case #" << k << ":" << endl;
	DFS(0, N, M * N - m);
	if (!found) cout << "Impossible" << endl;
}

int main()
{
	int k;
	cin >> k;
	for (int i = 1; i <= k; ++i) process(i);
}

