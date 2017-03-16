#pragma comment(linker, "/STACK:134217728")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <complex>
#include <functional>
#include <cmath>
#include <time.h>

using namespace std;

typedef long long LL;

const string problem = "B-small-attempt0";

int T;
int h[2501];

int main()
{
#ifndef _DEBUG
	freopen((problem + ".in").c_str(), "r", stdin);
	freopen((problem + ".out").c_str(), "w", stdout);
#endif
	cin >> T;
	int n;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		memset(h, 0, sizeof(h));
		cin >> n;
		for (int i = 0; i < 2 * n - 1; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int x;
				cin >> x;
				h[x] ^= 1;
			}
		}
		cout << "Case #" << test_case << ":";
		for (int i = 0; i <= 2500; ++i)
			if (h[i])
				cout << " " << i;
		cout << endl;
	}

	

	return 0;
}
