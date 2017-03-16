#include <iostream>
#include <time.h>
using namespace std;
double p[110000];
double a[110000];
void qqsort(int* a, int l, int r)
{
	int i = l, j = r, k;
	int m = a[(i + j) / 2];
	while (i < j)
	{
		while (a[i] < m)
			i++;
		while (a[j] > m)
			j--;
		if (i <= j)
		{
			k = a[i], a[i] = a[j], a[j] = k;
			i++, j--;
		}
	}
	if (i < r)
		qqsort(a, i, r);
	if (j > l)
		qqsort(a, l, j);
}
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int t, n, m, i;
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++)
	{
		memset(a, 0, sizeof(a));
		cin >> n >> m;
		for (i = 1; i <= n; i++)
			cin >> p[i];
		double min = 1e60;
		double p1 = 1;
		for (i = 0; i <= n; i++)
		{
			int front = i;
			int length = (n - i);
			int plength = (m - i);
			double pp = (length + plength + 1) * p1 + (length + plength + 1 + m + 1) * (1 - p1);
			if (pp < min)
				min = pp;
			if (i != n)
				p1 = p1 * p[i + 1];
		}
		if (1 + m + 1 < min)
			min = 1 + m + 1;
		cout << "Case #" << t1 << ": ";
		printf("%.7lf", min);
		cout << "\n";
	}
}