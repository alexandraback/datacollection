#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string PROG = "D-large";
FILE *fin, *fout;

int t, n;
double a[1000], b[1000];
int ans1, ans2;

void qsort(double *a, int l, int r)
{
	int i, j;
	double x, t;
	i = l;
	j = r;
	x = a[(l + r) >> 1];
	do
	{
		while (a[i] < x) i++;
		while (x < a[j]) j--;
		if (i <= j)
		{
			t = a[i]; a[i] = a[j]; a[j] = t;
			i++; j--;
		}
	} while (i <= j);
	if (l < j) qsort(a, l, j);
	if (i < r) qsort(a, i, r);
}

int main()
{
	fin = fopen((PROG + ".in").c_str(), "r");
	fout = fopen((PROG + ".out").c_str(), "w");
	
	int i, j, k, p, q;
	fscanf(fin, "%d", &t);
	for (k = 1; k <= t; k++)
	{
		fscanf(fin, "%d", &n);
		for (i = 0; i < n; i++)
			fscanf(fin, "%lf", a + i);
		for (i = 0; i < n; i++)
			fscanf(fin, "%lf", b + i);
		
		qsort(a, 0, n - 1);
		qsort(b, 0, n - 1);
		
		ans1 = 0;
		p = n - 1;
		for (i = n - 1; i >= 0; i--)
		{
			if (a[i] > b[p])
			{
				ans1++;
			}
			else
			{
				p--;
			}
		}
		
		ans2 = 0;
		p = 0;
		q = n - 1;
		for (i = 0; i < n; i++)
		{
			if (a[i] < b[p])
			{
				q--;
			}
			else
			{
				p++;
				ans2++;
			}
		}
		fprintf(fout, "Case #%d: %d %d\n", k, ans2, ans1);
	}
	return 0;
}