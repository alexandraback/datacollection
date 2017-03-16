#include <cstdio>
#include <vector>
using namespace std;

#define MAXD 20
#define MAXP 1<<MAXD
int nset[MAXD];
bool rep[MAXP];

int main ()
{
	int T, N, i, ts, rv, j, h;
	scanf("%d",&T);
	
	for ( int cnt = 1; cnt <= T; cnt++ )
	{
		scanf("%d",&N);
		for ( i = 0; i < N; i++ ) scanf("%d",&nset[i]);
		for ( i = 0; i < MAXP; i++ ) rep[i] = false;
		rv = -1;
		
		for ( i = 0; i < MAXP; i++ )
		{
			ts = 0;
			
			for ( j = 0; j < MAXD; j++ )
			{
				if ( ((1 << j) & i) > 0 ) ts += nset[j];
			}
			
			if ( rep[ts] ) { rv = ts; break; }
			rep[ts] = true;
		}
		
		printf("Case #%d:\n",cnt);
		if ( rv == -1 ) { printf("Impossible\n",cnt); continue; }
		h = 0;
		
		for ( i = 0; i < MAXP; i++ )
		{
			ts = 0;
			
			for ( j = 0; j < MAXD; j++ )
			{
				if ( ((1 << j) & i) > 0 ) ts += nset[j];
			}
			
			if ( ts == rv )
			{
				h++;
				for ( j = 0; j < MAXD; j++ )
				{
					if ( ((1 << j) & i) > 0 ) printf("%d ",nset[j]);
				}
				printf("\n");
			}
			if ( h == 2 ) break;
		}
		
	}
}