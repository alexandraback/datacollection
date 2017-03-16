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
#include <regex>
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
		int K, C, S;
		scanf("%d %d %d", &K, &C, &S);
		Int ex = 1;
		for (int i = 0; i < C - 1; i++)
			ex *= K;
		printf("Case #%d:", test);
		Int e = 1;
		for (int i = 0; i < S; i++)
		{
			printf(" %I64d", e);
			e += ex;
		}
		puts("");
	}

}