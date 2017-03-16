#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare (const void* a, const void* b)
{
  if (*(double*)a < *(double*)b) return -1;
  if (*(double*)a == *(double*)b) return 0;
  if (*(double*)a > *(double*)b) return 1;
}

int deceit_run (int blocks, double* n_blocks, double* k_blocks)
{
  int wins = 0;

  int n_high, k_high, n_low, k_low;

  n_low = 0;
  k_low = 0;
  n_high = blocks - 1;
  k_high = blocks - 1;

  for (int i = 0; i < blocks; i++)
  {
    if (n_blocks[n_low] > k_blocks[k_low])
    {
      ++n_low;
      ++k_low;
      ++wins;
    }
    else
    {
      ++n_low;
      --k_high;
    }
  }
  return wins;
}

int war_run (int blocks, double* n_blocks, double* k_blocks)
{
  int wins = 0;

  int n_high, k_high, n_low, k_low;

  n_low = 0;
  k_low = 0;
  n_high = blocks - 1;
  k_high = blocks - 1;

  for (int i = 0; i < blocks; i++)
  {
    if (n_blocks[n_high] > k_blocks[k_high])
    {
      --n_high;
      ++k_low;
      ++wins;
    }
    else
    {
      --n_high;
      --k_high;
    }
  }

  return wins;
}

int main (int carg, char* args[])
{
  // read and populate data
  int trials;

  int blocks;

  double* n_blocks;
  double* k_blocks;

  int win_war;
  int win_deceit;

  fscanf(stdin, "%d", &trials);
  for (int t = 0; t < trials; t++)
  {
    win_war = 0;
    win_deceit = 0;

    fscanf(stdin, "%d", &blocks);

    n_blocks = malloc(blocks * sizeof(double));
    k_blocks = malloc(blocks * sizeof(double));

    for (int i = 0; i < blocks; i++)
    {
      fscanf(stdin, "%lf", n_blocks + i);
    }

    for (int i = 0; i < blocks; i++)
    {
      fscanf(stdin, "%lf", k_blocks + i);
    }

    qsort(n_blocks, blocks, sizeof(double), compare);
    qsort(k_blocks, blocks, sizeof(double), compare);

    win_war = war_run (blocks, n_blocks, k_blocks);
    win_deceit = deceit_run (blocks, n_blocks, k_blocks);

    printf("Case #%d: %d %d\n", t + 1, win_deceit, win_war);
  }
}
