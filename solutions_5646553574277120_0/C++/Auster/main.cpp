#pragma comment(linker, "/STACK:134217728")

#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <complex>
#include <memory.h>
#include <time.h>

using namespace std;

typedef long long LL;

int T, C, D, V;
int d[111];

int main()
{
#ifndef _DEBUG
	freopen("C-small-attempt0 (1).in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> T;
	for(int it = 1; it <= T; ++it)
	{
		cin >> C >> D >> V;
		for(int i = 0; i < D; ++i)
			cin >> d[i];
		sort(d, d + D);
		int res = 0;
		LL can = 0;
		int p = 0;
		while (can < V)
		{
			while (p < D && d[p] <= can + 1)
				can += d[p++] * C;
			if (can < V)
			{
				can += (can + 1) * C;
				res++;
			}
		}
		cout << "Case #" << it << ": " << res << endl;
	}
	return 0;
}