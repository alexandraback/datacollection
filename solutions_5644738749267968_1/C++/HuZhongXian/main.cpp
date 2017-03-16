#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>

template <class T> void SWAP(T & a, T  & b) { T t = a; a = b; b = t; }
template <class T> T MAX(T a, T b) { if (a > b) return a; else return b; }
template <class T> T MIN(T a, T b) { if (a < b) return a; else return b; }
template <class T> T ABS(T a) { if (a < 0) return -a; else return a; }

using namespace std;
int main(int argc, char* argv[])
{
	string inputFileName = "D-large.in";
	ifstream input(inputFileName);
	ofstream output(inputFileName + ".out");
	int T, N;
	char buf[16];
	string weighs[2][1000];
	bool mark[1000];
	input >> T;
	for (int i = 1; i <= T; ++i)
	{
		input >> N;
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				input >> buf;
				weighs[j][k] = buf;
			}
			sort(weighs[j], weighs[j] + N);
		}
		int y = 0, z = 0;
		memset(mark, true, sizeof(mark));
		for (int j = 0; j < N; ++j)
		{
			bool search = true;
			int firstIndex = -1;
			for (int k = 0; search && k < N; ++k)
			{
				if (mark[k])
				{
					if (firstIndex == -1)
					{
						firstIndex = k;
					}
					if (weighs[1][k] > weighs[0][j])
					{
						search = false;
						mark[k] = false;
					}
				}
			}
			if (search)
			{
				++z;
				mark[firstIndex] = false;
			}
		}
		for (int j = 0, lI = 0, rI = N - 1; j < N; ++j)
		{
			if (weighs[0][j] > weighs[1][lI])
			{
				++y;
				mark[lI++] = false;
			}
			else
			{
				mark[rI--] = true;
			}
		}

		output << "Case #" << i << ": " << y << ' ' << z << endl;
	}

	output.close();
	input.close();

	//system("pause");
	return 0;
}
