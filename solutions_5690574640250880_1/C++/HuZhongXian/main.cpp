#include <cstdlib>
#include <fstream>
#include <sstream>

template <class T> void SWAP(T & a, T  & b) { T t = a; a = b; b = t; }
template <class T> T MAX(T a, T b) { if (a > b) return a; else return b; }
template <class T> T MIN(T a, T b) { if (a < b) return a; else return b; }
template <class T> T ABS(T a) { if (a < 0) return -a; else return a; }

using namespace std;
int main(int argc, char* argv[])
{
	string inputFileName = "C-large.in";
	ifstream input(inputFileName);
	ofstream output(inputFileName + ".out");
	int T, R, C, M;
	char grid[50][50];
	input >> T;
	for (int i = 1; i <= T; ++i)
	{
		input >> R >> C >> M;
		bool ture = false;
		if (R > C)
		{
			SWAP(R, C);
			ture = true;
		}
		bool impossible = false;
		if (R * C - 1 == M)
		{
			grid[0][0] = 'c';
		}
		else if (R == 1 || C == 1)
		{
			memset(grid, '.', sizeof(grid));
			if (M + 1 >= R * C)
			{
				impossible = true;
			}
			else
			{
				for (int m = 0; m < M; ++m)
				{
					grid[0][m] = '*';
				}
				grid[0][C - 1] = 'c';
			}
		}
		else
		{
			memset(grid, '*', sizeof(grid));
			impossible = true;
			for (int r = 2; impossible && r <= R; ++r)
			{
				for (int c = 2; impossible && c <= C; ++c)
				{
					if (r * c + M >= R * C)
					{
						int mine = M - (R * C - r * c);
						int space = MAX(0, c > 2 ? r - 3 : 0) + MAX(0, r > 2 ? c - 3 : 0) + (r > 2 && c > 2);
						if (!(impossible = (mine > space)))
						{
							for (int tr = 0; tr < r; ++tr)
							{
								for (int tc = 0; tc < c; ++tc)
								{
									grid[tr][tc] = '.';
								}
							}
							int tr = r - 1, tc = c - 1;
							while (mine && tc >= 2)
							{
								--mine;
								grid[tr][tc--] = '*';
							}
							tr = r - 2, tc = c - 1;
							while (mine && tr >= 2)
							{
								--mine;
								grid[tr--][tc] = '*';
							}
							grid[0][0] = 'c';
						}
					}
				}
			}
		}

		output << "Case #" << i << ":\n";
		//output << "Row: " << (ture ? C : R) << " Col: " << (ture ? R : C) << " Mine: " << M << " Space: " << R * C - M << endl;
		if (impossible) output << "Impossible\n";
		else
		{
			for (int a = 0; a < (ture ? C : R); ++a)
			{
				for (int b = 0; b < (ture ? R : C); ++b)
				{
					output << (ture ? grid[b][a] : grid[a][b]);
				}
				output << endl;
			}
		}
	}

	output.close();
	input.close();

	//system("pause");
	return 0;
}
