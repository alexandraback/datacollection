#include <cstdio>

int przyp()
{
	int n;
	scanf("%d", &n);
	int dod = 0;
	int sum = 0;
	for(int i = 0; i <= n; i++)
	{
		char c;
		scanf(" %c", &c);
		int x = c - '0';
		if(sum + dod < i)
			dod += i - (sum + dod);
		sum += x;
	}
	return dod;
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
		printf("Case #%d: %d\n", i, przyp());
	return 0;
}
