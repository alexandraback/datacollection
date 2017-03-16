#include<stdio.h>
int mov;
int hash[2000010];
int judge(int n, int b)
{
	int k = 10;
	int res = 0;
	int p = mov;
	while(n / k)
	{
		int cre = n / k + (n % k) * p;
		if (cre != n && cre > n && cre <= b && hash[cre] != n)
		{
			res++;
			hash[cre] = n;
			//printf("%d %d\n",n, cre);
		}
		k *= 10;
		p /= 10;
	}
	return res;
}
int main()
{
	int cas;
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int a, b;
	scanf("%d", &cas);
	for(int idx = 1; idx <= cas; idx++)
	{
		int ans = 0;
		scanf("%d%d",&a, &b);
		int k = a;
		mov = 1;
		for(int i = a; i <= b; i++)
			hash[i] = -1;
		while(k / 10)
		{
			mov *= 10;
			k /= 10;
		}
		for(int i = a; i < b; i++)
		{
			ans += judge(i, b);
		}
		printf("Case #%d: %d\n", idx, ans);
	}
}