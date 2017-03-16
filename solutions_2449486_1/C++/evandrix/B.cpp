#include <cstdio>

using namespace std;

#define FOR(i,a,b)   for(int(i)=int(a);(i)<int(b);(i)++)
#define FOREQ(i,a,b) for(int(i)=int(a);(i)<=int(b);(i)++)
#define MAX(a,b) ((a)>(b)?(a):(b))

static int T,N,M;
static int max_rows[105], max_cols[105];
static int grid[105][105];

int main()
{
	scanf("%d", &T);
	FOREQ(t,1,T)
	{
		scanf("%d%d", &N,&M);
		FOR(i,0,N)
		{
			FOR(j,0,M)
			{
				scanf("%d", &grid[i][j]);
			}
		}
		
		FOR(i,0,N)
		{
			int the_max = 0;
			FOR(j,0,M)
			{
				the_max = MAX(the_max, grid[i][j]);
			}
			max_rows[i] = the_max;
		}

		FOR(j,0,M)
		{
			int the_max = 0;
			FOR(i,0,N)
			{
				the_max = MAX(the_max, grid[i][j]);
			}
			max_cols[j] = the_max;
		}

		bool possible = true;
		FOR(i,0,N)
		{
			FOR(j,0,M)
			{
				if (grid[i][j] == max_rows[i] || grid[i][j] == max_cols[j])
				{}
				else
				{
					possible = false;
					break;	
				}
			}
			if (!possible) break;
		}
		
		printf("Case #%d: %s\n", t,possible?"YES":"NO");
	}
	return 0;
}
