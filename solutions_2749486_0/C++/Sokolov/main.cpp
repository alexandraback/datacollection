#pragma comment(linker, "/STACK:500000000")
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define y0 y123
#define y1 y1234
#define ll long long
#define PI 3.1415926535897932384626433832795
#define EPS 1e-9
#define INF 2147483647
#define N 1000005
#define M 26

int gcd(int a, int b) { return (!b) ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a,b) * b; }

int t, x, y;
int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &t);
	for(int tt = 1; tt <= t; tt++)
	{
		scanf("%d %d", &x, &y);
		printf("Case #%d: ", tt);
		if(x != 0)
		{
			if(x > 0)
				for(int i = 0; i < 2*x-1; i++)
				{
					if(i % 2 == 0) printf("E");
					else printf("W");
				}
			
			else
			{
				x = -x;
				for(int i = 0; i < 2*x-1; i++)
				{
					if(i % 2 == 0) printf("W");
					else printf("E");
				}
			}
		}
		if(y != 0)
		{
			if(y > 0)
				for(int i = 0; i < 2*y; i++)
				{
					if(i % 2 == 0) printf("S");
					else printf("N");
				}
			else
			{
				y = -y;
				for(int i = 0; i < 2*y; i++)
				{
					if(i % 2 == 0) printf("N");
					else printf("S");
				}
			}
		}
		printf("\n");		
	}
	return 0;
}