#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

double pie[2000];
double dru[2000];
int n;
int t;
int d, w;

int main()
{
	scanf("%d", &t);
	for (int h=1; h<=t; h++)
	{
		scanf("%d", &n);
		w=0;
		d=n+1;
		for (int i=1; i<=n; i++)
		{
			cin >> pie[i];
		}
		for (int i=1; i<=n; i++)
		{
			cin >> dru[i];
		}
		printf("Case #%d", h);
		printf(": ");
		sort(pie+1, pie+1+n);
		sort(dru+1, dru+1+n);
		for (int i=1; i<=n; i++)
		{
			w++;
			while(dru[w]<pie[i] && w<=n)
			{
				w++;
			}
			if (w==n)
			{
				w=n-i;
				break;
			}
			if (w>n)
			{
				w=n-i+1;
				break;
			}
		}
		for (int i=n; i>0; i--)
		{
			d--;
			while(dru[d]>pie[i] && d)
			{
				d--;
			}
			if (d==1)
			{
				d=n-i+1;
				break;
			}
			if (!d)
			{
				d=n-i;
				break;
			}
		}
		printf("%d %d\n", d, w);
	}
	return 0;
}
