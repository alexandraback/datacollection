#include <cstdlib>
#include <fstream>
#include <sstream>

template <class T> void SWAP(T & a, T  & b) { T t = a; a = b; b = t; }
template <class T> T MAX(T a, T b) { if (a > b) return a; else return b; }
template <class T> T MIN(T a, T b) { if (a < b) return a; else return b; }
template <class T> T ABS(T a) { if (a < 0) return -a; else return a; }

const int k_TargetMask = (1 << 10) - 1;
long long findLastSheep(long long v)
{
	if (v == 0) return -1;
	long long ret = v;
	int mask = 0;
	while (true)
	{
		long long tmp = ret;
		while (tmp)
		{
			mask |= (1 << (tmp % 10));
			tmp /= 10;
		}
		if (mask == k_TargetMask)
		{
			break;
		}
		ret += v;
	}
	return ret;
}

using namespace std;
int main(int argc, char* argv[])
{
	string inputFileName = "A-large.in";
	ifstream input(inputFileName);
	int T, buf[101];
	input >> T;
	for (int i = 0; i < T; ++i)
	{
		input >> buf[i];
	}
	input.close();
	ofstream output(inputFileName + ".out");
	for (int i = 0; i < T; ++i)
	{
		auto ret = findLastSheep(buf[i]);
		output << "Case #" << (i + 1) << ": ";
		if (ret == -1)
		{
			output << "INSOMNIA";
		}
		else
		{
			output << ret;
		}
		output << endl;
	}
	output.close();

	system("pause");
	return 0;
}
