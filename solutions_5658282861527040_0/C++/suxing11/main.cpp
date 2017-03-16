# include <stdio.h>


int gao(int a, int b, int k)
{
	int i, j;
	int ans = 0;
	for (i = 0; i < a; i++)
		for (j = 0; j < b; j++)
			if ((i&j) < k) ans++;
	return ans;
}


int main ()
{
	int T;
	int i, a, b, k;
	freopen ("B-small-attempt0.in", "r", stdin);
	freopen ("b_out.txt", "w", stdout);
	scanf ("%d", &T);
	for (i = 1; i <= T; i++)
	{
		scanf ("%d%d%d", &a, &b, &k);
		printf ("Case #%d: %d\n", i, gao(a,b,k));
	}
	return 0;
}
