#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define A first
#define B second

int main()
{
	int i, j, res, N, S, T, p;
	int t[200];
	cin >> T;
	for (int x=1; x<=T; ++x)
	{
		cin >> N >> S >> p;
		for (i=0; i<N; ++i)
			cin >> t[i];
		sort(t, t+N);
		j = S;
		res = 0;
		for (i=N; i--; )
		{
			if (t[i] < 2)
			{
				if (p <= t[i])
					++res;
			}
			else if ((t[i]+2)/3 >= p)
			{
				++res;
			}
			else if (j)
			{
				if ((t[i]+4)/3 >= p)
				{
					++res;
					--j;
				}
				else
					break;
			}
		}
		cout << "Case #" << x << ": " << res << endl;
	}
	return 0;
}
