# include <cstdio>
# include <cmath>
# include <cstring>
# include <string>
# include <vector>
# include <queue>
# include <map>
# include <algorithm>
# include <iostream>

using namespace std;

int c, d, v;
int cd[32];
int tak[32], pos;

bool check (int p, int x)
{
	bool ans = false;
	if (x < 0)
		return false;
	if (x == 0)
		return true;
	if (p == pos)
		return false;
	ans = check (p + 1, x);
	ans |= check (p + 1, x - tak[p]);
	return ans;
}

int main ()
{
	int t, t1, i, p, ans = 0, j = 1;
	scanf ("%d", &t);
	for (t1 = 1; t1 <= t; t1 ++)
	{
		scanf ("%d%d%d", &c, &d, &v);
		ans = 0;
		pos = 0;
		for (i = 1; i <= d; i ++)
		{
			scanf ("%d", &p);
			tak[i - 1] = p;
		}
		pos = d;
		for (j = 1; j <= v; j ++)
			if (!check (0, j))
			{
				ans ++;
				tak[pos ++] = j;
			}
		printf ("Case #%d: %d\n", t1, ans);
	}
	return 0;
}

