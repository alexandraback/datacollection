#include <cstdio>
#include <cstring>

int a[32][16];
int b[32][16];

int main()
{
	int tn, ti = 0;
	memset(b, 0, sizeof(b));
	scanf("%d", &tn);
	while(tn--)
	{
		int i, x, y;
		scanf("%d %d %d", &i, &x, &y);
		--i;

		memset(b, 0, sizeof(b));
		for(int j = 0; j < (1 << i); ++j)
		{
			memset(a, 0, sizeof(a));
			a[16][0] = 1;
			int maxx = 2;

			for(int k = 0; k < i; ++k)
			{
				int x = 16;
				int y = maxx;
				if((1<<k) & j) 
				{
					while(y > 0 && a[x-1][y-1] == 0)
					{
						--x;
						--y;
					}
					if(x == 16)
					{
						if(a[x+1][y-1] == 0)
						{
							while(y > 0 && a[x+1][y-1] == 0)
							{
								++x;
								--y;
							}
						}
						else
						{
							maxx += 2;
						}
					}
					a[x][y] = 1;
				}
				else 
				{
					while(y > 0 && a[x+1][y-1] == 0)
					{
						++x;
						--y;
					}
					if(x == 16)
					{
						if(a[x-1][y-1] == 0)
						{
							while(y > 0 && a[x-1][y-1] == 0)
							{
								--x;
								--y;
							}
						}
						else
						{
							maxx += 2;
						}
					}
					a[x][y] = 1;
				}
			}
			for(int k = 0; k < 32; ++k)
				for(int l = 0; l < 16; ++l)
					b[k][l] += a[k][l];
		}
		double ans = 0;
		if(x < -16 || x > 15 || y < 0 || y > 16)
			ans = 0;
		else
			ans = (double)b[16+x][y] / b[16][0];
		printf("Case #%d: %.7lf\n", ++ti, ans);
	}
}
