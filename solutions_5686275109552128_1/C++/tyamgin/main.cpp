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

int solve(vector<int> a)
{
	int res = INF;
	for (int maxH = 1; maxH <= 1009; maxH++)
	{
		int cnt = 0;
		for (auto i : a)
		{
			if (i > maxH)
				cnt += (i - 1) / maxH;
		}
		res = min(res, maxH + cnt);
	}
	return res;
}

int main()
{
	int tests, n, i;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		scanf("%d", &n);
		vector<int> a(n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		printf("Case #%d: %d\n", test, solve(a));
	}
}