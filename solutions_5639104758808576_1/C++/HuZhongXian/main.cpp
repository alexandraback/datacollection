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
	string inputFileName = "A-large.in";
	ifstream input(inputFileName);
	ofstream output(inputFileName + ".out");
	int T, S_max;
	char buf[1010];
	input >> T;
	for (int i = 1; i <= T; ++i)
	{
		input >> S_max;
		input >> buf;
		int invite = 0;
		for (; invite <= 9; ++invite)
		{
			int num = invite + buf[0] - '0';
			bool valid = true;
			for (int j = 1; j <= S_max && valid; ++j)
			{
				if (num >= 9)
				{
					break;
				}
				else if (num >= j)
				{
					num += (buf[j] - '0');
				}
				else
				{
					valid = false;
				}
			}
			if (valid) break;
		}
		output << "Case #" << i << ": " << invite << endl;
	}

	output.close();
	input.close();

	//system("pause");
	return 0;
}
