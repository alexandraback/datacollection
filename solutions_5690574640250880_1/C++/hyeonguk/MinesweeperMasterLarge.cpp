
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

void testCaseSmall()
{
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

void printCheck(const vector<vector<bool>> &check)
{
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (i == r && j == c)
			{
				fprintf(fout, "c");
			}
			else
			{
				fprintf(fout, "%s", check[i][j] ? "*" : ".");
			}
		}
		fprintf(fout, "\n");
	}
}

#define MAX 64
bool table[MAX][MAX][MAX * MAX];
int pJTrack[MAX][MAX][MAX * MAX];

void testCaseLarge()
{
	vector<vector<bool>> check(MAX, vector<bool>(MAX));

	// [Ãþ][¸¶Áö¸· °³¼ö][ÇÕ] = true/false;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			for (int p = 0; p < MAX * MAX; p++)
			{
				table[i][j][p] = 0;
			}
		}
	}
	table[0][c][0] = true;

	for (int i = 1; i <= r; i++)
	{
		for (int j = 0; j <= c; j++)
		{
			if (j == c - 1)
			{
				continue;
			}
			for (int k = 0; k <= m; k++)
			{
				// [Ãþ - 1][prevJ][ÇÕ - j]¿¡¼­ °¡Á®¿È
				if (k - j < 0)
				{
					continue;
				}
				for (int prevJ = j; prevJ <= c; prevJ++)
				{
					table[i][j][k] |= table[i - 1][prevJ][k - j];
					if (table[i][j][k])
					{
						pJTrack[i][j][k] = prevJ;
						break;
					}
				}
			}
		}
	}

	// °¡Àå ¹Ø 2Ä­
	for (int width = 0; width <= c - 2; width++)
	{
		for (int prevJ = width; prevJ <= c; prevJ++)
		{
			if (m - width * 2 >= 0)
			{
				if (table[r - 2][prevJ][m - width * 2])
				{
					for (int j = 1; j <= width; j++)
					{
						check[r][j] = check[r - 1][j] = true;
					}
					int k = m - width * 2;
					for (int i = r - 2; i > 0; i--)
					{
						for (int j = 1; j <= prevJ; j++)
						{
							check[i][j] = true;
						}

						int pp = prevJ;
						prevJ = pJTrack[i][prevJ][k];
						k -= pp;
					}
					printCheck(check);
					return;
				}
			}
		}
	}

	fprintf(fout, "Impossible\n");
}

void testCase()
{
	fscanf(fin, "%d%d%d", &r, &c, &m);

	if (r == 1 || c == 1)
	{
		int count = 0;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (i == r - 1 && j == c - 1)
				{
					fprintf(fout, "c");
				}
				else if (count < m)
				{
					count++;
					fprintf(fout, "*");
				}
				else
				{
					fprintf(fout, ".");
				}
			}
			fprintf(fout, "\n");
		}
		return;
	}

	if (r * c - 1 == m)
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
		return;
	}

	testCaseLarge();
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
