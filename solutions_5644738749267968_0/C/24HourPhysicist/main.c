#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
Google Code Jam
Qualification 2014
Problem D. Deceitful War
*/

#define TRUE 1
#define FALSE 0


int comp (const void *a, const void *b)
{
  double x,y;
  x = *((double*)a);
  y = *((double*)b);
  if (x>y) 
    return 1;
  if (x<y)
    return -1;
  fprintf(stderr, "Error: no two can be the same: %lf %lf\n", x, y);
  return 0;
}

typedef double *hand;

hand Populate_Hand(int n_blocks)
{
  int i;
  hand h;
  h = (double*)(malloc(n_blocks*sizeof(double)));
  for(i=0;i<n_blocks;i++){
    scanf("%lf", &h[i]);
  }
  qsort(h, n_blocks, sizeof(double), comp);
  return h;
}

void Free_Hand(hand h)
{
  free(h);
}

void Print_Hand(hand h, int max)
{
  fprintf(stderr, "Hand");
  int i;
  for(i=0;i<max;i++){
    fprintf(stderr, " %lf", h[i]);
  }
  fprintf(stderr, "\n");
}


//return the number of wins that the person
//with the advantage will have
int Play(hand a, hand d, int nblocks)
{
  int ia, id;
  int wins, losses;
  ia = id = 0;
  wins = losses = 0;

  while (ia < nblocks) {
    if (a[ia] > d[id]) {
      wins++;
      ia++;
      id++;
    }
    else {
      losses++;
      ia++;
    }
  }
  return wins;
}

void Run(int c)
{
  int nblocks;
  hand ken, naomi;
  int naomi_advantage, regular;
  
  scanf("%d", &nblocks);

  naomi = Populate_Hand(nblocks);
  ken = Populate_Hand(nblocks);

  //Print_Hand(naomi, nblocks);
  //Print_Hand(ken, nblocks);

  naomi_advantage = Play(naomi, ken, nblocks);
  regular = nblocks - Play(ken, naomi, nblocks);

  fprintf(stdout, "Case #%d: %d %d\n", c, naomi_advantage, regular);

  Free_Hand(naomi);
  Free_Hand(ken);

}


int main() {
  int T;
  int i;
  scanf("%d", &T);

  for(i=1;i<=T;i++){
    Run(i);
  }
  return 0;
}
