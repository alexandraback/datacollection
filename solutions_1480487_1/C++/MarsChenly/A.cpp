/*
Author:MarsChenly
Date:2012.05.06
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn(1005);

int a[maxn];
double ans[maxn];
bool del[maxn];

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int task,cases;
	scanf("%d",&task);
//	cout << task << endl;
	for (int cases = 1; cases <= task; cases++)
	{
		int S = 0,n;
		scanf("%d",&n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d",&a[i]);
			S = S + a[i];
		}
		printf("Case #%d:",cases);
		bool flag = true;
		memset(del,0,sizeof(del));
		while (flag)
		{
			flag = false;
			int m = 0,sum = 0;
			for (int i = 1; i <= n; i++)
			{
				if (!del[i]) 
				{
					sum = sum + a[i];
					m++;
				}
			}
			for (int i = 1; i <= n; i++)
			if (!del[i])
			{
				if (a[i] > 1.0 * (S + sum) / m)
				{
					flag = true;
					del[i] = true;
					ans[i] = 0;
					break;
				} else
				{
					ans[i] = (1.0 * (S + sum) / m - a[i]) / S;
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			printf(" %.6lf",100 * ans[i]);
		}
		printf("\n");
	}
	return 0;
}
