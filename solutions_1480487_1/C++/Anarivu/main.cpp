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


int t;

int n;
double s;
int a[205];

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	scanf("%d", &t);

	for(int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);

		s = 0;
		double p;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			s += a[i];
		}
		p = 2*s / n;
		double s2 = 0;

		int cnt = 0;
		for(int i = 0; i < n; i++)
		{
			if(a[i] < p)
				cnt++;
			else s2 += a[i];
		}

		p = (2*s - s2) / cnt;


		printf("Case #%d: ", tt+1);
		for(int i = 0; i < n; i++)
		{
			if(a[i] > p)
				printf("0.000000 ");
			else
				printf("%.7lf ", 100 * (p -a[i]) / s);
		}
		printf("\n");
	}


	return 0;
}


