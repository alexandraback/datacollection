#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

const double M_PI = 4.0*atan(1.0);

int main()
{
	
	assert(freopen("A-small-attempt1.in", "r", stdin));
	assert(freopen("output.out", "w", stdout));

	int nCase;
	int row,col;
	scanf("%d",&nCase);
	int count = 0;
	int r,t;
	for(int i = 0 ; i < nCase ; i++)
	{
		count = 0;
		scanf("%d",&r);
		scanf("%d",&t);
		bool finished = true;
		float totalPaint =(float) t;
		
		int firstArea =  r *r ;
		int currentArea =(r+1) * (r+1);
		count++;
		totalPaint =totalPaint -( currentArea - firstArea);
		
		while(finished)
		{
			 r = r+2;
			 firstArea =  r *r ;
			 currentArea =(r+1) * (r+1);
			


			if(currentArea - firstArea <= totalPaint)
			{
				count++;
				//r = r+1;
				totalPaint =totalPaint -( currentArea - firstArea);
			}
			else
			{
				finished = false;
			}
		}

		printf("Case #%d: %d\n",i+1,count);

	}
	return 0;
}