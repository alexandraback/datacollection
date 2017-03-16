#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

__int64 paintFromR(__int64 r)
{
	return 2*r+1;
}

int main(int argc, char *argv[])
{
	char buf[65536];
	int  i, T;
	__int64 r, t, j;

	gets(buf);
	sscanf(buf, "%d", &T);
	for(i=0; i<T; i++)
	{
		gets(buf);
		sscanf(buf, "%I64d %I64d", &r, &t);

		j=0;
		t -= paintFromR(r);
		while(t >= 0)
		{
			j++;
			r += 2;
			t -= paintFromR(r);
		}
		
		printf("Case #%d: %I64d\n",i+1,j);
	}

	return 0;
}