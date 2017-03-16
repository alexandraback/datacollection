#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream.h>

int main (void)
{
	int t = 0;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		double c = 0;
		double f = 0;
		double x = 0;
		cin >> c;
		cin >> f;
		cin >> x;
		
		double fn = ((x / c) - (2 / f) - 1);
		int n = ceil(fn);
		if (0 > n)
		{
			n = 0;
		}
		
		double tt = 0;
		for (int j = 0; j < n; j++)
		{
				tt += (c / (2+j*f));
		}
		
		tt += (x / (2 + n * f));
		
		printf("Case #%d: %.7f\n", i+1, tt);
	}  
	return 0;
}
