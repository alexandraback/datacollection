#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int letters[26] = {0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1};

typedef struct _substring {
	int start,end;
} Substring;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

__int64 solve(char *buf, int bufLen, int n)
{
	Substring a;
	__int64 i, pos=0, oldpos=-1, curn, thisletter, lastletter=0, strlength=0, before, after;
	__int64 sum=0, diff;

	for(i=0; i<bufLen; i++)
	{
		thisletter = letters[buf[i]-'a'];
		if(thisletter == 1 && lastletter == 0)
		{
			pos = i;
			strlength = 1;
		}
		else if(thisletter == 1 && lastletter == 1)
		{
			strlength++;
		}
		else if(thisletter == 0)
		{
			strlength=0;
		}

		if(strlength >= n)
		{
			before = pos - (oldpos+1);
			after = bufLen-1 - i;
			
			if(before > 0 && after > 0)
			{
				diff = (before+1)*(after+1);
			}
			else
			{
				diff = before+1+after;
			}

			sum += diff;
			oldpos = pos;
			pos++;
		}

		lastletter = thisletter;
	}

	return sum;
}

int main(int argc, char *argv[])
{
	char *buf, *tmp;
	int  i, T;
	int n;
	__int64 res;

	buf = malloc(1048576);
	gets(buf);
	sscanf(buf, "%d", &T);
	for(i=0; i<T; i++)
	{
		gets(buf);
		sscanf(buf, "%*s %d", &n);
		tmp = strchr(buf,' ');
		n = atoi(tmp+1);
		*tmp = '\0';

		res = solve(buf, (int)(tmp-buf),n);

		printf("Case #%d: %I64d\n",i+1,res);
	}

	free(buf);
	return 0;
}