#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t = 0;
char app[10];
int main()
{
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		int n = 0;
		bool flag = false;
		scanf("%d", &n);
		memset(app, 0, sizeof(app));
		for (int j = 1; j < 10000; j++)
		{
			if (flag) break;
			flag = true;
			int tt = n * j;
			while (tt)
			{
				app[tt % 10] = true;
				tt /= 10;
			}
			for (int k = 0; k < 10; k++)
				if (!app[k])
					flag = false;
			if (flag)
			{
				printf("Case #%d: %d\n", i, n * j);
				break;
			}
		}
		if (!flag)
			printf("Case #%d: INSOMNIA\n", i);
	}
	return 0;
}
