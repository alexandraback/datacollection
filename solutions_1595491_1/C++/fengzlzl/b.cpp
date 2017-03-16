#include <stdio.h>
#include <algorithm>

using namespace std;

int a[1000];
int n, s, p;

int main()
{
	freopen("bin.txt", "r", stdin);
	freopen("bout.txt", "w", stdout);
	int T, i, tot, highest, cas=0;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &s, &p);
		for (i=0; i<n; i++)
		  scanf("%d", &a[i]);
		sort(a, a+n);
		int ans = 0;
		for (i=n-1; i>=0; i--)
		{
			tot = a[i];
			if (tot % 3 == 0) highest = tot / 3;
			else highest = tot / 3 + 1;
			if (highest>=p) ans++;
			else if (s>0 && tot % 3 != 1)
			{
				if (tot % 3 == 0)
				{
				 	if (tot>0) highest = tot / 3+1;
				}
				else highest = tot / 3 + 2;
				if (highest>=p)
				{
					ans++;
					s--;
				}
			}
		}
		printf("Case #%d: %d\n", ++cas, ans);
	}
	return 0;
}