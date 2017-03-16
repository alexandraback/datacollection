#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	for(int tn = 0; tn<T; ++tn)
	{
		int n;
		char buffer[2000];
		int db = 0;
		int f = 0;
		scanf("%d %s",&n, buffer);
		for(int i = 0; i<=n; ++i)
		{
			int req = i - db;
			if (req > 0)
			{
				f += req;
				db += req;
			}
			db += buffer[i]-'0';
		}
		printf("Case #%d: %d\n",tn+1,f);
	}
	return 0;
}