#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

unsigned long long poww(unsigned long long k, unsigned long long c)
{
	if (c == 0)
		return 1;
	return k*poww(k, c - 1);
}

int main()
{
	ifstream input;
	ofstream output;
	input.open("input.txt");
	output.open("output.txt");
	int T;
	input >> T;
	for (int cc = 0; cc < T; cc++)
	{
		unsigned long long k, c, s;
		input >> k >> c >> s;
		if (c*s < k)
		{
			output << "Case #" << cc + 1 << ": IMPOSSIBLE" << endl;
			continue;
		}
		unsigned long long pos = 1;
		output << "Case #" << cc + 1 << ":";
		for (unsigned long long i = 0; i < k; i++)
		{
			pos += i * poww( k, (c*k-i-1) % c );
			if ((i + 1) % c == 0 || i + 1 == k)
			{
				output << " " << pos;
				pos = 1;
			}
		}
		output << endl;
	}
}