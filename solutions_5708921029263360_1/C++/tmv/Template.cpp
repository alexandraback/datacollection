#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>      // For greater<int>()
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <sstream>
using namespace std;

// Fashon Police

static void HandleCase(const int cse)
{
	int J, P, S, K;
	cin >> J >> P >> S >> K;

	int count = 0;
	int minJ = min(J, K*S);
	int minP = min(P, K*S);
	int minS = min(S, K);
	cout << "Case #" << cse << ": " << minJ *minP*minS << endl;

	for (int j = 1; j <= minJ; ++j)
	{
		for (int p = 1; p <= minP; ++p)
		{
			for (int s = 1; s <= minS; ++s)
			{
				int ss = ((s + j - 1 + p - 1 - 1) % S) + 1;
				cout << j << " " << p << " " << ss << endl;
			}
		}
	}
}


int main()
{
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);

	//freopen("C-small-attempt0.in", "r", stdin);
	//freopen("C-small-attempt0.out", "w", stdout);

	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);

	int T;
	cin >> T;

	//string str;
	//getline(cin, str, '\n');

	for (int i = 0; i < T; ++i)
		HandleCase(i + 1);

	return 0;
}


