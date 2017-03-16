#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory.h>

using namespace std;

int main()
{
	int T, t = 0;
	scanf("%d", &T);
	while (t ++ < T)
	{
		int x, y;
		scanf("%d%d", &x, &y);

		int step = x > 0 ? x : -x;
		step += y > 0 ? y : -y;

		int i = 0;
		for (i = 1; i <= step; i ++)
		{
			if ((i + 1) * i / 2 >= step)
			{
				break;
			}
		}

		char ret[10000];
		memset(ret, 0, sizeof(ret));
		int pos = 0;
		ret[i] = '\0';
		if (i * (i + 1) / 2 == step)
		{
			int cur = 0;
			for (int j = i; j >= 1; j --)
			{
				if (x > 0)
				{
					if (cur + j <= x)
					{
						cur += j;
						ret[j - 1] = 'E';
					}
					else
					{
						ret[j - 1] = y > 0 ? 'N' : 'S';
					}
				}
				else
				{
					if (cur + j <= -x)
					{
						cur += j;
						ret[j - 1] = 'W';
					}
					else
					{
						ret[j - 1] = y > 0 ? 'N' : 'S';
					}
				}
			}
			printf("Case #%d: %s\n", t, ret);
		}
		else
		{
			int tot0 = i * (i + 1) / 2;
			int tot1 = (i - 1) * i / 2;
			if (tot0 - step > step - tot1)
			{
				i --;
			}

			//cout << "i: " << i << endl;
		

			int xleft = 0;
			int yleft = 0;
			if (x != 0)
			{
				int tmp = (i + 1) * i / 2 - (y > 0 ? y : - y);

				if (x > 0)
				{
					xleft = x - tmp;
					x = tmp;
				}
				else
				{
					xleft = x + tmp;
					x = - tmp;
				}
			}
			else
			{
				int tmp = (i + 1) * i / 2 - (x > 0 ? x : - x);

				if (y > 0)
				{
					yleft = y - tmp;
					y = tmp;
				}
				else
				{
					yleft = y + tmp;
					y = - tmp;
				}
			}

			//cout << "(x, y) = " << x << ", " << y << endl;
			//cout << "(xl, yl) = " << xleft << ", " << yleft << endl;
			int cur = 0;
			for (int j = i; j >= 1; j --)
			{
				if (x > 0)
				{
					if (cur + j <= x)
					{
						cur += j;
						ret[j - 1] = 'E';
					}
					else
					{
						ret[j - 1] = y > 0 ? 'N' : 'S';
					}
				}
				else
				{
					if (cur + j <= -x)
					{
						cur += j;
						ret[j - 1] = 'W';
					}
					else
					{
						ret[j - 1] = y > 0 ? 'N' : 'S';
					}
				}
			}

			int pos = i;

			if (xleft != 0)
			{
				if (xleft > 0)	
				{
					for (int j = 0; j < xleft; j ++)
					{
						ret[pos ++] = 'W';
						ret[pos ++] = 'E';
					}
				}
				else
				{
					for (int j = 0; j < - xleft; j ++)
					{
						ret[pos ++] = 'E';
						ret[pos ++] = 'W';
					}
				}
			}
			else
			{
				if (yleft > 0)	
				{
					for (int j = 0; j < yleft; j ++)
					{
						ret[pos ++] = 'S';
						ret[pos ++] = 'N';
					}
				}
				else
				{
					for (int j = 0; j < - yleft; j ++)
					{
						ret[pos ++] = 'N';
						ret[pos ++] = 'S';
					}
				}
			}

			ret[pos] = '\0';
			printf("Case #%d: %s\n", t, ret);

		}

	}
}
