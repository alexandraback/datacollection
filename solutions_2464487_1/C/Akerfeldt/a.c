#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

__int64 paintFromR(__int64 r)
{
	return 2*r+1;
}

__int64 solve(__int64 r, __int64 t)
{
	return (t+4)/(2*r+5);
}

__int64 sumFrom1ToX(__int64 x)
{
	__int64 sum;

	if(x%2 == 0)
		return (x/2)*(x+1);
	else
	{
		x--;
		sum = (x/2)*(x+1);
		sum += x+1;
		return sum;
	}
}

__int64 totalPaint(__int64 r, __int64 j)
{
	return j*(2*r+1)+(4*(sumFrom1ToX(j-1)));
}

int main(int argc, char *argv[])
{
	char buf[65536];
	int  i, T;
	__int64 r, t, j, diff, oldj;

	gets(buf);
	sscanf(buf, "%d", &T);
	for(i=0; i<T; i++)
	{
		gets(buf);
		sscanf(buf, "%I64d %I64d", &r, &t);

		j=1;
		diff=1;
		while(1)
		{
			if(t < totalPaint(r,j) && diff == 1)
			{
				break;
			}
			else if(t == totalPaint(r,j) && diff == 1)
			{
				j++;
				break;
			}
			else if(t < totalPaint(r,j))
			{
				j=oldj;
				diff=1;
			}
			else
			{
				oldj=j;
				diff*=2;
			}
			
			j+=diff;
		}
		j--;
		/*
		j=0;
		t -= paintFromR(r);
		while(t >= 0)
		{
			j++;
			r += 2;
			t -= paintFromR(r);
		}*/
		
		printf("Case #%d: %I64d\n",i+1,j);
	}

	return 0;
}