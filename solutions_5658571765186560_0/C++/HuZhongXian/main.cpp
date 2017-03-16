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
	string inputFileName = "D-small-attempt2.in";
	ifstream input(inputFileName);
	ofstream output(inputFileName + ".out");
	int T, X, R, C;
	input >> T;
	for (int i = 1; i <= T; ++i)
	{
		input >> X >> R >> C;

		//output << X << ' ' << R << ' ' << C << endl;

		if (R > C)
		{
			SWAP(R, C);
		}

		if ((R * C) % X)
		{
			output << "Case #" << i << ": " << "RICHARD" << endl;
			continue;
		}

		if (X <= 2)
		{
			output << "Case #" << i << ": " << "GABRIEL" << endl;
			continue;
		}

		if (X > C || X >= 7)
		{
			output << "Case #" << i << ": " << "RICHARD" << endl;
			continue;
		}

		if (X == 3)
		{
			if (R == 1)
			{
				output << "Case #" << i << ": " << "RICHARD" << endl;
			}
			else
			{
				output << "Case #" << i << ": " << "GABRIEL" << endl;
			}
			continue;
		}

		if (X == 4)
		{
			if (R <= 2)
			{
				output << "Case #" << i << ": " << "RICHARD" << endl;
			}
			else
			{
				output << "Case #" << i << ": " << "GABRIEL" << endl;
			}
			continue;
		}

		if (X == 5)
		{
			if (R <= 2)
			{
				output << "Case #" << i << ": " << "RICHARD" << endl;
			}
			else
			{
				output << "Case #" << i << ": " << "GABRIEL" << endl;
			}
			continue;
		}

		if (X == 6)
		{
			if (R <= 3)
			{
				output << "Case #" << i << ": " << "RICHARD" << endl;
			}
			else
			{
				output << "Case #" << i << ": " << "GABRIEL" << endl;
			}
			continue;
		}
	}

	output.close();
	input.close();

	//system("pause");
	return 0;
}
