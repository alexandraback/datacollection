#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

#define FF(i, a, b) for (int i=a; i<=b; i++)
#define FI(i, a, b) for (int i=a; i>=b; i--)
#define MS(f, x) memset(f, x, sizeof(f))
#define INF 1 << 30
#define zero 1e-6

using namespace std;

int n, s;
int a[300];

bool check(int x, double p)
{
	double w = a[x] + p * s;
	double z = p;
	FF(i, 1, n)
	{
		if (i == x) continue;
		if (a[i] < w)
			z += (w - a[i]) / s;		
	}
	
	if (z > 1) return true;
	return false;
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	int ttt;
	scanf("%d", &ttt);
	FF(tt, 1, ttt)
	{
		scanf("%d", &n);
		s = 0;
		FF(i, 1, n)
		{
			scanf("%d", &a[i]);
			s += a[i];
		}
		
		printf("Case #%d:", tt);
		FF(i, 1, n)
		{
			double l = 0, r = 1;
			while (l + 1e-10 < r)
			{
				double mid = (l + r) / 2;
				if (check(i, mid))
					r = mid;
				else
					l = mid;
			}
			
			printf(" %lf", l * 100);
		}
		printf("\n");
	}
		
	return 0;
}
