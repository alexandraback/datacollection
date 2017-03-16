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

int n, s, p;
int t[140];

int solve(int a, int surp)
{
	if (surp && (a < 2 || a > 28))
		return 0;
	if (surp)
	{
		if (a % 3 <= 1)
			return a / 3 + 1 >= p;
		return a / 3 + 2 >= p;
	}
	else
	{
		if (a % 3 == 0)
			return a / 3 >= p;
		return a / 3 + 1 >= p;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int testNum;
	scanf("%d", &testNum);
	for (int testCount = 0; testCount < testNum; testCount++)
	{
		cin >> n >> s >> p;
		for (int i = 0; i < n; i++)
			cin >> t[i];
		int result = 0;
		sort(t, t + n);
		for (int i = 0; i < n; i++)
			if (solve(t[i], 0))
				result++;
			else if (s && solve(t[i], 1))
			{
				result++;
				s--;
			}
		printf("Case #%d: %d\n", testCount + 1, result);
	}
	return 0;
}