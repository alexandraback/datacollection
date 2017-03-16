#include <functional>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <string>
#include <cstdio>
#include <complex>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

#define int64 long long
#define mp make_pair

const int inf = 1e9;

#ifdef _DEBUG
    const int N = 3010;
#else
    const int N = 300010;
#endif

int T, r, c, x;


int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++)
	{
		int x, r, c;
		cin >> x >> r >> c;
		bool f = true;
		int s = r * c;
		if (s % x != 0) f = false;
		else
		{
			if (r < c) swap(r, c);
			if (x < 3) f = true;
			else if (x == 3)
			{
				if (c > 1) f = true;
				else f = false;
			}
			else
			{
				if (r < 4) f = false;
				else 
				{
					if (c < 3) f = false;
					else f = true;
				}
			}
		}
		if (!f) printf("Case #%d: RICHARD\n", ii);
		else printf("Case #%d: GABRIEL\n", ii);
	}
	return 0;
}