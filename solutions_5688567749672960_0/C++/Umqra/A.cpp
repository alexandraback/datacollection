#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

const int N = (int)1e7 + 100;
const int INF = (int)1e9 + 100;

int dig[100];
int dist[N];
int q[N];

int reverseNum(int x)
{
	int cntD = 0;
	while (x > 0)
	{
		dig[cntD++] = x % 10;
		x /= 10;
	}
	int value = 0;
	for (int i = 0; i < cntD; i++)
	{
		value *= 10;
		value += dig[i];
	}
	return value;
}

int topQ = 0;
void relax(int v, int d)
{
	if (v < N && dist[v] > d)
	{
		dist[v] = d;
		q[topQ++] = v;
	}
}

void calc()
{
	fill(dist, dist + N, INF);
	q[topQ++] = 1;
	dist[1] = 1;
	for (int i = 0; i < topQ; i++)
	{
		int v = q[i];
		relax(v + 1, dist[v] + 1);
		relax(reverseNum(v), dist[v] + 1);
	}
}

int main()
{
	calc();
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		int n;
		scanf("%d", &n);
		printf("Case #%d: %d\n", i, dist[n]);		
	}
	return 0;
}
