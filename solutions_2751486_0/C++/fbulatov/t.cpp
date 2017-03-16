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
#include <complex>
#include <map>
#include <set>
#define Int unsigned long long
#define inf 0x3f3f3f3f
#define eps 1e-9
using namespace std;
#define N 1000005

char A[N];
int dp[N];

bool f(char c)
{
	return c != 'a' && c != 'e' && c != 'i' && c !='o' && c != 'u';
}

int main()
{
	freopen("i.txt", "rt", stdin);
	freopen("o.txt", "wt", stdout);
	int t, n, i;
	cin >> t;
	int tt = 0;
	while(t--)
	{
		tt++;
		scanf("%s %d", &A, &n);
		int len = strlen(A);
		dp[0] = f(A[0]);
		Int res = 0;
		for(i = 1; i < len; i++)
		{
			if(f(A[i]))
				dp[i] = dp[i - 1] + 1;
			else
				dp[i] = 0;
		}
		Int last = inf;
		for(i = 0; i < len; i++)
		{
			if(dp[i] < n)
			{
				if(last != inf)
					res += (last + 1);
			}
			else
			{
				last = i - n + 1;
				res += (last + 1);
			}
		}
		printf("Case #%d: %lld\n", tt, res);
	}
} 