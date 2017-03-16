#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

typedef long long i64d;

using namespace std;

int main()
{
	freopen("A-large.in" , "r" , stdin);
	//freopen("input.txt" , "r" , stdin);
	freopen("A-large.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d:" , ca);
		int n;
		int a[300];
		int sum = 0;
		scanf("%d" , &n);
		for (int i = 0; i < n; i ++)
		{
			scanf("%d" , &a[i]);
			sum += a[i];
		}
		double avg = 2.0 * (double)sum / n;
		double p[300];
		int check[300] = {0};
		int num = 0;
		double tot = sum;
		for (int i = 0; i < n; i ++)
		{
			if (avg <= a[i]) {check[i] = 1; p[i] = 0;}
			else {num ++; tot += a[i];}
		}
		if (num > 0) tot = tot / num;
		double tot2 = tot;
		for (int i = 0; i < n; i ++)
			if (check[i] == 0)
			{
				if (num > 0) p[i] = 100.0 * (tot-a[i]) / (double)sum;
				else p[i] = 0;
				//if (tot <= a[i]) {check[i] = 1; p[i] = 0;}
				//else {num ++; tot2 += a[i];}
			}
		/*
		if (num > 0) tot2 = tot2 / num;
		for (int i = 0; i < n; i ++)
			if (check[i] == 0)
			{
				if (num > 0) p[i] = 100.0 * (tot2-a[i]) / (double)sum;
				else p[i] = 0;
			}
		*/
		for (int i = 0; i < n; i ++)
		{
			printf(" %lf" , p[i]);
		}
		printf("\n");
	}
	return 0;
}