// 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>

int pairs ( int start, int end )
{
	int total = 0;
	char start_str[25];
	sprintf ( start_str, "%d", start );
	int len = strlen ( start_str );
	int num_found = 0;
	int check_set[10] = { 0 };
	for ( int rotation = 0; rotation < len - 1; rotation++ )
	{
		char* ptr = start_str;
		char first = *ptr;
		while ( *(ptr+1) ) { *ptr = *(ptr+1); ptr++; }
		*ptr = first;
		int new_num = atoi ( start_str );
		if ( new_num > start && new_num <= end )
		{
			for ( int i = 0; i < num_found; i++ )
			{
				if ( check_set[i] == new_num )
				break;
			}
			if ( i == num_found )
			{
				check_set[num_found] = new_num;
				num_found++;
				total++;
			}
		}
	}
	return total;
}

int main(int argc, char* argv[])
{
	int cases,cas;
	scanf ("%d\n", &cases );
	for ( cas = 0; cas < cases ; cas++ )
	{
		int min;
		int max;
		int total = 0;
		scanf ("%d %d\n", &min, &max );
		for ( int i = min; i <max; i++ )
		{
			total += pairs ( i, max );
		}
		printf ("Case #%d: %d\n", cas + 1, total );
	}
	return 0;
}

