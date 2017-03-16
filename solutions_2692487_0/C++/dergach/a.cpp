#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

int a[105];

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		int A, n;
		scanf("%d %d", &A, &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int res = 1234567890;
		int cnt = 0;
		sort(a, a + n);
		if(A == 1)
			res = n;
		else
		{
			for(int i = 0; i < n; i++)
			{
				if(a[i] < A)
					A += a[i];
				else
				{
					res = min(res, cnt + n - i);
					while(a[i] >= A)
					{
						A += A - 1;
						cnt++;
					}
					A += a[i];
				}
			}
			res = min(res, cnt);
		}
		printf("Case #%d: %d\n", t, res);
	}
	return 0;
}