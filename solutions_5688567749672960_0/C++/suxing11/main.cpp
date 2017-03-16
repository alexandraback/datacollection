#include <stdio.h>


int step[10000010];
int q[10000010];
int n;


int inverse(int x)
{
	int ans = 0;
	while(x)
		ans = ans * 10 + x%10, x/=10;
	return ans;
}


void gao()
{
	int f, r, u, v;
	
	q[0] = 1, step[1] = 1, f = 0, r = 1;
	while (f != r)
	{
		u = q[f++];
		
		v = u+1;
		if (v < 10000000 && step[v] == 0)
		{
			step[v] = step[u]+1;
			q[r++] = v;
		}
		
		v = inverse(u);
		if (v < 10000000 && step[v] == 0)
		{
			step[v] = step[u]+1;
			q[r++] = v;
		}
	}
}


int main()
{
	int T, cas;
	freopen ("A-small-attempt0.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	scanf ("%d", &T);
	gao();
	for (cas = 1; cas <= T; cas++)
	{
		scanf ("%d", &n);
		printf ("Case #%d: %d\n", cas, step[n]);
	}
	return 0;
}
