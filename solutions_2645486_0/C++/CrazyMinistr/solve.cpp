// #pragma comment(linker, "/STACK:36777216")
#include <set>
#include <map>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstddef>
#include <sstream>
#include <string.h>
#include <iostream>
#include <algorithm>

#define LL long long

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0 ? -x : x; }

using namespace std;
#define N 1000

int a[N];
LL f[1000][N];

int main()
{
//*
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
//*/
	int T;
	cin>> T;
	for (int test = 1; test <= T; test++)
	{
		int e, r, n;
		cin>> e>> r>> n;
		for (int i = 0; i < n; i++)
			cin>> a[i];
		if (r >= e)
		{
			LL ans = 0;
			for (int i = 0; i < n; i++)
				ans += (LL) a[i] * e;

			cout<< "Case #"<< test<< ": "<< ans<< endl;
		}
		else
		{
			memset(f, 0, sizeof(f));
			for (int i = 0; i <= e; i++)
				f[0][i] = (LL) a[0] * (e - i);

			for (int i = 0; i < n - 1; i++)
			{
				for (int j = 0; j <= e; j++)
				{
					for (int k = 0; k <= j + r && k <= e; k++)
					{
						int ee = min(e, j + r);
						f[i + 1][k] = max(f[i + 1][k], f[i][j] + (LL) (ee - k) * a[i + 1]);
					}
				}
			}
			cout<< "Case #"<< test<< ": "<< f[n - 1][0]<< endl;
		}
	}
	return 0;
}
