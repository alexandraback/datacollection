//============================================================================
// Name        : AOsmos.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solve(vector<int> &motes, int step, long long A)
{
	if (step == motes.size())
	{
		return 0;
	}
	long long count = 0;
	if (A > 1)
	{
		while (A <= motes[step])
		{
			A += A - 1;
			++count;
		}
	}
	else
	{
		count = 1000000000;
	}
	A += motes[step];
	return min(count + solve(motes, step + 1, A), (long long)motes.size() - step);
}

int main() {
	int T;
	cin >> T;
	for (int caseNum = 1; caseNum <= T; ++caseNum)
	{
		long long A, N;
		cin >> A >> N;
		vector<int> motes(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> motes[i];
		}
		sort(motes.begin(), motes.end());

		long long answer = solve(motes, 0, A);
		cout << "Case #" << caseNum << ": " << answer << endl;
	}
}
