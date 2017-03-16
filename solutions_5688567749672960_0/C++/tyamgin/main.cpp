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

#define N 1000009

int d[N];
char buf[22];

Int Reverse(Int n)
{
	sprintf(buf, "%lld", n);
	reverse(buf, buf + strlen(buf));
	return atoll(buf);
}

int main()
{
	int tests;
	Int n;
	queue<int> q;
	q.push(1);
	memset(d, 63, sizeof(d));
	d[1] = 1;
	while (q.size())
	{
		int v = q.front();
		q.pop();
		vector<Int> nx = { v + 1, Reverse(v) };
		for (auto to : nx)
		{
			if (to >= N)
				continue;
			if (d[to] == INF)
			{
				d[to] = d[v] + 1;
				q.push(to);
			}
		}
	}
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		Int n;
		scanf("%lld", &n);
		printf("Case #%d: %d\n", test, d[n]);
	}
}