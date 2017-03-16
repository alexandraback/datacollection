#pragma comment (linker, "/STACK:256000000")
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
#include <complex>
#include <bitset>
#include <sstream>
#include <set>
#include <map>

using namespace std;
template <class T> T sqr(T a) { return a * a; }

int a, b;

int solve(int k)
{
	stringstream ss;
	ss << k;
	string s;
	ss >> s;
	int len = s.length();
	set<int> q;
	q.insert(k);
	for (int i = 1; i < len; i++)
		if (s[i] != '0')
		{
			int cur = 0;
			for (int j = 0; j < len; j++)
				cur = cur * 10 + s[(i + j) % len] - '0';
			if (a <= cur && cur <= b)
			{
				if (cur < k)
					return 0;
				q.insert(cur);
			}
		}
	return q.size() * (q.size() - 1) / 2;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int testNum;
	scanf("%d", &testNum);
	for (int testCount = 0; testCount < testNum; testCount++)
	{
		cin >> a >> b;
		int result = 0;
		for (int i = a; i <= b; i++)
			result += solve(i);
		printf("Case #%d: %d\n", testCount + 1, result);
	}
	return 0;
}