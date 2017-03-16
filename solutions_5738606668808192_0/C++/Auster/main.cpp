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

string problem = "C";

int t;

string s;

const int N = 16;

LL prime(LL x)
{
	for (LL i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return i;
	return 0;
}

bool check(int x, vector<LL> & v)
{
	for (int p = 2; p <= 10; ++p)
	{
		LL y = 0;
		LL pw = 1;
		for (int i = 0; i < N; ++i)
		{
			if (x & (1 << i))
				y += pw;
			pw *= p;
		}
		LL d = prime(y);
		if (d == 0)
			return 0;
		v.push_back(d);
	}
	return 1;
}

string bin(int x)
{
	string res = "";
	while (x)
	{
		res += '0' + (x & 1);
		x /= 2;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
#ifndef _DEBUG
	freopen((problem + ".in").c_str(), "r", stdin);
	freopen((problem + ".out").c_str(), "w", stdout);
#endif

	vector<string> s;
	vector<vector<LL>> div;

	int res = 0;
	for (int i = (1 << (N - 1)) + 1; i < 1 << N; i += 2)
	{
		vector<LL> v;
		if (check(i, v))
		{
			s.push_back(bin(i));
			div.push_back(v);
		}
		if (s.size() == 50)
			break;
	}

	cout << "Case #1:" << endl;
	for (int i = 0; i < s.size(); ++i)
	{
		cout << s[i];
		for (int j = 0; j < div[i].size(); ++j)
			cout << " " << div[i][j];
		cout << endl;
	}

	return 0;
}