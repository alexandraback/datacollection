#include <cassert>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

const int N = 1 << 8;
int d[N + N] [N + N];
int step[N + N] [N + N];

char dir[] = {'N', 'S', 'E', 'W'};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


void prepare()
{
	memset(d, 0xFF, sizeof(d));

	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	d[N][N] = 0;

	while(!q.empty())
	{
		pair<int, int> c = q.front();
		q.pop();

		int dist = 1 + d[c.second + N][c.first + N];
		for(int i = 0; i < 4; i++)
		{
			int x = c.first + dx[i] * dist;
			int y = c.second + dy[i] * dist;

			if(y + N >= 0 && y + N < 2 * N && x + N >= 0 && x + N < 2 * N && d[y + N][x + N] < 0)
			{
				d[y + N][x + N] = dist;
				step[y + N][x + N] = i;
				q.push(make_pair(y, x));
			}
		}
	}
}


void solve(int x, int y)
{
	vector<char> path;

	while(x != 0 || y != 0)
	{
		int s = step[y + N][x + N];
		int dist = d[y + N][x + N];

		path.push_back(dir[s]);

		y -= dist * dy[s];
		x -= dist * dx[s];
	}

	for(int i = (int)path.size() - 1; i >= 0; i--)
		printf("%c", path[i]);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	prepare();

	int t;
	scanf("%i\n", &t);

	for(int ti = 1; ti <= t; ti++)
	{
		int x, y;
		scanf("%i %i\n", &x, &y);
		cout << "Case #" << ti << ": ";
		solve(x, y);
		cout << "\n";
	}

	return 0;
}
