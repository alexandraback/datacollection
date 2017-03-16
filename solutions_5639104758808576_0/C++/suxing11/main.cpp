#include <stdio.h>


int ans;

int n;
char s[1100];


void gao()
{
	int cur, i;
	ans = 0;
	cur = 0;
	scanf ("%d %s%*c", &n, s);
	for (i = 0; i <= n; i++)
	{
		if (cur < i) ans += i-cur, cur = i;
		cur += s[i] - '0';
	}
	
}


int main()
{
	int T, ncas;
	freopen ("A-small-attempt0.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	scanf ("%d%*c", &T);
	for (ncas = 1; ncas <= T; ncas++)
	{
		gao();
		printf ("Case #%d: %d\n", ncas, ans);
	}
	
	return 0;
}
