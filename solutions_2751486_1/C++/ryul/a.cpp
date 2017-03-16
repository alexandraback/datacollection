#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define MAX 1500000

bool vow(char str);

char string[MAX];
int vowl[MAX];

int main(void)
{
	int test, ans, n;
	FILE *in = fopen("A-large.in", "r");
	FILE *out = fopen("A-large.out", "w");

	fscanf(in, "%d", &test);
	int i=1;
	ans=0;
	while ( i <= test )
	{
		fscanf(in, "%s %d", string, &n);

		int count=0;
		int len = strlen(string);
		int check = -1;
		
		for ( int j=len-1; j>=0; j-- )
		{
			if ( vow(string[j]) == true ) count=0;
			else vowl[j] = ++count;
		}

		for ( int j=0; j<len; j++ )
		{
			if ( vowl[j] >= n )
			{
				ans += (j-check)*(len-(j+n)+1);
				check = j;
			}
		}

		fprintf(out, "Case #%d: %d\n", i, ans);
		ans=0;
		i++;
		for ( int j=0; j<len; j++ )
			vowl[j] = 0;
	}

	fclose(in);
	fclose(out);
	return 0;
}

bool vow(char str)
{
	if ( str == 'a' || str == 'e' || str == 'i' || str == 'o' || str == 'u' )
		return true;
	else return false;
}