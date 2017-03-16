#pragma comment(linker, "/STACK:500000000")
#include <functional>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <sstream>
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
#define inf 0x3f3f3f3f
#define eps 1e-9
using namespace std;
#define N 10000005

Int sum[N];
char s[30];

bool isPal(Int n)
{
	sprintf(s, "%lld", n);
	int l = 0, r = strlen(s) - 1;
	while(l < r)
	{
		if(s[l++] != s[r--])
			return false;
	}
	return true;
}

bool eq(double a, double b)
{
	return fabs(a - b) < eps;
}

int main()
{
	//freopen("i.txt", "rt", stdin);
	//freopen("o.txt", "wt", stdout);
	for(Int i = 1; i < N; i++)
	{
		Int sq = i * i;
		sum[i] = sum[i - 1] + bool(isPal(i) && isPal(sq));
		if(sum[i] > sum[i - 1])
			i = i;
	}

	int t, tt = 0;
	Int a, b;
	cin >> t;
	while(t--)
	{
		tt++;
		scanf("%lld %lld", &a, &b);
		double q = sqrt(a + .0);
		Int L, R;
		if(eq(q, (Int)(q)))
			L = q;
		else
			L = q + 1;
		R = sqrt(b + .0);
		printf("Case #%d: %lld\n", tt, sum[R] - sum[L - 1]);
	}
}  