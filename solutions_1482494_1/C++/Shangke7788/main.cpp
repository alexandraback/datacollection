#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <math.h>

using namespace std;

#define N 1005
int n, sum, x, uu;
int inf = 10005;
int a[N][2];
bool vis[N][2];

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, ca=1;
	scanf("%d", &T);
	while (T --)
	{
		bool flag = true;
		scanf("%d", &n);
		for ( int i=0; i<n; i++)
		{
			scanf("%d%d", &a[i][0], &a[i][1]);
			vis[i][0] = vis[i][1] = 0;
		}
		sum = 0; x = n; uu = 0;
		while (x)
		{
			int t = inf, k = 0;
			uu ++;
			for ( int j=0; j<n; j++)
			{
				if (!vis[j][1] && t > a[j][1])
				{
					t = a[j][1];
					k = j;
				}
			}
			if (a[k][1] <= sum)
			{
				if (vis[k][0])
					sum ++;
				else
					sum += 2;
				vis[k][1] = 1;
				x --;
				continue;
			}
			t = 0; k = -1;
			for ( int j=0; j<n; j++)
			{
				if (!vis[j][1] && !vis[j][0] && a[j][0] <= sum && t < a[j][1])
				{
					t = a[j][1];
					k = j;
				}
			}
			if (k != -1)
			{
				vis[k][0] = 1;
				sum ++;
				continue;
			}
			flag = false;
			break;
		}
		printf("Case #%d: ", ca++);
		if (flag)
			printf("%d\n", uu);
		else
			printf("Too Bad\n");
	}
	return 0;
}

