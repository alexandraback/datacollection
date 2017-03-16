#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<math.h>
using namespace std;


int a[2000005] = {0};
int u[(1<<20) + 5] = {0};
int n;
int b[25];
bool found = 0;

int rec(int m)
{
	if(m == 0)
		return 0;
	if(u[m])
		return u[m];

	for(int i = 0; i < n; i++)
	{
		if(m & (1<<i) && !u[m])
		{
			u[m] = b[i] + rec(m ^ (1<<i));
			if(found)
				return -1;

			if(a[u[m]])
			{
				found = 1;
				for(int j = 0; j < n; j++)
				{
					if(m & (1<<j))
						printf("%d ", b[j]);
				}
				printf("\n");
				for(int j = 0; j < n; j++)
				{
					if(a[u[m]] & (1<<j))
						printf("%d ", b[j]);
				}
				printf("\n");
				return 0;
			}
			a[u[m]] = m;
		}
		else if(m & (1<<i))
		{
			rec(m ^ (1<<i));
		}
	}

	return u[m];
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);

	int tt;
	scanf("%d", &tt);
	for(int t = 0; t < tt; t++)
	{
		found = 0;
		scanf("%d", &n);
		memset(a, 0, sizeof(bool) * 2000005);
		memset(u, 0, sizeof(int) * ((1<<20) + 5));

		for(int i = 0; i < n; i++)
		{
			scanf("%d", &b[i]);
		}

		printf("Case #%d:\n", t+1);

		rec((1<<n)-1);

		if(!found)
			printf("Impossible\n");
	}
	

	return 0;
}


