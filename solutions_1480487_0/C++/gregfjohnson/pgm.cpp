/* template for programming contests */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verbose = 0;

int count;
int data[200];
double result[200];

/* clear out and initialize data structures for next input problem */
void reset_input()
{
}

/* read in input for next problem */
void read_input()
{
  scanf("%d", &count);
  for (int i = 0; i < count; i++)
    scanf("%d", &data[i]);
}

/* print input for the current problem */
void print_input()
{
    fprintf(stderr, "input:\n");
    fprintf(stderr, "count %d; ", count);
    for (int i = 0; i < count; i++)
      fprintf(stderr, "%d ", data[i]);
    fprintf(stderr, "\n");
}

/* solve the current problem */
void solve_it()
{
  int total = 0, i, winners = 0;
  double score, nn;

  for (i = 0; i < count; i++)
    total += data[i];

  score = 2.0 * total / count;

  for (i = 0; i < count; i++)
  {
    nn = 100. * (score - data[i]) / total;
    if (nn < 0.0)
      winners++;
  }

  if (winners > 0)
  {
    int sum_loser = 0;
    for (i = 0; i < count; i++)
    {
      nn = 100. * (score - data[i]) / total;
      if (nn >= 0.0)
      {
        sum_loser += data[i];
      }
    }
    score = ((double) total + sum_loser) / (count - winners);
  }

  for (i = 0; i < count; i++)
  {
    nn = 100. * (score - data[i]) / total;
    result[i] = nn;
  }
}

/* print the solution for the current problem */
void print_soln()
{
  for (int i = 0; i < count; i++)
  {
    if (result[i] < 0.0)
      printf("0.0 ");
    else
      printf("%.06f ", result[i]);
  }
}

/* read in, solve, and print solution to one problem in the input */
void do_game(int game)
{
    reset_input();

    read_input();

    if (verbose)
        print_input();

    solve_it();

    printf("Case #%d:\n", game + 1);

    print_soln();

     printf("\n");
}

/* process a file containing a sequence of problems */
int main(int argc, char **argv)
{
    int games, game, just_game = -1;

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            if (strcmp("-v", argv[i]) == 0)
                verbose++;
            else if (strcmp("-g", argv[i]) == 0)
            {
                if (++i >= argc || sscanf(argv[i], "%d", &just_game) != 1)
                {
                    fprintf(stderr, "bad arg line\n");
                    exit(1);
                }
                just_game--;
            }
            else
            {
                fprintf(stderr, "bad arg line\n");
                exit(1);
            }
        }
    }

    scanf("%d", &games);

    for (game = 0; game < games; game++)
    {
        if (just_game != -1 && game != just_game)
            read_input();
        else
            do_game(game);
    }
}
