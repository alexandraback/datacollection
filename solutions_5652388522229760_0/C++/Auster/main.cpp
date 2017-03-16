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

string problem = "A-small-attempt1";

int t, n;

int main()
{
#ifndef _DEBUG
	freopen((problem + ".in").c_str(), "r", stdin);
	freopen((problem + ".out").c_str(), "w", stdout);
#endif
	cin >> t;
	for (int test_case = 1; test_case <= t; ++test_case)
	{
		cin >> n;

		cout << "Case #" << test_case << ": ";
		
		int mask = 0;

		for (int i = 1; i <= 1000; i++)
		{
			int val = i * n;
			while (val)
			{
				mask |= 1 << val % 10;
				val /= 10;
			}
			if (mask == 1023)
			{
				cout << n * i << endl;
				break;
			}
		}

		if (mask != 1023)
			cout << "INSOMNIA" << endl;
	}


	return 0;
}