#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>

int main( )
{
	int T,A,B;
	int x,y;
    int i,j;
    double min,temp1,temp2,p;
	freopen( "A-small-attempt0.in", "r", stdin );
	freopen( "output.txt", "w", stdout );
	scanf("%d\n",&T);
	for(i = 1; i <= T; ++i)
	{
		printf("Case #%d: ",i);
		scanf("%d%d\n",&A,&B);
		x = B-A+1;
		y = B+1;
		min = (2*A-y) < (1-x)? (2*A-y):(1-x);
		temp2 = y;
		for(j = 1; j <= A; ++j)
		{
              scanf("%lf",&p);
              temp2 *= p;
              temp1 = 2*(A-j) - temp2;
              if(temp1 < min)
                       min = temp1;
        }
        min += x+y;
        printf("%.6lf",min);
		printf("\n");
	}
	
	return 0;
}
