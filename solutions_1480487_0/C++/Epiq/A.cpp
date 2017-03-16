#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;

int T, N;
int X = 0;
int x = 0;
int s[200];
double a, m;

int main()
{
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	scanf("%d", &T);
	for (int test = 1; test <= T; test++)
	{
		printf("Case #%d:", test);
		X = 0;
		x = 0;
		int n = 0;
		int t;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &s[i]);
			X += s[i];
		}
		a = 1.0 * X / N;
		for (int i = 0; i < N; i++)
		{
			if (s[i] < 2.0 * a)
			{
				x += s[i];
				n++;
			}
		}
		for (int i = 0; i < N; i++)
		{
			if (s[i] >= 2.0 * a) printf(" %lf", 0.0);
			else printf(" %.6lf", 100.0 * (double(X + x) / n - s[i]) / X);
		}
		printf("\n");
	}
	
	return 0;
}
