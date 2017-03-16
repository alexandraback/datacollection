#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:500000000") 
#include <functional>
#include <algorithm>
#include <iostream> 
#include <string.h> 
#include <stdlib.h>
#include <complex>
#include <sstream> 
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
	for (int test = 1; test <= tests; test++)
	{
		Int n;
		scanf("%I64d", &n);
		set<int> s;
		Int res = -1;
		for (int it = 1; it <= 10000000; it++)
		{
			Int a = n * it;
			for (Int i = a; i > 0; i /= 10)
				s.insert(i % 10);
			if (s.size() == 10)
			{
				res = a;
				break;
			}
		}
		printf("Case #%d: ", test);
		if (res == -1)
			puts("INSOMNIA");
		else
			printf("%I64d\n", res);
	}
}