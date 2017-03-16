#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ofstream outFile;
	ifstream inFile;
	inFile.open("input.txt");
	outFile.open("output.txt");

	int T;
	int R,C,M;
	int clears;
	int row, col;
	char **map;

	int mines;
	inFile >> T;
	for (int caseNum = 0; caseNum<T; caseNum++)
	{
		inFile >> R >> C >> M;
		map = new char*[R];
		for (row = 0; row < R; row++)
		{
			map[row] = new char[C];
		}
		outFile << "Case #" << caseNum+1 << ":" << endl;

		clears = R*C - M;
		if (( (R>1 && C>1) && (clears == 2 || clears == 3 || clears == 5 || clears == 7)) || ((R == 2 || C==2) && (clears % 2 == 1) && (clears>1)))
		{
			outFile << "Impossible" << endl;
		}
		else
		{
			mines = 0;
			for (row=0; row < R; row++)
				for (col=0; col<C; col++)
					map[row][col] = '.';

			if (R == 1)
			{
				for (col=0; mines<M; mines++,col++)
				{
					map[0][col] = '*';
				}
				
			}
			else if (clears == 1)
			{

			for (row=0; row < R; row++)
				for (col=0; col<C; col++)
					map[row][col] = '*';

			}
			else
			{

				for (row=0; row<R-2 && mines < M; row++)
				{
					for (col=0; col<C && mines < M; col++)
					{
						map[row][col] = '*';
						mines++;
					}
				}
				col--;
				row--;
				if (mines==M)
				{
					if (col == C-2)
					{
						map[row][col] = '.';
						map[row+1][0] = '*';
						if (row == R-3)
						{
							map[row][col-1] = '.';
							map[row+2][0] = '*';
						}
					}
				}
				else
				{
					for (col = 0; mines<M; col++, mines+=2)
					{
						map[R-1][col] = '*';
						map[R-2][col] = '*';
					}
					if (mines>M)
					{
						map[R-1][col] = '*';
						map[R-2][col] = '*';
						map[R-3][C-1] = '.';
						map[R-3][C-2] = '.';
						map[R-3][C-3] = '.';
					}
				}
			}
			map[R-1][C-1] = 'c';
			for (row=0; row<R; row++)
			{
				for (col=0; col<C; col++)
				{
					outFile << map[row][col];
				}
				outFile << endl;
			}

		}

	}

	return 0;
}