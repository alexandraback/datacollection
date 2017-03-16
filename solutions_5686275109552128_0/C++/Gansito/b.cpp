#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main()
{
	int cases , NoCase;
	int D , tim , p , no , r;

	scanf("%d\n",&cases);
	for( NoCase = 1; NoCase <= cases; NoCase++ )
	{
		scanf("%d\n",&D);
		
		priority_queue < int , vector < int > , greater< int > > pq;
		tim = 0;
		no = 0;

		for( int i = 0; i < D; i++ )
		{
			scanf("%d\n",&p);
			pq.push( p );
		}
		while( !pq.empty() )
		{
			p = pq.top();
			r = p - ( (tim - no ) );
			//printf("Query tm = %d , no =  %d , r = %d , p = %d\n",tim , no ,  r , p);
			pq.pop();
			if( r <= 0 ) continue;
			if( (r >> 1) > pq.size() + 1  )
			{
				//printf("Split %d from %d ,in minute %d => ", r , p , tim);
				//printf("Adding %d and %d\n",( r + 1 ) >> 1 , ( r >> 1) );
				no++;
				pq.push( ( r + 1 ) >> 1 );
				pq.push( ( r >> 1) );
				tim++;
			}
			else
			{
				//printf("Eat %d from %d\n",r,p);
				tim += r;
			}
		}
		printf("Case #%d: %d\n",NoCase,tim);
	}
	return 0;
}