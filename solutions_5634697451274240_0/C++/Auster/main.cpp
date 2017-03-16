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

string problem = "B-small-attempt0";

int t;

string s;


int main()
{
#ifndef _DEBUG
	freopen((problem + ".in").c_str(), "r", stdin);
	freopen((problem + ".out").c_str(), "w", stdout);
#endif
	cin >> t;
	for (int test_case = 1; test_case <= t; ++test_case)
	{
		cin >> s;

		cout << "Case #" << test_case << ": ";

		int res = 0;

		string ss = "";
		for (int i = 0; i < s.size(); ++i)
			if (ss.empty() || ss.back() != s[i])
				ss += s[i];

		if (ss.back() == '+')
			ss.pop_back();

		
		cout << ss.size() << endl;
	}

	return 0;
}