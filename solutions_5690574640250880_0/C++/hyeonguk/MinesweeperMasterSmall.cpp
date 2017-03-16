
#include <cstdio>

FILE *fin = fopen("input.txt", "rt"),
*fout = fopen("output.txt", "wt");

#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int r, c, m, total;

const int Deltas = 8;
const int Dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int Dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

vector<vector<bool>> board;
vector<vector<int>> counts;
vector<vector<bool>> went;

inline bool testStatus(int status)
{
	int count = 0;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int f = i * c + j;
			if (status & (1 << f))
			{
				board[i][j] = 1;
				count++;
			}
			else
			{
				board[i][j] = 0;
			}
		}
	}

	if (count != m)
	{
		return false;
	}

	if (count == r * c - 1)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (i == r - 1 && j == c - 1)
				{
					fprintf(fout, "c");
				}
				else
				{
					fprintf(fout, "*");
				}
			}
			fprintf(fout, "\n");
		}
		return true;
	}

	count = r * c - m;

	pair<int, int> start = make_pair(-1, -1);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			counts[i][j] = 0;
			for (int d = 0; d < Deltas; d++)
			{
				int x = Dx[d] + i;
				int y = Dy[d] + j;

				if ((0 <= x && x < r && 0 <= y && y < c) == false)
				{
					continue;
				}

				counts[i][j] += board[x][y];
			}

			if (counts[i][j] == 0 && !board[i][j])
			{
				start = make_pair(i, j);
			}
		}
	}

	if (start.first < 0)
	{
		return false;
	}

	queue<pair<int, int>> q;
	q.push(start);

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			went[i][j] = false;
		}
	}

	while (q.empty() == false)
	{
		auto current = q.front();
		q.pop();

		count--;
		went[current.first][current.second] = true;

		for (int d = 0; d < Deltas; d++)
		{
			int x = current.first + Dx[d];
			int y = current.second + Dy[d];

			if ((0 <= x && x < r && 0 <= y && y < c) == false)
			{
				continue;
			}
			if (went[x][y])
			{
				continue;
			}
			went[x][y] = true;
			if (counts[x][y] && !board[x][y])
			{
				count--;
				continue;
			}
			if (counts[x][y] || board[x][y])
			{
				continue;
			}
			q.push(make_pair(x, y));
		}
	}

	if (count != 0)
	{
		return false;
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (i == start.first && j == start.second)
			{
				fprintf(fout, "c");
			}
			else
			{
				fprintf(fout, "%s", board[i][j] ? "*" : ".");
			}
		}
		fprintf(fout, "\n");
	}
	return true;
}

void testCase()
{
	fscanf(fin, "%d%d%d", &r, &c, &m);

	board = vector<vector<bool>>(r, vector<bool>(c));
	counts = vector<vector<int>>(r, vector<int>(c));
	went = vector<vector<bool>>(r, vector<bool>(c));

	total = r * c;
	for (int status = 0; status < (1 << total); status++)
	{
		if (testStatus(status))
		{
			return;
		}
	}
	fprintf(fout, "Impossible\n");
}

int main()
{
	int t;
	fscanf(fin, "%d", &t);

	for (int i = 1; i <= t; i++)
	{
		printf("%d\n", i);
		fprintf(fout, "Case #%d:\n", i);
		testCase();
	}

	return 0;
}
