#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int s,n,a[128];

bool
possible (int op1, int op2)
{
	int t = s;
	int j = 0;
	for (; t > a[j] && j < n; j ++)
		t += a[j];
	for (int i = 0; i < op1; i ++){
		t = t*2 - 1;
		for (; t > a[j] && j < n; j ++)
			t += a[j];
	}
	return n - j <= op2;
}

int
main ()
{
	freopen ("As.in","r",stdin);
	freopen ("As.out","w",stdout);
	int t;
	scanf ("%d", &t);
	for (int tc = 1; tc <= t; tc ++){
		scanf ("%d %d", &s, &n);
		for (int i = 0; i < n; i ++)
			scanf ("%d", &a[i]);
		sort (a, a + n);

		int ans = INT_MAX;
		for (int i = 0; i <= n; i ++)
			for (int j = 0; j <= n; j ++)
				if (possible (i,j))
					ans = min (ans, i + j);
		printf ("Case #%d: %d\n",tc,ans);
	}
	return 0;
}