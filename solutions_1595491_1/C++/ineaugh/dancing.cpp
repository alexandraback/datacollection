#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <bitset>
#include <algorithm>
#include <sstream>

using namespace std;

void SolveCase()
{
	int N, S, p;
	cin >> N >> S >> p;
	vector<int> sums(N);
	for(int i = 0; i < N; ++i)
		cin >> sums[i];

	int simple = 0, potential = 0;
	for(int i = 0; i < N; ++i)
	{
		if(sums[i] % 3 == 0)
		{
			if(sums[i] / 3 >= p)
				++simple;
			else if(sums[i] > 0 && sums[i] / 3 + 1 == p)
				++potential;
		}
		else if(sums[i] % 3 == 2)
		{
			if(sums[i] / 3 + 1 >= p)
				++simple;
			else if(sums[i] / 3 + 2 == p)
				++potential;
		}
		else if(sums[i] / 3 + 1 >= p)
			++simple;
	}

	cout << simple + min(potential, S);
}

void main()
{
	int testCases;
	cin >> testCases;
	for(int i = 0; i < testCases; ++i)
	{
		cout << "Case #" << (i + 1) << ": ";
		SolveCase();
		cout << endl;
	}
}