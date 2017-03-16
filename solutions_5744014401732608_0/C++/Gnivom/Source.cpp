#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <fstream>
#include <set>
#include <tuple>
#include <queue>

using namespace std;

ifstream input;
ofstream output;

long long poww(long long base, long long exp)
{
	if (exp == 0)
		return 1;
	return poww(base,exp-1) * base;
}


void solve()
{
	int B, M;
	input >> B >> M;
	if (poww(2, B - 2) < M)
	{
		output << "IMPOSSIBLE";
		return;
	}

	output << "POSSIBLE";

	for (int i = 0; i < B; i++)
	{
		output << endl;
		for (int j = 0; j < B; j++)
		{
			if (i > 0)
			{
				output << (i < j ? 1 : 0);
				continue;
			}
			if (j == 0)
			{
				output << 0;
				continue;
			}
			if (M == poww(2, B - 2))
			{
				output << 1;
				continue;
			}
			if (j == B - 1)
			{
				output << 0;
				continue;
			}
			output << (M / poww(2, B - j - 2)) % 2;
		}
	}
}

int main()
{
	input.open("input.txt");
	output.open("output.txt");
	int T;
	input >> T;
	for (int cc = 0; cc < T; cc++)
	{
		output << "Case #" << cc + 1 << ": ";
		solve();
		output << endl;
	}
	input.close();
	output.close();
}