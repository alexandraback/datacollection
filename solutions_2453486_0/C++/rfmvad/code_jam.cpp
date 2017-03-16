#include <algorithm>
#include "BigIntegerLibrary.hh"
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ifstream in;
	ofstream out;
	int T;
	string line;
	string b[4];
	bool ow, xw;

	in.open("D:\\code_jam_in.txt");
	out.open ("D:\\code_jam_out.txt");

	in >> T;
	getline(in, line);

	for (int t = 1; t <= T; t++)
	{
		for (int i = 0; i < 4; i++)
			getline(in, b[i]);
		getline(in, line);

		bool o_win = false;
		bool x_win = false;
		bool empty = false;

		for (int i = 0; i < 4; i++)
		{
			ow = true;
			xw = true;

			for (int j = 0; j < 4; j++)
			{
				ow &= b[i][j] == 'O' || b[i][j] == 'T';
				xw &= b[i][j] == 'X' || b[i][j] == 'T';
				empty |= b[i][j] == '.';
			}

			o_win |= ow;
			x_win |= xw;
		}

		for (int j = 0; j < 4; j++)
		{
			ow = true;
			xw = true;

			for (int i = 0; i < 4; i++)
			{
				ow &= b[i][j] == 'O' || b[i][j] == 'T';
				xw &= b[i][j] == 'X' || b[i][j] == 'T';
			}

			o_win |= ow;
			x_win |= xw;
		}

		ow = true;
		xw = true;
		for (int i = 0; i < 4; i++)
		{
			ow &= b[i][i] == 'O' || b[i][i] == 'T';
			xw &= b[i][i] == 'X' || b[i][i] == 'T';
		}

		o_win |= ow;
		x_win |= xw;

		ow = true;
		xw = true;
		for (int i = 0; i < 4; i++)
		{
			ow &= b[i][3 - i] == 'O' || b[i][3 - i] == 'T';
			xw &= b[i][3 - i] == 'X' || b[i][3 - i] == 'T';
		}

		o_win |= ow;
		x_win |= xw;

		out << "Case #" << t << ": ";

		if (o_win)
			out << "O won";
		else if (x_win)
			out << "X won";
		else if (empty)
			out << "Game has not completed";
		else
			out << "Draw";

		out << endl;
	}

	in.close();
	out.close();
	
	return 0;
}