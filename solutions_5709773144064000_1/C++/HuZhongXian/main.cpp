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
	int T;
	double C, F, X;
	input >> T;
	for (int i = 1; i <= T; ++i)
	{
		input >> C >> F >> X;
		double res = X * 0.5;
		double prevCTime = 0.0;
		double curC = 2.0;
		for (int i = 0; i <= X; ++i)
		{
			res = MIN(res, prevCTime + X / curC);
			prevCTime += C / curC;
			curC += F;
		}
		stringstream ss;
		ss.precision(std::numeric_limits<double>::digits10);
		ss << res;
		output << "Case #" << i << ": " << ss.str() << endl;
	}

	output.close();
	input.close();

	//system("pause");
	return 0;
}
