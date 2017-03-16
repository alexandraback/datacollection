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

#define N 1009

char s[N];

int main()
{
	int tests, n, i;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		scanf("%d %s", &n, s);
		int res = 0,
			cnt = 0;
		for (i = 0; i <= n; i++)
		{
			if (cnt < i)
			{
				res += i - cnt;
				cnt = i;
			}
			cnt += s[i] - '0';
		}
		printf("Case #%d: %d\n", test, res);
	}
}