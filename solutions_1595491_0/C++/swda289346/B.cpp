#include <stdio.h>
#define N 100

int main()
{
	int t;
	int n, s, p;
	int get;
	int c, cs;
	scanf("%d", &t);
	for (int i=1;i<=t;++i)
	{
		c = cs = 0;
		scanf("%d%d%d", &n, &s, &p);
		for (int j=0;j<n;++j)
		{
			scanf("%d", &get);
			if (get/3+(get%3?1:0)>=p)
				++c;
			else if ((get%3==0&&get>=3&&get/3+1>=p) || (get%3==2&&get/3+2>=p))
				++cs;
		}
		printf("Case #%d: %d\n", i, c+(cs<?s));
	}
	return 0;
}
