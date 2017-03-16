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

const int MAX_N = 100000000;

int dp[MAX_N];

queue <int> q;

int main ()
{
	int i, t, rev, k, t1, a;
	memset (dp, -1, sizeof (dp));
	q.push (1);
	dp[1] = 1;
	while (!q.empty ())
	{
		t = q.front ();
		q.pop ();
		
		rev = 0;
		
		k = t;
		
		while (k)
		{
			rev = rev * 10 + k % 10;
			k /= 10;
		}
		///cout << t << " " << t1 << " : " << rev << endl;
		if (t < MAX_N && dp[t + 1] == -1)
		{
			q.push (t + 1);
			dp[t + 1] = dp[t] + 1;
		}
		if (rev < MAX_N && dp[rev] == -1)
		{
			q.push (rev);
			dp[rev] = dp[t] + 1;
		}
	}
	scanf ("%d", &t);
	for (t1 = 1; t1 <= t; t1 ++)
	{
		scanf ("%d", &a);
		printf ("Case #%d: %d\n", t1, dp[a]);
	}
	return 0;
}

