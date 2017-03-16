#pragma comment(linker, "/STACK:500000000") 
#include <functional>
#include <algorithm> 
#include <iostream> 
#include <string.h> 
#include <stdlib.h>
#include <limits.h>
#include <numeric>
#include <sstream> 
#include <fstream>
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
typedef pair<int, int> pii;

char table[128][128];

struct Quaternion
{
	char ch;

	Quaternion(char c = '1') : ch(c)
	{
	}

	Quaternion operator *(const Quaternion &b) const
	{
		int sign = 1;
		if (ch < 0)
			sign *= -1;
		if (b.ch < 0)
			sign *= -1;
		return Quaternion(sign * table[abs(ch)][abs(b.ch)]);
	}

	bool operator ==(const Quaternion &b) const
	{
		return ch == b.ch;
	}
};

#define N 10009

char s[N]; 
Quaternion a[N], Le[N], Ri[N];

bool doTest()
{
	int L, X, i, k;
	scanf("%d %d %s", &L, &X, s);
	Quaternion I('i'), J('j'), K('k');
	for (i = 0; i < L; i++)
	{
		for (int x = 0; x < X; x++)
			a[x * L + i + 1] = s[i];
	}
	int n = L * X;
	Ri[n + 1] = Le[0] = Quaternion('1');
	for (i = 1; i <= n; i++)
		Le[i] = Le[i - 1] * a[i];
	for (i = n; i >= 1; i--)
		Ri[i] = a[i] * Ri[i + 1];

	if (!(Le[n] == I*J*K))
		return false;

	for (i = 1; i <= n - 2; i++)
	{
		if (Le[i] == I)
		{
			for (k = i + 2; k <= n; k++)
			{
				if (Ri[k] == K)
					return true;
			}
		}
	}
	return false;
}

int main()
{
	table['1']['1'] = '1';
	table['1']['i'] = 'i';
	table['1']['j'] = 'j';
	table['1']['k'] = 'k';

	table['i']['1'] = 'i';
	table['i']['i'] = -'1';
	table['i']['j'] = 'k';
	table['i']['k'] = -'j';

	table['j']['1'] = 'j';
	table['j']['i'] = -'k';
	table['j']['j'] = -'1';
	table['j']['k'] = 'i';

	table['k']['1'] = 'k';
	table['k']['i'] = 'j';
	table['k']['j'] = -'i';
	table['k']['k'] = -'1';

	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		printf("Case #%d: %s\n", test, doTest() ? "YES" : "NO");
	}
}