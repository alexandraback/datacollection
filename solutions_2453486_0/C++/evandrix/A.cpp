#include <cstdio>

using namespace std;

#define FOR(i,a,b)   for(int(i)=int(a);(i)<int(b);(i)++)
#define FOREQ(i,a,b) for(int(i)=int(a);(i)<=int(b);(i)++)

static int T;
static char grid[4][4];

int main()
{
	scanf("%d", &T);
	FOREQ(t,1,T)
	{
		FOR(i,0,4)
			scanf("%s", &grid[i]);

		int no_x = 0, no_o = 0, no_t = 0;
		bool x_won = false, o_won = false, has_empty_sq = false;

		FOR(i,0,4)
		{
			no_x = 0, no_o = 0, no_t = 0;
			FOR(j,0,4)
			{
				if (grid[i][j] == 'X') no_x++;
				else if (grid[i][j] == 'O') no_o++;
				else if (grid[i][j] == 'T') no_t++;
				else if (grid[i][j] == '.') has_empty_sq = true;
			}
			
			if ( (no_x == 4)
				|| (no_x == 3 && no_t == 1))
			{
				x_won = true;
			}
			else if ( (no_o == 4)
				|| (no_o == 3 && no_t == 1))
			{
				o_won = true;
			}
		}

		FOR(i,0,4)
		{
			no_x = 0, no_o = 0, no_t = 0;
			FOR(j,0,4)
			{
				if (grid[j][i] == 'X') no_x++;
				else if (grid[j][i] == 'O') no_o++;
				else if (grid[j][i] == 'T') no_t++;
			}
			
			if ( (no_x == 4)
				|| (no_x == 3 && no_t == 1))
			{
				x_won = true;
			}
			else if ( (no_o == 4)
				|| (no_o == 3 && no_t == 1))
			{
				o_won = true;
			}
		}

		no_x = 0, no_o = 0, no_t = 0;
		FOR(i,0,4)
		{
			if (grid[i][i] == 'X') no_x++;
			else if (grid[i][i] == 'O') no_o++;
			else if (grid[i][i] == 'T') no_t++;	
		}
		if ( (no_x == 4)
			|| (no_x == 3 && no_t == 1))
		{
			x_won = true;
		}
		else if ( (no_o == 4)
			|| (no_o == 3 && no_t == 1))
		{
			o_won = true;
		}

		no_x = 0, no_o = 0, no_t = 0;
		FOR(i,0,4)
		{
			if (grid[i][3-i] == 'X') no_x++;
			else if (grid[i][3-i] == 'O') no_o++;
			else if (grid[i][3-i] == 'T') no_t++;	
		}
		if ( (no_x == 4)
			|| (no_x == 3 && no_t == 1))
		{
			x_won = true;
		}
		else if ( (no_o == 4)
			|| (no_o == 3 && no_t == 1))
		{
			o_won = true;
		}

		printf("Case #%d: ", t);
		if (x_won && o_won)
		{
			printf("Draw\n");
		}
		else if (x_won)
		{
			printf("X won\n");
		}
		else if (o_won)
		{
			printf("O won\n");
		}
		else
		{
			if (has_empty_sq) printf("Game has not completed\n");
			else printf("Draw\n");
		}
	}
	return 0;
}
