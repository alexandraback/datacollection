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

const int MAX_N = 16;

int n, m, s;

char so[MAX_N];
char t[MAX_N];
char curr[MAX_N];

int sum, ma, nu;

void go (int p)
{
	int i, ccnt = 0, la;
	if (p == s)
	{
		nu ++;
		int j;
		for (i = 0; i + m - 1 < p; i ++)
		{
			la = 1;
			for (j = i; j <= i + m - 1; j ++)
				if (curr[j] != t[j - i])	
					la = 0;
			ccnt += la;
		}
		if (ccnt > ma)
			ma = ccnt;
		sum += ccnt;
		return ;
	}
	for (i = 0; i < n; i ++)
	{
		curr[p] = so[i];
		go (p + 1);
		curr[p] = '#';
	}
}

void read ()
{
	double dma, dnu, dsum, ans;
	scanf ("%d%d%d", &n, &m, &s);
	scanf ("%s", so);
	scanf ("%s", t);
	sum = nu = ma = 0;
	go (0);
	///printf ("%d %d %d\n", ma, nu, sum);
	dma = ma;
	dnu = nu;
	dsum = sum;
	ans = (dnu * dma - dsum) / dnu;
	printf ("%.7lf\n", ans);
}

int main ()
{
	int t, t1;
	scanf ("%d", &t);
	for (t1 = 1; t1 <= t; t1 ++)
	{
		printf ("Case #%d: ", t1);
		read ();
	}
	return 0;
}



