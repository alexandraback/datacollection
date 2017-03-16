#include <stdio.h>

int s[11234];

int
main(void)
{
	int T, n;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d ", &n);
		for(int i = 0; i <= n; i++)
			s[i] = getchar() - '0';
		int ans = 0, up = 0;
		for(int i = 0; i <= n; i++)
		{
			if(up < i)
				ans += i - up, up = i;
			up += s[i];
		}
		printf("Case #%d: %d\n", t, ans);
	}
}
