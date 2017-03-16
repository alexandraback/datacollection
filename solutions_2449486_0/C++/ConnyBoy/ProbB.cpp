#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int cases;
	int height;
	int lawn[102][102][5];
	string output;
	ifstream fin;
	ofstream fout;

	fin.open("B-small-attempt1.in");
	fout.open("output.txt");

	fin >> cases;
	for (int i = 0; i < cases; i++)
	{
		int N, M;
		fin >> N >> M;
		for (int rows = 0; rows < N + 2; rows++)
		{
			for (int columns = 0; columns < M + 2; columns++)
			{
				if (rows == 0 || rows == N + 1)
				{
					lawn[rows][columns][0] = 0;
					lawn[rows][columns][1] = 0;
					lawn[rows][columns][2] = 0;
					lawn[rows][columns][3] = 0;
					lawn[rows][columns][4] = 0;
				}
				else if (columns == 0 || columns == M + 1)
				{
					lawn[rows][columns][0] = 0;
					lawn[rows][columns][1] = 0;
					lawn[rows][columns][2] = 0;
					lawn[rows][columns][3] = 0;
					lawn[rows][columns][4] = 0;
				}
				else
				{
					fin >> height;
					lawn[rows][columns][0] = height;
					lawn[rows][columns][1] = lawn[rows][columns - 1][1] > lawn[rows][columns - 1][0] ? lawn[rows][columns - 1][1] : lawn[rows][columns - 1][0];
					lawn[rows][columns][2] = lawn[rows - 1][columns][2] > lawn[rows - 1][columns][0] ? lawn[rows - 1][columns][2] : lawn[rows - 1][columns][0];
				}
			}
		}

		for (int rows = N; rows > 0; rows--)
		{
			for (int columns = M; columns > 0; columns--)
			{
				lawn[rows][columns][3] = lawn[rows][columns + 1][3] > lawn[rows][columns + 1][0] ? lawn[rows][columns + 1][3] : lawn[rows][columns + 1][0];
				lawn[rows][columns][4] = lawn[rows + 1][columns][4] > lawn[rows + 1][columns][0] ? lawn[rows + 1][columns][4] : lawn[rows + 1][columns][0];
			}
		}

		output = "YES";
		for (int rows = 1; rows < N + 1; rows++)
		{
			for (int columns = 1; columns < M + 1; columns++)
			{
				int current_pos = lawn[rows][columns][0];

				if (current_pos < lawn[rows][columns][1] && current_pos < lawn[rows][columns][2])
				{
					output = "NO";
					break;
				}
				else if (current_pos < lawn[rows][columns][2] && current_pos < lawn[rows][columns][3])
				{
					output = "NO";
					break;
				}
				else if (current_pos < lawn[rows][columns][3] && current_pos < lawn[rows][columns][4])
				{
					output = "NO";
					break;
				}
				else if (current_pos < lawn[rows][columns][4] && current_pos < lawn[rows][columns][1])
				{
					output = "NO";
					break;
				}
			}
			if(output == "NO")
				break;
		}

		fout << "Case #" << i + 1 << ": " << output << endl;
	}

	return 0;
}