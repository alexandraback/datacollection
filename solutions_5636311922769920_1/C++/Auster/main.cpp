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

const string problem = "D-large";



int main()
{
#ifndef _DEBUG
	freopen((problem + ".in").c_str(), "r", stdin);
	freopen((problem + ".out").c_str(), "w", stdout);
#endif
	int t;
	int k, c, s;

	cin >> t;
	
	for (int test_case = 1; test_case <= t; ++test_case)
	{
		cin >> k >> c >> s;
		cout << "Case #" << test_case << ":";

		if (k == 1)
		{
			cout << " 1" << endl;
			continue;
		}

		vector<LL> res;

		LL pos = 1;
		for (int i = 1; i <= k; ++i)
		{
			pos = (pos - 1) * k + i;
			if (i % c == 0)
			{
				res.push_back(pos);
				pos = 1;
			}
		}

		if (k % c != 0)
		{
			for (int i = 0; i < c - k % c; ++i)
				pos *= k;
			res.push_back(pos);
		}

		if (res.size() > s)
			cout << " IMPOSSIBLE";
		else
		{
			for (int i = 0; i < res.size(); ++i)
				cout << " " << res[i];
		}
		cout << endl;

	}

	return 0;
}