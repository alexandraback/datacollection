#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;
int distances[128][128];
bool vis[128][128];
int maxWaters[128][128];

int floorMat[128][128];
int ceiling[128][128];
int n, m;
bool canPass(int x, int y, int newX, int newY, int water)
{
	if (newX < 0 || newX >= n || newY < 0 || newY >= m)
		return false;
	if (ceiling[newX][newY] - max(water, floorMat[x][y]) < 50)
		return false;
	if (ceiling[newX][newY] - max(water, floorMat[newX][newY]) < 50)
		return false;
	if (ceiling[x][y] - max(water, floorMat[newX][newY]) < 50)
		return false;
	return true;
}

int getMaxWater(int x, int y, int newX, int newY)
{
	if (newX < 0 || newX >= n || newY < 0 || newY >= m)
		return -1;
	int maxWater = 10000000;
	if (ceiling[newX][newY] - floorMat[x][y] < 50)
		return -1;
	if (ceiling[newX][newY] - floorMat[newX][newY] < 50)
		return -1;
	if (ceiling[x][y] - floorMat[newX][newY] < 50)
		return -1;
	maxWater = min(maxWater, ceiling[newX][newY] - 50);
	maxWater = min(maxWater, ceiling[x][y] - 50);
	return maxWater;
}


typedef pair<int, pair<int, int> > point;
int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);
		int h;
		cin >> h >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				distances[i][j] = 100000000;
		for (int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> ceiling[i][j];
		for (int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> floorMat[i][j];
		priority_queue<point, vector<point>, greater<point> > toProcess;
		queue<pair<int, int> > q;
		q.push(make_pair(0, 0));
		toProcess.push(make_pair(0, make_pair(0, 0)));
		memset(vis, false, sizeof(vis));
		memset(maxWaters, -1, sizeof(maxWaters));
		maxWaters[0][0] = h;
		vis[0][0] = true;
		distances[0][0] = 0;
		int mat[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		pair<int, int> cur1;
		while(!q.empty()) {
			cur1 = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				if (canPass(cur1.first, cur1.second, cur1.first + mat[i][0], cur1.second + mat[i][1], h)
					&& !vis[cur1.first + mat[i][0]][cur1.second + mat[i][1]])
				{
					vis[cur1.first + mat[i][0]][cur1.second + mat[i][1]] = true;
					maxWaters[cur1.first + mat[i][0]][cur1.second + mat[i][1]] = h;
					distances[cur1.first + mat[i][0]][cur1.second + mat[i][1]] = 0;
					q.push(make_pair(cur1.first + mat[i][0], cur1.second + mat[i][1]));
					toProcess.push(make_pair(0, make_pair(cur1.first + mat[i][0], cur1.second + mat[i][1])));
				}
			}
		}
		
		point cur;
		memset(vis, false, sizeof(vis));
		while(!toProcess.empty())
		{
			cur = toProcess.top();
			toProcess.pop();
			if (vis[cur.second.first][cur.second.second])
				continue;
			vis[cur.second.first][cur.second.second] = true;
			for (int i = 0; i < 4; i++)
			{
				int maxWater = getMaxWater(cur.second.first, cur.second.second, cur.second.first + mat[i][0], cur.second.second + mat[i][1]);
				if (maxWater == -1)
					continue;
				maxWater = min(maxWater, maxWaters[cur.second.first][cur.second.second]);
				if (vis[cur.second.first + mat[i][0]][cur.second.second + mat[i][1]])
					continue;
				int time = distances[cur.second.first][cur.second.second] + max(0, maxWaters[cur.second.first][cur.second.second] - maxWater);
				int moveTime = 0;
				if (maxWater - 20 >= floorMat[cur.second.first][cur.second.second])
					moveTime = 10;
				else
					moveTime = 100;
				time += moveTime;
				if(time < distances[cur.second.first + mat[i][0]][cur.second.second + mat[i][1]])
				{
					distances[cur.second.first + mat[i][0]][cur.second.second + mat[i][1]] = time;
					maxWaters[cur.second.first + mat[i][0]][cur.second.second + mat[i][1]] = max(0, min(maxWater, maxWaters[cur.second.first][cur.second.second]) - moveTime);
					toProcess.push(make_pair(time, make_pair(cur.second.first + mat[i][0], cur.second.second + mat[i][1])));
				}
			}
		}
		printf("%.2lf\n", (double)distances[n - 1][m - 1] / 10.0);

	}
	return 0;
}
