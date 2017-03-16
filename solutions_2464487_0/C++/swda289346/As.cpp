#include <stdio.h>

int main()
{
	int t;
	int r, b;
	int ans;
	scanf("%d", &t);
	for (int i=1;i<=t;++i)
	{
		ans = 0;
		scanf("%d%d", &r, &b);
		for (int j=r;;j+=2)
			if (b>=j*2+1)
			{
				b -= j*2+1;
				++ans;
			}
			else
				break;
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}
