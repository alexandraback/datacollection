// 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

typedef struct {
	int max_normal;
	int max_strange;
} entry;


entry lookup_table[31];;

void update_lookup_table ( int first, int second, int third )
{
	int min = 10;
	int max = 0;
	int d = 0;
	int sum;
	if ( first < min ) min = first;
	if ( second < min ) min = second;
	if ( third < min ) min = third;
	if ( first > max ) max = first;
	if ( second > max ) max = second;
	if ( third > max ) max = third;

	d = max - min;
	sum = first + second + third;

	if ( d == 0 || d == 1 )
	{
		// normal score
		if ( max > lookup_table[sum].max_normal ) lookup_table[sum].max_normal = max;
	}
	else if ( d == 2 )
	{
		if ( max > lookup_table[sum].max_strange ) lookup_table[sum].max_strange = max;
	}
}

void prepare_table ( void )
{
	int first,second,third,i;

	for ( i = 0; i < 30; i++ )
	{
		lookup_table[i].max_normal = lookup_table[i].max_strange = 0;
	}

	
	for ( first = 0; first <= 10; first++ )
	{
		for ( second = 0; second <= 10; second++ )
		{
			for ( third = 0; third <= 10; third++ )
			{
				update_lookup_table ( first, second, third );
			}
		}
	}
	for ( i = 0; i < 31; i++ )
	{
	//	printf ("%2d  %d,  %d\n", i, lookup_table[i].max_normal,lookup_table[i].max_strange );
	}
}


int main(int argc, char* argv[])
{
	int cases, cas;

	prepare_table();
	
	scanf ("%d\n", &cases );
	for ( cas = 0; cas < cases ; cas++ )
	{
		int googlers;
		int strange;
		int score;
		int g_total;
		int total_number = 0;
		scanf ("%d %d %d", &googlers, &strange, &score );
		for ( int i_g = 0; i_g < googlers; i_g++ )
		{
			scanf ("%d", &g_total );
			if ( score <= lookup_table[g_total].max_normal ) 
			{
				total_number++;
			}
			else if ( score <= lookup_table[g_total].max_strange && strange )
			{
				strange--;
				total_number++;
			}
		}
		printf ("Case #%d: %d\n", cas+1, total_number );
	}
	return 0;
}

