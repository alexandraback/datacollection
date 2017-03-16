#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
using namespace std;
const int ZX = 200;
const int ZY = 200;
const int MOP = 500;
int can[ZX * 2][ZY * 2][MOP + 1];
int par[ZX * 2][ZY * 2][MOP + 1];
int R, C;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dc[] = {'N', 'S', 'E', 'W'};

bool make_road(int r, int c)
{
	return r >= 0 && r < R && c >= 0 && c < C;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("B-small-attempt0.in");
	ofstream cout("B-small-attempt0.out");


	R = ZX * 2; C = ZY * 2;

	can[ZX][ZY][0] = 1;

	int tx = -1 + ZX;
	int ty = 0 + ZY;

	for (int it = 0; it < MOP; ++it)
	{
		int ca = it + 1;
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
				if (can[i][j][it])
				{
					for (int k = 0; k < 4; ++k)
						if (make_road(i + dx[k]*ca, j + dy[k]*ca))
						{
							can[i + dx[k]*ca][j + dy[k]*ca][it+1] = 1;
							par[i + dx[k]*ca][j + dy[k]*ca][it+1] = k;
						}
				}
	}

	int T;
	cin >> T;

	for (int ts = 1; ts <= T; ++ts)
	{

		int x, y;
		cin >> x >> y;
		x += ZX; y += ZY;

		int it;
		for (it = 0; !can[x][y][it] ; ++it);

		vector<char> ans;

		while (it)
		{
			ans.push_back(dc[par[x][y][it]]);
			int cx = x;
			int cy = y;
			x -= dx[par[cx][cy][it]] * it;
			y -= dy[par[cx][cy][it]] * it;
			--it;
		}

		reverse(ans.begin(), ans.end());
		cout << "Case #" << ts << ": " << string(ans.begin(), ans.end()) << endl;
	}




	//system("PAUSE");
	cin.close(); cout.close();
	return 0;
}

