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



int t, n;
char s[N];
bool f(char s)
{
	return (s != 'a' && s != 'e' && s != 'i' && s != 'o' && s != 'u');
}
int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d%*c", &t);
	for(int tt = 1; tt <= t; tt++)
	{
		scanf("%s %d%*c", &s, &n);
		int len = strlen(s);
		int res = 0;
		for(int i = 0; i < len; i++)
			for(int j = i+n-1; j < len; j++)
			{
				int max_v = 0, cnt = 0;
				for(int k = i; k <= j; k++)
					if(f(s[k]))
					{
						cnt = 1;
						for(k++; k <= j && f(s[k]); k++)
							cnt++;
						max_v = max(cnt, max_v);
					}
				if(max_v >= n)
					res++;
			}
		printf("Case #%d: %d\n", tt, res);
	}
	return 0;
}