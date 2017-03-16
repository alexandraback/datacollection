#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	int cases;

	fin.open("A-small-attempt0.in");
	fout.open("output.txt");

	fin >> cases;
	for (int i = 0; i < cases; i++)
	{
		bool possible_draw = true;
		bool O_winner = false;
		bool X_winner = false;
		string result;
		int results[10] = {0,0,0,0,0,0,0,0,0,0};
		char input_char;

		for (int row = 0; row < 4; row++)
		{
			for (int column = 4; column < 8; column++)
			{
				fin >> ws >> input_char;
				int to_add = 0;

				if (input_char == 'T')
				{
					to_add = 9;
				}
				else if (input_char == '.')
				{
					possible_draw = false;
				}
				else
				{
					if (input_char == 'O')
					{
						to_add = 1;
					}
					else
					{
						to_add = 8;
					}
				}

				results[row] += to_add;
				results[column] += to_add;

				if (row + column == 7)
				{
					results[9] += to_add;
				}
				else if (column - row == 4)
				{
					results[8] += to_add;
				}
			}
		}

		for (int res = 0; res < 10; res++)
		{
			if (results[res] & 32)
			{
				X_winner = true;
				break;
			}
			else if (results[res] & 4)
			{
				O_winner = true;
				break;
			}
		}

		if (O_winner)
		{
			result = "O won";
		}
		else if (X_winner)
		{
			result = "X won";
		}
		else if (possible_draw)
		{
			result = "Draw";
		}
		else
		{
			result = "Game has not completed";
		}

		fout << "Case #" << i + 1 << ": " << result << endl;
	}

	fin.close();
	fout.close();
}