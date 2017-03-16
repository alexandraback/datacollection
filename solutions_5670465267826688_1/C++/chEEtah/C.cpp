#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int toQ(char c)
{
	return c - 'i' + 2;
}

int table[5][5] = 
{
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4},
	{0, 2, -1, 4, -3},
	{0, 3, -4, -1, 2},
	{0, 4, 3, -2, -1}
};

int mult(int a, int b)
{
	int aa = abs(a), bb = abs(b);
	int sign = (a / aa) * (b / bb);

	return table[aa][bb] * sign;
}

int nt;
long long L, X;
string s;

int main()
{
	int nt;
 	cin >> nt;
 	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		cin >> L >> X >> s;

		if (X > 12) X = 12 + X % 4;

		assert(L == s.size());

		int n = L * X;

		int prefix = 1;
		int minI = n + 1;
		for(int i = 0; i < n; i++)
		{
			prefix = mult(prefix, toQ(s[i % L]));
			if (prefix == 2) minI = min(minI, i + 1); 
		}

		if (prefix != -1)
		{
			puts("NO");
			continue;
		}

		int suffix = 1;
		int maxK = 0;
		for(int i = 0; i < n; i++)
		{
			suffix = mult(toQ(s[(n - i - 1) % L]), suffix);
			if (suffix == 4) maxK = max(maxK, n - i); 
		}		

		assert(prefix == suffix);
		if (minI < maxK) puts("YES"); else puts("NO");
	}
	return 0;
}