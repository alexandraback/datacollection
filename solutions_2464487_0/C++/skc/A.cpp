// Codejam.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "stdio.h"
#include <vector>

using namespace std;

#if 1
typedef unsigned int typ;
#define FORMAT_STR	"%u"
#else
typedef unsigned __int64 typ;
#define FORMAT_STR	"%llu"
#endif

#if 1

int main(void)
{
	typ r,t,i,n,area=0;

	scanf(FORMAT_STR, &n);
	for(int j=1 ; j<=n ; ++j)
	{
		scanf(FORMAT_STR" "FORMAT_STR,&r, &t);

		typ area=0;
		int cnt=0;
		for(i=r ; 1 ; i+=2)
		{
			area += 2*i+1;
			if(area > t)
				break;
			cnt++;
		}

		printf("Case #%d: %d\n", j, cnt);
	}

	fflush(stdin);
	getchar();
	return 0;
}

#endif