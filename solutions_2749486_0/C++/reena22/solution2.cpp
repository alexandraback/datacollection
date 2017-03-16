#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <algorithm>    // std::sort
#include <vector>       // std::vector

void SolveCase(int X, int Y, int testNum)
{
	int xcurr = 0, ycurr = 0;
	char dir[500];
	int currJump = 0;
	while(xcurr != X || ycurr != Y)
	{
		if(currJump >= 500)
			break;

		if(xcurr != X)
		{
			if(xcurr < X)
			{
				if(xcurr + currJump + 1 > X)
				{
					xcurr = xcurr - currJump - 1;
					dir[currJump] = 'W';
					currJump++;
					xcurr = xcurr + currJump + 1;
					dir[currJump] = 'E';
					currJump++;
				}
				else
				{
					xcurr = xcurr + currJump + 1;
					dir[currJump] = 'E';
					currJump++;
				}
			}
			else if(xcurr > X)
			{
				if(xcurr - currJump - 1 < X)
				{
					xcurr = xcurr + currJump + 1;
					dir[currJump] = 'E';
					currJump++;
					xcurr = xcurr - currJump - 1;
					dir[currJump] = 'W';
					currJump++;
				}
				else
				{
					xcurr = xcurr - currJump - 1;
					dir[currJump] = 'W';
					currJump++;
				}
			}
		}
		else if(ycurr != Y)
		{
			if(ycurr < Y)
			{
				if(ycurr + currJump + 1 > Y)
				{
				ycurr = ycurr - currJump - 1;
				dir[currJump] = 'S';
				currJump++;
				ycurr = ycurr + currJump + 1;
				dir[currJump] = 'N';
				currJump++;
				}
				else
				{
					ycurr = ycurr + currJump + 1;
				dir[currJump] = 'N';
				currJump++;
				}
			}
			else if(ycurr > Y)
			{
				if(ycurr - currJump - 1 < Y)
				{
				ycurr = ycurr + currJump + 1;
				dir[currJump] = 'N';
				currJump++;
				ycurr = ycurr - currJump - 1;
				dir[currJump] = 'S';
				currJump++;
				}
				else
				{
					ycurr = ycurr - currJump - 1;
				dir[currJump] = 'S';
				currJump++;
				}
			}
		}
	}

	dir[currJump] = '\0';

	printf("Case #%d: %s\n", testNum, dir);
}

// ---------------------------------------------------------------------------------
// Main Function
// ---------------------------------------------------------------------------------

int  main ()
{
	int T;
	scanf("%d", &T);

	for(int t = 1; t<=T; t++)
	{
		int X,Y;
		scanf("%d%d", &X, &Y);


		SolveCase(X, Y, t);

	}
}
