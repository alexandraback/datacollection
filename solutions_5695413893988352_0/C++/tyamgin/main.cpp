#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:500000000") 
#include <functional>
#include <algorithm>
#include <iostream> 
#include <string.h> 
#include <stdlib.h>
#include <complex>
#include <sstream> 
#include <fstream>
#include <numeric>
#include <ctype.h> 
#include <stdio.h> 
#include <bitset>
#include <vector> 
#include <string> 
#include <math.h> 
#include <time.h> 
#include <queue> 
#include <stack> 
#include <list>
#include <map> 
#include <set> 
#define Int long long 
#define INF 0x3F3F3F3F 
#define eps 1e-9
using namespace std;

int main()
{
	int tests;
	scanf("%d", &tests);

	auto each = [&](string s, function<void(string)> fn)
	{
		auto tmp = s;
		function<void(int)> rec = [&](int pos)
		{
			if (pos == s.size())
			{
				fn(s);
				return;
			}
			if (tmp[pos] != '?')
				return rec(pos + 1);
			for (char c = '0'; c <= '9'; c++)
			{
				s[pos] = c;
				rec(pos + 1);
			}
		};
		rec(0);
	};

	for (int test = 1; test <= tests; test++)
	{
		string A, B;
		cin >> A >> B;
		pair<int, pair<string, string> > res = { INF, { "", "" } };
		each(A, [&](string a)
		{
			each(B, [&](string b)
			{
				int aa = atoi(a.c_str());
				int bb = atoi(b.c_str());
				res = min(res, { abs(aa - bb), {a, b} });
			});
		});
		printf("Case #%d: %s %s\n", test, res.second.first.c_str(), res.second.second.c_str());
	}
}