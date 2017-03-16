#include <cstdio>
#include <string.h>

#include <cassert>

int rMin[100];
int cMin[100];

int min(int a, int b)
{
	if ( a < b )
		return a;
	else
		return b;
}

int max(int a, int b)
{
	if ( a > b )
		return a;
	else
		return b;
}


void Reset()
{
  for (int i = 0; i < 100; i++)
  {
	  rMin[i] = 1;
	  cMin[i] = 1;
  }
}

int main(int argc, char *argv[])
{
  char grid[100][100];

  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++)
  {
	int N, M;
	int possible = true;
    printf("Case #%d: ", t);
	Reset();
	assert(scanf("%d %d", &N, &M) == 2);

	for (int r = 0; r < N; r++)
	{
	  for (int c = 0; c < M; c++)
	  {
		  assert(scanf("%d", &grid[r][c]) == 1);
	  }
	}
	
    for (int r = 0; r < N; r++)
	{
	  for (int c = 0; c < M; c++)
	  {
		  rMin[r] = max(rMin[r], grid[r][c]);
	  }
	}

   for (int c = 0; c < M; c++)
	{
	  for (int r = 0; r < N; r++)
	  {
		  cMin[c] = max(cMin[c], grid[r][c]);
	  }
	}

    for (int r = 0; r < N; r++)
	{
	  for (int c = 0; c < M; c++)
	  {
		  if  ((rMin[r] > grid[r][c]) &&
			   (cMin[c] > grid[r][c]))
		  {
			  if (possible)
			  {
//				  printf("%d,%d %d rMin %d cMin %d\n",
//					     r, c, grid[r][c], rMin[r], cMin[c]);
			  possible = false;
			  }
		  }

	  }
	}

	printf("%s", possible ? "YES" : "NO");

	printf("\n");

  }

}