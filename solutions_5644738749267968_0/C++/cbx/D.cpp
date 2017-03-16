#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1111;
int solve(int n,double *a,double *b)
{
	int s=0;
	int i,j;
	j=0;
	for (i=0;i<n;i++)
	{
		for (;j<n;j++)
		{
			if (b[j]>a[i])
			{
				break;
			}
		}
		if (j==n)
		{
			break;
		}
		s++;
		j++;
	}
	return s;
}
int main()
{
	int t,ti;
	scanf("%d",&t);
	for (ti=1;ti<=t;ti++)
	{
		int n;
		scanf("%d",&n);
		static double naomi[N],ken[N];
		int i;
		for (i=0;i<n;i++)
		{
			scanf("%lf",&naomi[i]);
		}
		for (i=0;i<n;i++)
		{
			scanf("%lf",&ken[i]);
		}
		sort(naomi,naomi+n);
		sort(ken,ken+n);
		printf("Case #%d: %d %d\n",ti,solve(n,ken,naomi),n-solve(n,naomi,ken));
	}
	return 0;
}
