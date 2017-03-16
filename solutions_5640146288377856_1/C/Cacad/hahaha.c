#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int test, i, result, c, w, r;

	freopen ("A-large.in","r", stdin);
	freopen ("output.txt", "w", stdout);

	scanf("%d", &test);

	for (i=1 ; i<=test ; i++)
	{
		scanf("%d %d %d", &r, &c, &w);
		if (c%w==0)
		{
			result= w -1 + (r)*(c/w);
		}
		else
		{
			result= w+ r*(c/w);
		}

		printf("Case #%d: %d\n", i, result);
	}

	return 0;
}