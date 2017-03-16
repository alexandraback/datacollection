#define _CRT_SECURE_NO_WARNINGS
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

int solve(int n, int m, int w)
{
	int res = 0, i, j;
	for (i = 1; i < n; i++)
		res += m / w;
	while (m >= 2 * w)
		res++, m -= w;
	return res + w + (w < m);
}

int main()
{
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		int n, m, w;
		scanf("%d %d %d", &n, &m, &w);
		printf("Case #%d: %d\n", test, solve(n, m, w));
	}
}