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

const string problem = "A-small-attempt0";

int T;
string s;

string dp[1 << 10];

void go(int len)
{
	if (len == 0)
		return;
	string & res = dp[len];
	if (res != "")
		return;
	go(len - 1);
	res = max(s[len - 1] + dp[len - 1], dp[len - 1] + s[len - 1]);
}

int main()
{
#ifndef _DEBUG
	freopen((problem + ".in").c_str(), "r", stdin);
	freopen((problem + ".out").c_str(), "w", stdout);
#endif

	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> s;
		for (int i = 0; i < 1 << 10; ++i)
			dp[i] = "";
		go((int)s.size());
		cout << "Case " << "#" << test_case << ": " << dp[(int)s.size()] << endl;
	}

	return 0;
}
