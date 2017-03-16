#include <iostream>
#include <cstdio>
#include <cstring>

int n; 
int a[100];
int sums[2000200];

int getsum (int mask)
{
	int ret = 0, i; 
	for (i = 0; i < n; i ++)
		if (mask & (1 << i))
			ret += a[i];
	return ret;
}

void printmask (int mask)
{
	int i;
	for (i = 0; i < n; i ++)
		if (mask & (1 << i))
			printf ("%d ", a[i]);
	
	printf ("\n");
	
}

void solve ()
{
	memset (sums, 0, sizeof (sums));
	
	scanf ("%d", &n);
	int i; 
	for (i = 0; i < n; i ++)
		scanf ("%d", &a[i]);
	
	for (i = 1; i < (1<<n); i ++)
	{
		int s = getsum (i);
		if (sums[s] != 0)
		{
			printmask(sums[s]);
			printmask(i);
			break;
		}
		else
			sums[s] = i;
	}
		
}

int main () 
{
	
	int t; 
	scanf ("%d", &t);
	
	for (int i = 1; i <=t; i ++)
		printf ("Case #%d: \n", i), solve ();
	
	return 0;
}