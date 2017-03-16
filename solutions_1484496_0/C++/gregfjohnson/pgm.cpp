/* template for programming contests */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verbose = 0;

int count;
int data[20];

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

typedef struct {
  int value;
  int mask;
} pair_t;

int result_cmp(const pair_t *p1, const pair_t *p2)
{
  return p1->value - p2->value;
}

pair_t result[1048576];

void printum(int i)
{
  int mask = result[i].mask;
  int first = 1;
  i = 0;
  while (mask != 0)
  {
    if (mask & 1)
    {
      if (!first) printf(" ");
      first = 0;
      printf("%d", data[i]);
    }
    mask = mask >> 1;
    i++;
  }
  printf("\n");
}

/* solve the current problem */
void solve_it()
{
  int result_ind = 0, value, m2, i;
  i = 0;
  for (int mask = 1; mask <= 1048575; mask++)
  {
    value = 0;
    m2 = mask;
    i = 0;
    while (m2 != 0)
    {
      if (m2 & 1)
        value += data[i];
      m2 = m2 >> 1;
      i++;
    }
    result[result_ind++].value = value;
    result[result_ind-1].mask = mask;
  }

  qsort(result, 1048575, sizeof(result[0]),
      (int(*)(const void *, const void *))result_cmp);

  for (i = 0; i < 1048574; i++)
  {
    if (result[i].value == result[i+1].value)
    {
      printum(i);
      printum(i+1);
      return;
    }
  }
  printf("impossible\n");
}

/* print the solution for the current problem */
void print_soln()
{
}

/* read in, solve, and print solution to one problem in the input */
void do_game(int game)
{
    reset_input();

    read_input();

    if (verbose)
        print_input();

    printf("Case #%d:\n", game + 1);

    solve_it();

    print_soln();

    // printf("\n");
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
