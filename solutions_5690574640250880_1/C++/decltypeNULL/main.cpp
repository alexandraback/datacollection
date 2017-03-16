#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cassert>
using namespace std;

int M, R, C;
int F; // free
// F!=0
int mn; //min(R,C)

const int MX = 149;
char ans[MX][MX];

void init(void)
{
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) ans[i][j] = '*';
}

void fill_1(void)
{
	ans[0][0] = 'c';
}

void fill_1_N(void)
{
	if (R == 1)
	{
		for (int j = 0; j < F; j++) ans[0][j] = '.';
	}
	else if (C == 1)
	{
		for (int i = 0; i < F; i++) ans[i][0] = '.';
	}
	else assert(false);

	ans[0][0] = 'c';
}

void fill_2_N(void)
{
	if (R == 2)
	{
		for (int j = 0; j < F / 2; j++) ans[0][j] = ans[1][j] = '.';
	}
	else if (C == 2)
	{
		for (int i = 0; i < F / 2; i++) ans[i][0] = ans[i][1] = '.';
	}
	else assert(false);

	ans[0][0] = 'c';
}

void fill_4(void)
{
	assert(mn >= 2);

	ans[0][0] = 'c';
	ans[0][1] = ans[1][0] = ans[1][1] = '.';
}

/*
void fill_5(void)
{
	assert(mn >= 3);

	ans[1][1] = 'c';
	ans[0][1] = ans[1][0] = ans[1][2] = ans[2][1] = '.';
}
*/

void fill_6(void)
{
	assert(mn >= 3);

	for (int i = 0; i < 3; i++) for (int j = 0; j < 2; j++) ans[i][j] = '.';
	ans[0][0] = 'c';
}

void neigh(int i, int j)
{
	for (int ii = i - 1; ii <= i + 1; ii++)
	{
		for (int jj = j - 1; jj <= j + 1; jj++)
		{
			if (0 <= ii && ii < R && 0 <= jj && jj < C)
			{
				if (ans[ii][jj] == '*') ans[ii][jj] = '.';
			}
		}
	}
}

void fill_at_least_8(void)
{
	neigh(0, 0);
	neigh(0, 1);
	neigh(1, 0);

	ans[0][0] = 'c';

	int todo = F - 8;
	int it_i = 2, it_j = 2;

	int it_ii = 1, it_jj = 1;

	while (todo > 0)
	{
		if (todo >=2 && (it_i < R - 1 || it_j < C - 1))
		{
			todo -= 2;
			if (it_i < R - 1)
			{
				neigh(it_i, 0);
				it_i++;
			}
			else
			{
				neigh(0, it_j);
				it_j++;
			}
		}
		else
		{
			todo--;
			neigh(it_ii, it_jj);
			it_ii++;
			if (it_ii >= R - 1)
			{
				it_jj++;
				it_ii = 1;
			}
		}
	}
}

bool solve(void)
{
	F = R*C - M;
	mn = min(R, C);

	init();

	if (F == 1) // one free cell
	{
		fill_1();
		return true;
	}

	if (mn == 1) // 1xN field
	{
		fill_1_N();
		return true;
	}

	if (F <= 3) // 2 or 3 free cells, not 1XN field, no config
	{
		return false;
	}

	if (F == 7) // no config
	{
		return false;
	}

	if (mn == 2) // 2xN field
	{
		if (F % 2 == 0)
		{
			fill_2_N();
			return true;
		}
		else return false;
	}

	// now, at least 3x3 field
	if (F == 4)
	{
		fill_4();
		return true;
	}

	if (F == 5)
	{
		return false;
	}

	if (F == 6)
	{
		fill_6();
		return true;
	}

	fill_at_least_8();
	return true;
}

bool check_field(void)
{
	int count_c = 0;
	int count_star = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			count_c += ans[i][j] == 'c';
			count_star += ans[i][j] == '*';
		}
	}
	
	if (count_c != 1) return false;
	if (count_star != M) return false;

	return true;
}

bool seen[MX][MX];
int _count;
void dfs(int i, int j)
{
	if (i < 0 || i >= R || j<0 || j>=C) return;
	if (seen[i][j]) return;
	seen[i][j] = true;
	if (ans[i][j] == '*') return;
	_count++;

	int neigbors_occ = 0;
	for (int ii = i - 1; ii <= i + 1; ii++)
	{
		for (int jj = j - 1; jj <= j + 1; jj++)
		{
			if (0 <= ii && ii < R && 0 <= jj && jj < C)
			{
				neigbors_occ += ans[ii][jj] == '*';
			}
		}
	}

	if (neigbors_occ == 0)
	{
		for (int ii = i - 1; ii <= i + 1; ii++)
		{
			for (int jj = j - 1; jj <= j + 1; jj++)
			{
				dfs(ii, jj);
			}
		}
	}
}

bool check_field2(void)
{
	int start_x, start_y;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (ans[i][j] == 'c')
			{
				start_x = i;
				start_y = j;
			}
		}
	}

	_count = 0;
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) seen[i][j] = false;
	dfs(start_x, start_y);
	return _count == F;
}

bool has_solution(void)
{
	if (F == 1) return true;
	if (mn == 1) return true;
	if (F == 2 || F == 3 || F==5 || F == 7) return false;
	if (mn == 2) return F % 2 == 0;
	return true;
}

void solve_C(void)
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	out << setprecision(10);

	int T;
	in >> T;
	for (int t = 1; t <= T; t++)
	{
		in >> R >> C >> M;
		out << "Case #" << t << ":\n";
		if (!solve())
		{
			out << "Impossible" << '\n';
			/*
			if (has_solution())
			{
				cout << R << ' ' << C << ' ' << M << endl;
				;
				;
			}
			*/
		}
		else
		{
			for (int i = 0; i < R; i++)
			{
				for (int j = 0; j < C; j++) out << ans[i][j];
				out << '\n';
			}

			/*
			if (!check_field() || !check_field2())
			{
				cout << R << ' ' << C << ' ' << M << endl;

				for (int i = 0; i < R; i++)
				{
					for (int j = 0; j < C; j++) cout << ans[i][j];
					cout << '\n';
				}

				;
				;
				;
				;
				cout << "\n----\n";
			}
			*/
			
		}
	}

	in.close();
	out.close();
}

int main()
{
	//solve_A();
	//solve_B();
	solve_C();
	return 0;
}