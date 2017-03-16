#define _CRT_SECURE_NO_WARNINGS C4996
#include <stdio.h>
int T,p;
int n,sum=0,ans=0;
char st[1010];
int main()
{
	int i;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d", &T);

	while (T)
	{
		T--;
		scanf("%d %s", &n, st);

		sum = 0;
		ans = 0;
		sum += st[0] - 48;
		for (i = 1; i <= n; i++)
		{
			st[i] -= 48;
			if (sum < i){ ans += i - sum; sum = i; }
			sum += st[i];
		}
		printf("Case #%d: %d\n", ++p,ans);
		//p++;
	}

	return 0;
}
