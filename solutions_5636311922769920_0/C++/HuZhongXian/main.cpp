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
	string inputFileName = "D-small-attempt1.in";
	ifstream input(inputFileName);
	int T, K[101], C[101], S[101];
	input >> T;
	for (int i = 0; i < T; ++i)
	{
		input >> K[i] >> C[i] >> S[i];
	}
	input.close();
	ofstream output(inputFileName + ".out");
	for (int i = 0; i < T; ++i)
	{
		auto _K = K[i], _C = C[i], _S = S[i];
		output << "Case #" << (i + 1) << ":";
		if (_S * _C >= _K)
		{
			long long kc = 1, val = 0;
			int p = 0;
			bool flag = true;
			for (int j = 0; j < _K; ++j)
			{
				val += kc * j;
				if (++p >= _C)
				{
					output << " " << (val + 1);
					kc = 1;
					val = 0;
					p = 0;
					flag = false;
				}
				else
				{
					kc *= _K;
					++p;
					flag = true;
				}
			}
			if (flag)
			{
				output << " " << (val + 1);
			}
		}
		else
		{
			output << " IMPOSSIBLE";
		}
		output << endl;
	}
	output.close();

	system("pause");
	return 0;
}
