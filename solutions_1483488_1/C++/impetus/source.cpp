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
	int p = k / 10;
	int ten = 1;
	int len = 1;
	while (p)
		ten *= 10, p /= 10, len++;
	set<int> q;
	q.insert(k);
	int cur = k;
	for (int i = 1; i < len; i++)
	{
		cur = cur / ten + cur % ten * 10;
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