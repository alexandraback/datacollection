#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int step;

int main()
{
	int T, count = 1;
	cin>>T;
	while(T--)
	{
		printf("Case #%d: ", count++);
		int x, y;
		scanf("%d%d", &x, &y);
		bool bE, bN;
		int stepX, stepY, cntX = 0, cntY = 0;
		stepX = (abs(x))<<1;
		stepY = (abs(y))<<1;

		if(x < 0)
		{
			bE = true;
			while(cntX < stepX)
			{
				if(bE)
				{
					cntX++;
					putchar('E');
					bE = false;
				}
				else
				{
					cntX++;
					putchar('W');
					bE = true;
				}
			}
		}
		else if(x > 0)
		{
			bE = false;
			while(cntX < stepX)
			{
				if(bE)
				{
					cntX++;
					putchar('E');
					bE = false;
				}
				else
				{
					cntX++;
					putchar('W');
					bE = true;
				}
			}
		}
	
		if(y < 0)
		{
			bN = true;
			while(cntY < stepY)
			{
				if(bN)
				{
					cntY++;
					putchar('N');
					bN = false;
				}
				else
				{
					cntY++;
					putchar('S');
					bN = true;
				}
			}
		}
		else if(y > 0)
		{
			bN = false;
			while(cntY < stepY)
			{
				if(bN)
				{
					cntY++;
					putchar('N');
					bN = false;
				}
				else
				{
					cntY++;
					putchar('S');
					bN = true;
				}
			}
		}
		puts("");
	}
	return 0;
}

