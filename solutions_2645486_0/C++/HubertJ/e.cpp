#include <cstdio>
#include <math.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <cassert>

using namespace std;

int getMax(int maxE, int E, int R, int N, int* values)
{
	int max = 0;

	if (N == 0)
		return 0;

	if (E == 0)
		return 0;

	for(int i = 0; i <= E; i++)
	{
		int nextE = E-i+R;
		nextE = (maxE < nextE) ? maxE : nextE;
		int gain = values[0]*i + getMax(maxE, nextE, R, N-1, values+1);
		max = (gain > max) ? gain : max;
	}

	//cout << "max for E: " << E << " N: " << N << " value: " << values[0] << "\n";
	return max;
}

int main(int argc, char *argv[])
{
	int c, cases;
	cin >> cases;
	
	for(c = 1; c <= cases; c++)
	{
		unsigned int E, R, N;
		cin >> E;
		cin >> R;
		cin >> N;

		int values[N];
		for(int i = 0; i < N; i++)
		{
			cin >> values[i];
		}

		cout << "Case #" << c << ": ";
		cout << getMax(E, E, R, N, values) << "\n";
	}
}

