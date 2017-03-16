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
	string inputFileName = "B-small-attempt0.in";
	ifstream input(inputFileName);
	int T;
	string buf[101];
	input >> T;
	for (int i = 0; i < T; ++i)
	{
		input >> buf[i];
	}
	input.close();
	ofstream output(inputFileName + ".out");
	for (int i = 0; i < T; ++i)
	{
		int cnt = 0;
		char lastCh = '+';
		for (int j = buf[i].size(); j > 0; --j)
		{
			if (lastCh !=buf[i][j - 1])
			{
				lastCh = buf[i][j - 1];
				++cnt;
			}
		}
		output << "Case #" << (i + 1) << ": " << cnt << endl;
	}
	output.close();

	system("pause");
	return 0;
}
