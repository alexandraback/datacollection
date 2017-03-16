#include <cstdio>
#include <string.h>

#include <cassert>

int xCount[10];
int oCount[10];
bool xWin, oWin;
bool gameDone;

bool Incr(int &p)
{
	p++;
	if (p == 4)
		return true;
	else
		return false;
}

int Update(int r, int c, char val, int *count, bool &win)
{
		win = win || Incr(count[r]);
		win = win || Incr(count[c+4]);

		if (r == c)
		{
			win = win || Incr(count[8]);
		}

		if ((r + c) == 3)
		{
			win = win || Incr(count[9]);
		}

	return 0;
}

void Reset()
{
	memset(xCount, 0, sizeof(xCount));
	memset(oCount, 0, sizeof(oCount));
	xWin = false;
	oWin = false;
	gameDone = true; // default, then set to false if we find a .
}

int main(int argc, char *argv[])
{
  char buf[255];
  char grid[4][4];

  fgets(buf, 255, stdin);

  int T;
  sscanf(buf, "%d", &T);

  for (int i = 1; i <= T; i++)
  {
    printf("Case #%d: ", i);
	Reset();
	for (int r = 0; r < 4; r++)
	{
	  fgets(buf, 255, stdin);
	  buf[4] = 0;
#if DEBUG
	  printf("|%s|\n", buf);
#endif
	  for (int c = 0; c < 4; c++)
	  {
		  char val = buf[c];
		  
		  if ((val == 'X') || (val == 'T'))
			  Update(r, c, val, xCount, xWin);
		  if ((val == 'O') || (val == 'T'))
			  Update(r, c, val, oCount, oWin);

		  if (val == '.')
			  gameDone = false;
	  }
#if DEBUG
	  printf ("X %d %d %d %d - %d %d %d %d - %d %d\n",
		       xCount[0],
			   xCount[1],
			   xCount[2],
			   xCount[3],
			   xCount[4],
			   xCount[5],
			   xCount[6],
			   xCount[7],
			   xCount[8],
			   xCount[9]);
	  printf ("O %d %d %d %d - %d %d %d %d - %d %d\n",
		       oCount[0],
			   oCount[1],
			   oCount[2],
			   oCount[3],
			   oCount[4],
			   oCount[5],
			   oCount[6],
			   oCount[7],
			   oCount[8],
			   oCount[9]);
#endif
	}
	fgets(buf, 255, stdin);
	
	if (i != T)
	  assert(strlen(buf) <= 2);

	if (xWin)
	{
		printf("X won");
	} else if (oWin)
	{
        printf("O won");
	} else if (gameDone)
	{
		printf("Draw");
	}
	else
	{
		printf("Game has not completed");
	}

	printf("\n");

  }

}