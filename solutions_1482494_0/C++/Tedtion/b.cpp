#include <stdio.h>
#include <string.h>
#define NN 1008

int getNextLevel(int a[], int b[], int c[], int n, int stars)
{
	int i,next;
	for (i=0; i<n; i++) if (c[i] != 2)
	{
		if (b[i] <= stars) return i*2+1;
	}
	next = -1;
	for (i=0; i<n; i++) if (c[i] == 0 && a[i] <= stars)
	{
		if (next == -1) next = i;
		else if (b[next] < b[i]) next = i;
	}
	if (next == -1) return -1;
	return next*2;
}

int main()
{
	int a[NN],b[NN],c[NN],t,n,i;
	int stars, times, next;

	freopen("b-small.in", "r", stdin);
	freopen("b.out", "w", stdout);

	scanf("%d",&t);
	for (int cas = 1; cas <= t; cas++)
	{
		scanf("%d",&n);
		for (i=0; i<n; i++) scanf("%d%d",&a[i],&b[i]);
		memset(c,0,sizeof(c));
		stars = times = 0;
		while (1)
		{
			next = getNextLevel(a,b,c,n,stars);
			if (next == -1) break;
			if (next%2)
			{
				stars += 2 - c[next/2];
				c[next/2] = 2;
			} else {
				stars++;
				c[next/2] = 1;
			}
			times++;
		}
		for (i=0; i<n; i++) if (c[i] != 2) break;
		if (i<n) printf("Case #%d: Too Bad\n", cas);
		else printf("Case #%d: %d\n", cas, times);
	}
	return 0;
}
