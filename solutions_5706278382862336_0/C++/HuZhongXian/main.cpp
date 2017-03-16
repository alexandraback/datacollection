#define _CRT_SECURE_NO_DEPRECATE

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

template <class T> void SWAP(T & a, T  & b) { T t = a; a = b; b = t; }
template <class T> T MAX(T a, T b) { if (a > b) return a; else return b; }
template <class T> T MIN(T a, T b) { if (a < b) return a; else return b; }
template <class T> T ABS(T a) { if (a < 0) return -a; else return a; }
template<class T> T gcd(T a, T b) { if (b == 0) return a; else return gcd(b, a % b); }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

using namespace std;
int main(int argc, char* argv[])
{
	string inputFileName = "A-small-attempt0.in";
	ifstream input(inputFileName);
	ofstream output(inputFileName + ".out");
	int T;
	long long P, Q;
	char buf[128];
	input >> T;
	for (int i = 1; i <= T; ++i)
	{
		input >> buf;
		sscanf(buf, "%lld/%lld", &P, &Q);
		long long gys = gcd(P, Q);
		P /= gys;
		Q /= gys;
		int num = 1;
		long long tmp = Q;
		while (tmp && !(tmp % 2))
		{
			tmp >>= 1;
		}
		if (tmp <= 1)
		{
			while ((P << 1) < Q)
			{
				Q >>= 1;
				++num;
			}
		}
		output << "Case #" << i << ": ";
		if (tmp > 1) output << "impossible";
		else output << num;
		output << endl;
	}

	output.close();
	input.close();

	//system("pause");
	return 0;
}
