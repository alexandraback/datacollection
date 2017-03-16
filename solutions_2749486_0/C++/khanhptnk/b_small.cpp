#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

char direction[4] = {'N', 'E', 'S', 'W'};
int changeX[4] = {0, -1, 0, 1};
int changeY[4] = {-1, 0, 1, 0};

int ntest;
int X, Y;
int f[510][310][310];

void mark(int i, int x, int y, int dir) {
	if (x < 0 || x > 300 || y < 0 || y > 300) return;
	if (f[i][x][y] != -1) return;
	f[i][x][y] = dir;
}

void print(int i, int x, int y) {
	string ans = "";
	for (int k = i; k > 0; k--) {
		int cur = f[k][x][y];
		ans = direction[cur] + ans;
		x += changeX[cur] * k;
		y += changeY[cur] * k;
	}
	cout << ans << endl;
}

void bfs() {
	memset(f, -1, sizeof(f));
	f[0][100][100] = -2;
	for (int i = 0; i <= 500; i++)
		for (int x = 0; x <= 300; x++)
			for (int y = 0; y <= 300; y++)
				if (f[i][x][y] != -1) {
					//cout << i << ' ' << x << ' ' << y << endl;
					if (x == X && y == Y) {
						print(i, x, y);
						return;
					}
					mark(i + 1, x + (i + 1), y, 1);
					mark(i + 1, x - (i + 1), y, 3);
					mark(i + 1, x, y + (i + 1), 0);
					mark(i + 1, x, y - (i + 1), 2);
				}
}

int main() {
	//freopen("input.txt", "r", stdin);
	freopen("input_small.txt", "r", stdin);
	freopen("output_small.txt", "w", stdout);
	cin >> ntest;
	for (int test = 0; test < ntest; test++) {
		//cout <<test << endl;
		cin >> X >> Y;
		X += 100;
		Y += 100;
		cout << "Case #" << test + 1 << ": ";
		bfs();
	}
}
