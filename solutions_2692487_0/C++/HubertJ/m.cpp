#include <cstdio>
#include <math.h>
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cassert>
#include <algorithm>

using namespace std;

#define min(x, y) ((x<y) ? x : y)

int actions(int moteSize, vector<int>& v, int startIndex, int endIndex)
{

	int cur = startIndex;
	while (cur <= endIndex && moteSize > v[cur])
	{
		moteSize += v[cur];
		cur++;
	}

	if (cur > endIndex)
		return 0;

	if (cur == endIndex)
		return 1;

	return min( 1 + actions(moteSize+moteSize-1, v, cur, endIndex), min(1 + actions(moteSize, v, cur+1, endIndex), 1 + actions(moteSize, v, cur, endIndex-1)));
}

int main(int argc, char *argv[])
{
	int c, cases;
	cin >> cases;
	
	for(c = 1; c <= cases; c++)
	{
		int A, N;

		cin >> A; 
		cin >> N;

		vector<int> motes(N);

		for (int i = 0; i < N; i++)
		{
			cin >> motes[i];
		}
		sort(motes.begin(), motes.end());		

		int ret;
		if (A == 1)
			ret = N;
		else
			ret = actions(A, motes, 0, N-1);

		cout << "Case #" << c << ": ";
		cout << ret <<"\n";
//		cout << i << '\n';
	}
}

