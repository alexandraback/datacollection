#pragma comment(linker, "/STACK:500000000") 
#include <functional>
#include <algorithm> 
#include <iostream> 
#include <string.h> 
#include <stdlib.h> 
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

int main()
{
	int tests, a, b, k;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		scanf("%d %d %d", &a, &b, &k);
		int res = 0;
		for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
		if ((i & j) < k)
			res++;
		printf("Case #%d: %d\n", test, res);
	}
}