#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> coord;

int h, n, m;
int ceiling[100][100]; // потолок
int _floor[100][100]; // пол
int time[100][100];
queue<pair<int, int>> q;

bool goable(coord a, coord b)
{
	return
		b.first >= 0 && b.first < n &&
		b.second >= 0 && b.second < m &&
		ceiling[b.first][b.second] - _floor[b.first][b.second] >= 50 &&
		ceiling[a.first][a.second] - _floor[b.first][b.second] >= 50 &&
		ceiling[b.first][b.second] - _floor[a.first][a.second] >= 50;
}

coord _n(coord x)
{
	return coord(x.first - 1, x.second);
}

coord _s(coord x)
{
	return coord(x.first + 1, x.second);
}

coord _w(coord x)
{
	return coord(x.first, x.second - 1);
}

coord _e(coord x)
{
	return coord(x.first, x.second + 1);
}

void solve()
{
	cin >> h >> n >> m;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ceiling[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> _floor[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			time[i][j] = 10000000;
	time[0][0] = 0;
	q.push(pair<int, int>(0, 0));

	while (!q.empty())
	{
		int cur_h = h - time[q.front().first][q.front().second];
		int cur_hh;
		int t;

		if (goable(q.front(), _n(q.front())))
		{
			coord next = _n(q.front());

			if (ceiling[next.first][next.second] - cur_h - 50 >= 0 && time[q.front().first][q.front().second] == 0 && time[next.first][next.second] != 0)
			{
				time[next.first][next.second] = 0;
				q.push(next);
			}
			else
			{
				if (ceiling[next.first][next.second] - cur_h - 50 >= 0)
				{
					cur_hh = cur_h;
				}
				else
				{
					cur_hh = ceiling[next.first][next.second] - 50;
				}
				t = time[q.front().first][q.front().second] + (cur_hh - 20 >= _floor[q.front().first][q.front().second] ? 10 : 100) + cur_h - cur_hh;
				if (t < time[next.first][next.second])
				{
					time[next.first][next.second] = t;
					q.push(next);
				}
			}
		}

		if (goable(q.front(), _s(q.front())))
		{
			coord next = _s(q.front());

			if (ceiling[next.first][next.second] - cur_h - 50 >= 0 && time[q.front().first][q.front().second] == 0 && time[next.first][next.second] != 0)
			{
				time[next.first][next.second] = 0;
				q.push(next);
			}
			else
			{
				if (ceiling[next.first][next.second] - cur_h - 50 >= 0)
				{
					cur_hh = cur_h;
				}
				else
				{
					cur_hh = ceiling[next.first][next.second] - 50;
				}
				t = time[q.front().first][q.front().second] + (cur_hh - 20 >= _floor[q.front().first][q.front().second] ? 10 : 100) + cur_h - cur_hh;
				if (t < time[next.first][next.second])
				{
					time[next.first][next.second] = t;
					q.push(next);
				}
			}
		}

		if (goable(q.front(), _w(q.front())))
		{
			coord next = _w(q.front());

			if (ceiling[next.first][next.second] - cur_h - 50 >= 0 && time[q.front().first][q.front().second] == 0 && time[next.first][next.second] != 0)
			{
				time[next.first][next.second] = 0;
				q.push(next);
			}
			else
			{
				if (ceiling[next.first][next.second] - cur_h - 50 >= 0)
				{
					cur_hh = cur_h;
				}
				else
				{
					cur_hh = ceiling[next.first][next.second] - 50;
				}
				t = time[q.front().first][q.front().second] + (cur_hh - 20 >= _floor[q.front().first][q.front().second] ? 10 : 100) + cur_h - cur_hh;
				if (t < time[next.first][next.second])
				{
					time[next.first][next.second] = t;
					q.push(next);
				}
			}
		}

		if (goable(q.front(), _e(q.front())))
		{
			coord next = _e(q.front());

			if (ceiling[next.first][next.second] - cur_h - 50 >= 0 && time[q.front().first][q.front().second] == 0 && time[next.first][next.second] != 0)
			{
				time[next.first][next.second] = 0;
				q.push(next);
			}
			else
			{
				if (ceiling[next.first][next.second] - cur_h - 50 >= 0)
				{
					cur_hh = cur_h;
				}
				else
				{
					cur_hh = ceiling[next.first][next.second] - 50;
				}
				t = time[q.front().first][q.front().second] + (cur_hh - 20 >= _floor[q.front().first][q.front().second] ? 10 : 100) + cur_h - cur_hh;
				if (t < time[next.first][next.second])
				{
					time[next.first][next.second] = t;
					q.push(next);
				}
			}
		}

		q.pop();
	}

	cout << time[n - 1][m - 1] / 10 << '.' << time[n - 1][m - 1] % 10 << endl;
}

int main()
{
	int T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cout << "Case #" << i + 1 << ": ";
		solve();
	}

	return 0;
}

