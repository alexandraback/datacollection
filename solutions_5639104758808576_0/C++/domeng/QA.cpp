#include <stdio.h>
char buf[1005];
int main()
{
	int T;
	scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		int s;
		scanf("%d %s",&s,buf);
		int open = 0;
		int addMore = 0;
		for (int i = 0; i <= s; i++)
		{
			if (buf[i] <= '0') continue;
			if (open < i) 
			{
				addMore += i - open;
				open = i;
			}
			open += buf[i] - '0';
		}
		printf("Case #%d: %d\n", kase, addMore);
	}
	return 0;
}