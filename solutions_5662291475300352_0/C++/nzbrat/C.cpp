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

int n;

double st[4], sp[4], useless;

int main ()
{
	int t, t1, i;
	double len, tm;
	scanf ("%d", &t);
	for (t1 = 1; t1 <= t; t1 ++)
	{
		scanf ("%d", &n);
		for (i = 1; i <= n; i ++)
			scanf ("%lf%lf%lf", &st[i], &useless, &sp[i]);
		
		printf ("Case #%d: ", t1);
		
		if (n == 1)
		{
			printf ("0\n");
			continue;
		}
		if (st[2] > st[1])
		{
			swap (st[1], st[2]);
			swap (sp[1], sp[2]);
		}
		
		len = 360.0 - st[1];
		tm = (len * sp[1]) / 360.0;
		
		
		if (st[2] + (tm * 360.0) / sp[2] >= 720.0)
		{
			printf ("1\n");
			continue;
		}
		
		len = 360.0 - st[2];
		tm = (len * sp[2]) / 360.0;
		
		if (st[1] + (tm * 360.0) / sp[1] >= 720.0)
		{
			printf ("1\n");
			continue;
		}
		
		printf ("0\n");
	}	
	return 0;
}

