#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <cstdio>

using namespace std;

void solveCase(int t)
{
	unsigned int A, B, K;
	cin >> A >> B >> K;

	int pairs = 0;
	for (int a = 0; a < A; ++a)
	{
		for (int b = 0; b < B; ++b)
		{
			if ((a & b) < K)
				++pairs;
		}
	}
	cout << pairs;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{	
		cout << "Case #" << t << ": ";
        solveCase(t);
        cout << endl;
	}
	
	return 0;
}