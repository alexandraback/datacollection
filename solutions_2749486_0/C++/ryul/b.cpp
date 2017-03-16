#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int main(void)
{
	FILE *in = fopen("B-small-attempt0.in", "r");
	FILE *out = fopen("B-small-attempt0.out", "w");
	int t, ans;

	fscanf(in, "%d", &t);

	int n = 1;
	while ( n <= t )
	{
		int x, y;
		fscanf(in, "%d %d", &x, &y);

		fprintf(out, "Case #%d: ", n);
		if ( x > 0 )
		{
			for ( int i=0; i<x; i++ )
				fprintf(out, "WE");
		}
		else if ( x < 0 )
		{
			for ( int i=0; i<-x; i++ )
				fprintf(out, "EW");	
		}

		if ( y > 0 )
		{
			for ( int i=0; i<y; i++ )
				fprintf(out, "SN");
		}
		else if ( y < 0 )
		{
			for ( int i=0; i<-y; i++ )
				fprintf(out, "NS");
		}
		n++;
		fprintf(out, "\n");
	}

	fclose(in);
	fclose(out);
	return 0;
}