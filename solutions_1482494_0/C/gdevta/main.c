#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FOR(i,n) for((i)=0;(i)<(n);(i++)) 
#define min(a,b) ((a) > (b) ? (b) : (a))
#define max(a,b) ((a) > (b) ? (a) : (b))

#define INF 999999999

int n [101][2];

void testcase (int id)
{

	int N,i;
	
	scanf ("%d\n", &N);
	
	FOR(i,N) scanf ("%d %d ", &n[i][0], &n[i][1]);

	int stars = 0;

	int found = 1;
	
	int gs = 0;

	while (found != 0)
{
	found = 0;
	
	FOR(i,N)
	{
		if (n[i][1] <= stars)
		{
			found = 1;
			
			stars ++;
			
			if (n[i][0] != INF)
			{
				stars++;
			}
			
			n[i][0] = INF;
			n[i][1] = INF;
			
			break;
		}
	}	
	
	if (found != 1)
	{
		int max = -1;
	
		FOR(i,N)
		{
			if (n[i][0] <= stars)
			{
				found = 1;
				if (max == -1 || n[i][1] > n[max][1])
				{
					max = i;
				}
			}
		}
		
		if (max != -1)
		{
			stars ++;
				
			n[max][0] = INF;
		}
	}
	
	if (found)
	{
		gs ++;
	}
}	
	if (stars < N*2)
	{
		printf ("Case #%d: Too Bad\n", id);
	}
	else
	printf ("Case #%d: %d\n", id, gs);
}

int main ()
{
	int testcases = 0;
	
	scanf ("%d\n", &testcases);
	
	int i = 0;
		
	FOR(i,testcases) testcase (i+1);	

	return 0;
}
