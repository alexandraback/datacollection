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
	int A, B, C, K;
	input >> A >> B >> C >> K;
	output << A * B * min(K, C);
	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < B; j++)
		{
			for (int k = 0; k < K && k < C; k++)
			{
				output << endl;
				output << (i % A) + 1 << " " << (j % B) + 1 << " " << ((i + j + k) % C) + 1;
			}
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