#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <map>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
typedef long long ll;

ll P, Q;

int main() 
{
	int n_case = 0;
	scanf("%d", &n_case);
	for (int ca = 1; ca <= n_case; ca++) 
	{
		scanf(" %lld/%lld", &P, &Q);
		int ans = 55, val = 55;
		for (int i = 0; i <= 50; i++)
		{
			if (P == 0)
			{
				ans = i;
				break;
			}
			P = P * 2;
			if (P >= Q)
			{
				P -= Q;
				val = min(val, i + 1);
			}
		}
		if (ans > 40)
		{
			printf("Case #%d: impossible\n", ca);
		}
		else
		{
			printf("Case #%d: %d\n", ca, val);
		}
	}
	return 0;
}
