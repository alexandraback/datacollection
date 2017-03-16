#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cstdlib>

using namespace std;

int n;
vector<int> r, c, m;


void read_data(char* filename)
{
	ifstream fin(filename);
	fin >> n;
	r.resize(n);
	c.resize(n);
	m.resize(n);
	for(int i = 0; i < n; i++)
	{
		fin >> r[i] >> c[i] >> m[i];
	}
	fin.close();
}

int get_current_mines(int i, vector<int>& trace)
{
	int mines;

	if(trace[0] == c[i]) mines = 0;
	else mines = (c[i] - trace[0] - 1);

	for(int j = 1; j < r[i]; j++)
	{
		int prev;
		if(trace.size() > j - 1)
		{
			prev = trace[j - 1];
		}
		else
		{
			prev = -1;
		}

		if(prev < c[i]) mines += (c[i] - prev - 1);
	}

	return mines;
}

void draw_board(int i, vector<int>& trace, vector< vector<int> >& board)
{
	board.resize(r[i]);
	for(int j = 0; j < r[i]; j++)
	{
		board[j].resize(c[i]);
	}

	if(trace[0] < c[i])
	{
		for(int k = 0; k < (c[i] - trace[0] - 1); k++)
		{
			board[0][c[i] - k - 1] = 1;
		}
	}

	for(int j = 1; j < r[i]; j++)
	{
		int prev;
		if(trace.size() > j - 1)
		{
			prev = trace[j - 1];
		}
		else
		{
			prev = -1;
		}

		if(prev < c[i])
		{
			for(int k = 0; k < (c[i] - prev - 1); k++)
			{
				board[j][c[i] - k - 1] = 1;
			}
		}
	}
}

int get_minimum_mines(int i, vector<int>& trace)
{
	int mines;

	if(trace[0] == c[i]) mines = 0;
	else mines = (c[i] - trace[0] - 1);

	for(int j = 1; j < r[i]; j++)
	{
		int prev;
		if(trace.size() > j - 1)
		{
			prev = trace[j - 1];
		}
		else
		{
			prev = trace[trace.size() - 1];
		}

		if(prev < c[i]) mines += (c[i] - prev - 1);
	}

	return mines;
}



bool brute_force(int i, int row, int max_col, vector<int>& trace)
{
	for(int col = 1; col <= max_col; col++)
	{
		trace.push_back(col);
		if(get_minimum_mines(i, trace) <= m[i])
		{
			if(get_current_mines(i, trace) == m[i] || (row < r[i] && brute_force(i, row + 1, col, trace)))
			{
				return true;
			}
		}
		trace.pop_back();
	}
	return false;
}


void proc()
{
	for(int i = 0; i < n; i++)
	{
		cout << "Case #" << i + 1 << ":" << endl;


		if(r[i] * c[i] - m[i] == 1)
		{
			for(int j = 0; j < r[i]; j++)
			{
				for(int k = 0; k < c[i]; k++)
				{
					if(j == 0 && k == 0) cout << "c";
					else cout << "*";
				}
				cout << endl;
			}
			continue;
		}



		vector<int> trace;
		if(brute_force(i, 1, c[i], trace))
		{
			vector< vector<int> > board;
			draw_board(i, trace, board);

			for(int j = 0; j < r[i]; j++)
			{
				for(int k = 0; k < c[i]; k++)
				{
					if(j == 0 && k == 0) cout << "c";
					else if(board[j][k] == 1) cout << "*";
					else cout << ".";
				}
				cout << endl;
			}
		}
		else
		{
			cout << "Impossible" << endl;
		}
	}
}

int main(int argc, char** argv)
{
	read_data(argv[1]);
	proc();
	return 0;
}

