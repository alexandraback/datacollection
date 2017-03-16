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

bool doTest()
{
	int X, n, m;
	scanf("%d %d %d", &X, &n, &m);

	if (n > m)
		swap(n, m);

	if (X == 1)
	{
		return false;
	}

	if (X == 2)
	{
		return n * m % 2 == 1;
	}

	if (X == 3)
	{
		return n == 1
			|| n == 2 && m != 3
			|| n == 4;
	}

	if (X == 4)
	{
		return n <= 2
			|| n == 3 && m == 3;
	}

	throw;
}

int main()
{
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		printf("Case #%d: %s\n", test, doTest() ? "RICHARD" : "GABRIEL");
	}
}