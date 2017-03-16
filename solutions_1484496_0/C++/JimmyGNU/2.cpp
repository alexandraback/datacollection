#include<cstdio>
#include<map>
using namespace std;
int n, a[30];
void print (int p)
{
	for (int i = 0; i < n; ++i)
	{
		if ( (1 << i) &p)
		{
			printf ("%d ", a[i]);
		}
	}
	printf ("\n");
	return;
}
int main()
{
	int T;
	scanf ("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		bool flag=true;
		scanf ("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf ("%d", &a[i]);
		}
		printf ("Case #%d:\n", nCase);
		map<int, int> m;
		for (int p = 1; p <= 1 << n; ++p)
		{
			int sum = 0;
			for (int i = 0; i < n; ++i)
			{
				if ( (1 << i) &p)
				{
					sum += a[i];
				}
			}
			if (m.find (sum) == m.end())
			{
				m[sum] = p;
			}
			else
			{
				print (m[sum]);
				print (p);
				p = 1 << n;
				flag = false;
			}
		}
		if (flag)
		{
			printf ("Impossible\n");
		}
	}
	return 0;
}
