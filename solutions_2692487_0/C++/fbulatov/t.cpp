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
#define N 105

Int A[N];

int main()
{
	freopen("i.txt", "rt", stdin);
	freopen("o.txt", "wt", stdout);
	int t, i, n, tt = 0;
	Int a;
	cin >> t;
	while(t--)
	{
		tt++;
		scanf("%lld %d", &a, &n);
		for(i = 0; i < n; i++)
			scanf("%lld", &A[i]);
		sort(A, A + n);
		i = 0;
		int res = inf;
		int cnt = 0;
		while(i < n)
		{
			while(i < n && A[i] < a)
				a += A[i++];
			int R = n - i;
			res = min(res, cnt + R);
			if(i == n)
				break;
			if(a > 1)
			{
				while(A[i] >= a)
					a += (a - 1), cnt++;
			}
			else
				break;
		}
		printf("Case #%d: %d\n", tt, res);
	}
}