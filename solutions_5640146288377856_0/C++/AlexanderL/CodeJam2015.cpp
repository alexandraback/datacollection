// CodeJam2015.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{

//	freopen("A-test.in", "r", stdin);
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test)
	{
		int R, C, W;
		cin >> R >> C >> W;
		int d[30] = { 0 };
		d[0] = W;
		for (int i = 1; i <= C - W; ++i)
		{
			int best = 100000;
			for (int x = 1; x <= min(i, W); ++x)
			{
				int val = max(d[i - x] + 1, d[min(x, W) - 1]);
				if (val < best)
					best = val;
			}
			d[i] = best;
		}
		int res = d[C - W] + (R - 1) * (C / W);
		cout << "Case #" << test << ": " << res << endl;
	}
	return 0;
}

