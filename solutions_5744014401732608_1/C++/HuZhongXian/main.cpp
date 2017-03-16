#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

template <class T> void SWAP(T & a, T  & b) { T t = a; a = b; b = t; }
template <class T> T MAX(T a, T b) { if (a > b) return a; else return b; }
template <class T> T MIN(T a, T b) { if (a < b) return a; else return b; }
template <class T> T ABS(T a) { if (a < 0) return -a; else return a; }

using namespace std;

int main(int argc, char* argv[])
{
	//string inputFileName = "B-small-attempt1.in";
	string inputFileName = "B-large.in";
	ifstream input(inputFileName);
	int T;
	int B[101];
	long long M[101];
	bool mat[51][51];
	input >> T;
	for (int i = 0; i < T; ++i)
	{
		input >> B[i] >> M[i];
	}
	input.close();
	ofstream output(inputFileName + ".out");
	for (int i = 0; i < T; ++i)
	{
		long long maxWay = 1LL << (B[i] - 2);
		long long remain = maxWay - M[i];
		bool possible = (remain >= 0);
		output << "Case #" << (i + 1) << ": " << (possible ? "POSSIBLE\n" : "IMPOSSIBLE\n");
		if (possible)
		{
			memset(mat, 0, sizeof(mat));
			for (int j = 0; j < B[i]; ++j)
			{
				for (int k = j + 1; k < B[i]; ++k)
				{
					mat[j][k] = true;
				}
			}
			long long curWay = MAX(0LL, 1LL << (B[i] - 3));
			int curIndex = 1;
			while ((curIndex < B[i]) && (remain > 0))
			{
				if (remain >= curWay)
				{
					mat[0][curIndex] = false;
					remain -= curWay;
				}
				curWay >>= 1;
				++curIndex;
			}
			for (int j = 0; j < B[i]; ++j)
			{
				for (int k = 0; k < B[i]; ++k)
				{
					output << (mat[j][k] ? 1 : 0);
				}
				output << endl;
			}
		}
	}
	output.close();

	system("pause");
	return 0;
}
