#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

void Mark(int i, int j, vector<vector<char> >& map, int& empty)
{
	if (i < 0 || j < 0 || i >= map.size() || j >= map[0].size() || empty <= 0 || map[i][j] == 'x')
	{
		return;
	}
	map[i][j] = 'x';
	--empty;
}

void Mark(int i, int j, vector<vector<char> >& map)
{
	if (i < 0 || j < 0 || i >= map.size() || j >= map[0].size())
	{
		return;
	}
	map[i][j] = '.';
}

void Fill(int i, int j, vector<vector<char> >& map, int& empty);

void Fill2(int i, int j, vector<vector<char> >& map, int& empty)
{
	if (i < 0 || j < 0 || i >= map.size() || j >= map[0].size() || empty <= 0)
	{
		return;
	}
	Mark(i, j, map, empty);
	Mark(i - 1, j, map, empty);
	Mark(i, j - 1, map, empty);
	Mark(i - 1, j - 1, map, empty);
	Fill2(i, j - 1, map, empty);
}

void Fill(int i, int j, vector<vector<char> >& map, int& empty)
{
	if (i < 0 || j < 0 || i >= map.size() || j >= map[0].size() || empty <= 0)
	{
		return;
	}
	Mark(i, j, map, empty);
	Mark(i - 1, j, map, empty);
	Mark(i, j - 1, map, empty);
	Mark(i - 1, j - 1, map, empty);
	Fill2(i , j - 1, map, empty);
	Fill(i - 1, j, map, empty);
	Fill(i - 1, j - 1, map, empty);
}

bool NotMine(int i, int j, vector<vector<char> >& map)
{
	if (i < 0 || j < 0 || i >= map.size() || j >= map[0].size())
	{
		return true;
	}
	return (map[i][j] != '*');
}

bool NoMineNearby(int i, int j, vector<vector<char> >& map)
{
	bool result = true;
	for (int di = -1; di <= 1; ++di)
	{
		for (int dj = -1; dj <= 1; ++dj)
		{
			result &= NotMine(i + di, j + dj, map);
		}
	}
	return result;
}

void Check(int i, int j, vector<vector<char> >& map)
{
	if (i < 0 || j < 0 || i >= map.size() || j >= map[0].size())
	{
		return;
	}
	if (map[i][j] == '*')
	{
		return;
	}
	if (NoMineNearby(i, j, map))
	{
		Mark(i, j, map);
		Mark(i - 1, j - 1, map);
		Mark(i - 1, j, map);
		Mark(i, j - 1, map);
		Check(i, j - 1, map);
		Check(i - 1, j, map);
		Check(i - 1, j - 1, map);
	}
}

void solve(int index)
{
	int C, R, M;
	cin >> R >> C >> M;
	cout << "Case #" << index + 1 << ": ";
	cout << endl;
	vector<vector<char> > map(R, vector<char>(C, '*'));
	int empty = C * R - M;
	/*Fill(R - 1, C - 1, map, empty);*/
	if (R <= 2 || C <= 2)
	{
		for (int i = R - 1; i >= 0; --i)
		{
			for (int j = C - 1; j >= 0; --j)
			{
				Mark(i, j, map, empty);
				Mark(i - 1, j, map, empty);
			}
		}
	}
	else if (empty >= 2 * C + 2 || empty % 2 == 0)
	{
		for (int i = R - 1; i >= 0; --i)
		{
			for (int j = C - 1; j >= 0; --j)
			{
				Mark(i, j, map, empty);
				Mark(i - 1, j, map, empty);
			}
		}
	}
	else
	{
		for (int i = R - 1; i >= R - 3; --i)
		{
			for (int j = C - 1; j >= C - 3; --j)
			{
				Mark(i, j, map, empty);
			}
		}
		for (int i = R - 1; i >= 0; --i)
		{
			for (int j = C - 1; j >= 0; --j)
			{
				Mark(i, j, map, empty);
				Mark(i - 1, j, map, empty);
			}
		}
	}

	if (R > 2 && C > 2 && (M + 1) % C == 0 && (M + 1) / C < R)
	{
		map[M / C][C - 2] = 'x';
		map[M / C + 1][0] = '*';
	}
	bool impossible = false;
	Check(R - 1, C - 1, map);
	map[R - 1][C - 1] = 'c';
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			impossible |= map[i][j] == 'x';
		}
	}
	if (impossible)
	{
		cout << "Impossible";
		cout << endl;
	}
	else
	{
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				cout << map[i][j];
			}
			cout << endl;
		}
	}
}

int main(int argc, char **argv)
{
	//Sleep(10000);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		solve(i);
	}
	return 0;
}