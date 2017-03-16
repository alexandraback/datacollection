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
	string inputFileName = "B-large.in";
	ifstream input(inputFileName);
	ofstream output(inputFileName + ".out");
	int T, D, buf[1010];
	input >> T;
	for (int i = 1; i <= T; ++i)
	{
		input >> D;
		int a = 1, b = -1, ret = 0;
		for (int j = 0; j < D; ++j)
		{
			input >> buf[j];
			ret = MAX(ret, buf[j]);
		}
		b = ret - 1;
		while (a + 2 < b)
		{
			int v[2] = { a + (b - a) / 3, b - (b - a) / 3 };
			int t[2] = { v[0], v[1] };
			for (int j = 0; j < D; ++j)
			{
				t[0] += (buf[j] - 1) / v[0];
				t[1] += (buf[j] - 1) / v[1];
			}
			if (t[0] < t[1])
			{
				b = v[1] - 1;
			}
			else if (t[0] > t[1])
			{
				a = v[0] + 1;
			}
			else
			{
				a = v[0];
				b = v[1];
			}
			ret = MIN(ret, MIN(t[0], t[1]));
		}
		for (int j = a; j <= b; ++j)
		{
			int tmp = j;
			for (int k = 0; k < D; ++k)
			{
				tmp += (buf[k] - 1) / j;
			}
			ret = MIN(ret, tmp);
		}

		output << "Case #" << i << ": " << ret << endl;
	}

	output.close();
	input.close();

	//system("pause");
	return 0;
}
