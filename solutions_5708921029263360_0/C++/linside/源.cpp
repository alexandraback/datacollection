#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("result.txt");
int search(int m,int n,int p,int l,int mx)
{
	int a[11];
	for (int i = 1;i <= 10;i++) a[i] = p;
	for (int i = 1;i <= m;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			for (int k = 1;k <= p;k++)
			{
				if (l == 1)
				{
					int max = -10000, maxp;
					for (int ss = 1;ss <= mx;ss++)
					{
						if (a[ss] > max)
						{
							max = a[ss];
							maxp = ss;
						}
					}
					a[maxp]--;
					fout << maxp << " " << i << " " << j << endl;
				}
				if (l == 2)
				{
					int max = -10000, maxp;
					for (int ss = 1;ss <= mx;ss++)
					{
						if (a[ss] > max)
						{
							max = a[ss];
							maxp = ss;
						}
					}
					a[maxp]--;
					fout << i << " " << maxp << " " << j << endl;
				}
				if (l == 3)
				{
					int max = -10000, maxp;
					for (int ss = 1;ss <= mx;ss++)
					{
						if (a[ss] > max)
						{
							max = a[ss];
							maxp = ss;
						}
					}
					a[maxp]--;
					fout << i << " " << j << " " << maxp << endl;
				}

			}
		}
	}
	return 0;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int j, p, s, k,max;
		cin >> j >> p >> s >> k;
		fout << "Case #" << i << ": ";
		int c,l,a[11];
		if (j*p <= p*s)
		{
			c = j*p;
			l = 3;
			max = s;
		}
		else
		{
			c = p*s;
			l = 1;
			max = j;
		}
		if (j*s < c)
		{
			l = 2;
			max = s;
		}
		if (l == 1)
		{
			if (k > j) k = j;
			fout << p*s*k << endl;
			search(p, s, k, 1, j);
		}
		if (l == 2)
		{
			if (k > p) k = p;
			fout << j*s*k << endl;
			search(j, s, k, 2, p);
		}
		if (l == 3)
		{
			if (k > s) k = s;
			fout << j*p*k << endl;
			search(j, p, k, 3, s);
		}
	}
	system("pause");
	return 0;
}