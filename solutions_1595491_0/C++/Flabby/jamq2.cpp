#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 110;
int n, s, p;
int a[MAXN];

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("1.out", "w", stdout);

	int csnum;
	int cs;
	int cnt;

	scanf ("%d", &csnum);
	for (cs = 1; cs <= csnum; cs++)
	{
		scanf ("%d %d %d", &n, &s, &p);
		
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			int k;
			scanf ("%d", &k);
			
			if (k >= 3 * p - 2)
				cnt++;
			else
			{
				if (((p != 1 && k >= 3 * p - 4)
						|| (p == 1 && k >= 1))
					&& s > 0)
				{
					s--;
					cnt++;
				}
			}
		}
		printf ("Case #%d: %d\n", cs, cnt);
	}

	return 0;
}
