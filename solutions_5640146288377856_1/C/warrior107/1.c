#include<stdio.h>

int main()
{
	int t;
	int r, c, w;
	int i;
	int ans;

	scanf("%d", &t);

	for (i = 1; i <= t; i++)
	{
		scanf("%d %d %d", &r, &c, &w);

		ans = c / w;
		ans = ans*r;

		ans = ans + w - 1;

		if (c%w != 0)
			ans++;

		printf("Case #%d: %d\n",i,ans);
	}
}