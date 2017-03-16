#include <iostream>
#include <stack>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define A first
#define B second

int main()
{
	int i, j, k, N, T, res, total;
	pair<int, int> a[3000];
	bool bo[3000];
	pair<int, int> temp;
	bool b;
	
	scanf("%d", &T);
	for (int t=1; t<=T; ++t)
	{
		scanf("%d", &N);
		for (j=0; j<N; ++j)
		{
			scanf("%d %d", &a[j].A, &a[j].B);
			bo[j] = false;
		}
		res = total = 0;
		for (j=N+N; j--; )
		{
			b = false;
			for (k=0; k<N; ++k)
			{
				if (a[k].B <= total)
				{
					b = true;
					i = k;
					break;
				}
				if (b)
				{
					if (a[k].A <= total && a[k].B > a[i].B)
						i = k;
				}
				else
				{
					if (a[k].A <= total)
					{
						b = true;
						i = k;
					}
				}
			}
			if (N==0)
				break;
			if (b)
			{
				if (a[i].B <= total)
				{
					++res;
					if (!bo[i])
						total+=2;
					else
						++total;
					temp = a[i];
					a[i] = a[N-1];
					a[N-1] = temp;
					b = bo[i];
					bo[i] = bo[N-1];
					bo[--N] = b;
				}
				else
				{
					++res;
					++total;
					a[i].A = a[i].B;
					bo[i] = true;
				}
			}
			else
			{
				res = -1;
				break;
			}
		}
		if (res == -1)
			printf("Case #%d: Too Bad\n", t);
		else
			printf("Case #%d: %d\n", t, res);
	}
	return 0;
}
