#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
int a[10000];
bool dog(int x)
{
	int i, tk, tot, j;
	bool d;
	if (a[n] <= x) return true;
	for (i = 0; i <= a[n]&&i<x; i++)
	{
		tk = x - i;
		tot = 0;
		d = true;
		for (j = 1; j <= n; j++)
		{
			tot += (a[j] - 1) / tk;
			if (tot > i) {
				d = false; 
				break;
			}
		}
		if (d) return true;
	}
	return false;
}
int main()
{
	freopen("111.txt", "r", stdin);
	freopen("222.txt", "w", stdout);
	int ii, tt, i, left, mid, right, ans;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ii++)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		left = 1;
		right = a[n];
		ans = a[n];
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (dog(mid))
			{
				if (mid < ans) ans = mid;
				right = mid - 1;
			}
			else
				left = mid + 1;
		}
		printf("Case #%d: %d\n", ii, ans);
	}
	return 0;
}