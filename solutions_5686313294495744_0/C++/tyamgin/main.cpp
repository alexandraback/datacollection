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

#define N 1009

string a[N], b[N];

int main()
{
	int tests, n, i, j;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			cin >> a[i] >> b[i];
		int res = 0;
		for (int mask = 0; mask < (1 << n); mask++)
		{
			int cnt = 0;
			for (i = 0; i < n; i++)
			{
				if (mask & 1 << i)
				{
					cnt++;
					bool ok1 = false, ok2 = false;
					for (j = 0; j < n; j++)
					{
						if (~mask & 1 << j)
						{
							ok1 |= a[j] == a[i];
							ok2 |= b[j] == b[i];
						}
					}
					if (!ok1 || !ok2)
						break;
				}
			}
			if (i == n)
				res = max(res, cnt);

		}
		printf("Case #%d: %d\n", test, res);
	}
}