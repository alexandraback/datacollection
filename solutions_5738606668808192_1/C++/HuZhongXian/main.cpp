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
	int divisors[11];
	for (int i = 2; i <= 10; ++i)
	{
		divisors[i] = i + 1;
	}
	string inputFileName = "C-large.in";
	ifstream input(inputFileName);
	int T, N, J;
	input >> T >> N >> J;
	input.close();
	ofstream output(inputFileName + ".out");
	output << "Case #1:\n";
	for (int i = 0; i < J; ++i)
	{
		string jamcoin(N, '0');
		jamcoin[0] = jamcoin[1] = '1';
		jamcoin[N - 2] = jamcoin[N - 1] = '1';
		for (int j = 0; ; ++j)
		{
			int mask = 1 << j;
			if (mask > i)
			{
				break;
			}
			else
			{
				if (mask & i)
				{
					jamcoin[2 + j * 2] = jamcoin[3 + j * 2] = '1';
				}
			}
		}
		output << jamcoin;
		for (int j = 2; j <= 10; ++j)
		{
			output << ' ' << divisors[j];
		}
		output << endl;
	}
	output.close();

	system("pause");
	return 0;
}
