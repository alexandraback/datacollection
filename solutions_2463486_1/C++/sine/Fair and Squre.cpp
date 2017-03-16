#include <stdio.h>
#include <math.h>

int itv[10000000];

int palin(__int64 x)
{
	int ar[15], i;
	i=0;
	while (x)
	{
		ar[i++]=x%10;
		x/=10;
	}
	for (int j=i-1; j>=i/2; j--)
	{
		if (ar[j]!=ar[i-1-j]) return 0;
	}
	return 1;
}

int main()
{
	freopen("C-large-1.in", "r", stdin);
	freopen("l1.out", "w", stdout);

	int t, cas;
	__int64 a, b, i;

	for (i=1; i<=10000000; i++)
	{
		if (palin(i) && palin(i*i)) itv[i]=itv[i-1]+1;
		else itv[i]=itv[i-1];
	}
	

	scanf("%d", &t);
	for (cas=1; cas<=t; cas++)
	{
		scanf("%I64d%I64d", &a, &b);
		printf("Case #%d: %d\n", cas, itv[(int)sqrt((double)b)]-itv[(int)sqrt((double)(a-1))]);
	}
	return 0;
}