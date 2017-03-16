#include <iostream>
#include <cstdio>

#include <cstring>

using namespace std;

int main()
{
	int T, t = 0;
	scanf("%d", &T);

	while (t ++ < T)
	{
		int x, y;
		char ret[500];
		int pos = 0;
		scanf("%d%d", &x, &y);

		if (x > 0)
		{
			for (int i = 0; i < x; i ++)
			{
				ret[pos ++] = 'W';
				ret[pos ++] = 'E';
			}
		}
		else
		{
			for (int i = 0; i < 0 - x; i ++)
			{
				ret[pos ++] = 'E';
				ret[pos ++] = 'W';
			}
		}

		if (y > 0)
		{
			for (int i = 0; i < y; i ++)
			{
				ret[pos ++] = 'S';
				ret[pos ++] = 'N';
			}
		}
		else
		{
			for (int i = 0; i < 0 - y; i ++)
			{
				ret[pos ++] = 'N';
				ret[pos ++] = 'S';
			}
		}

		ret[pos] = '\0';

		printf("Case #%d: %s\n", t, ret);

		
	}
}
