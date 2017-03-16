#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int carg, char* args[])
{
  // read and populate data
  int trials;

  int rows;
  int cols;
  int mines;
  int possible;

  char* poss_config;

  fscanf(stdin, "%d", &trials);
  for (int t = 0; t < trials; t++)
  {
    fscanf(stdin, "%d", &rows);
    fscanf(stdin, "%d", &cols);
    fscanf(stdin, "%d", &mines);

    //printf("r %d c %d m %d s %d\n", rows, cols, mines, (rows * cols) - mines);
    int space = (rows * cols) - mines;
    int possible = 0;

    // easy case rows == 1 || cols == 1
    // 
    if (rows == 1 || cols == 1)
    {
      if (space)
      {
        possible = 1;

        poss_config = malloc(rows * cols * sizeof(char));
        poss_config[0] = 'c';
        for (int i = 1; i < space; i++)
        {
          poss_config[i] = '.';
        }
        for (int i = space; i < rows * cols; i++)
        {
          poss_config[i] = '*';
        }
      }
    }
    else
    {
      if (space == 1)
      {
        possible = 1;
        poss_config = malloc (rows * cols * sizeof(char));
        memset (poss_config, '*', rows * cols * sizeof(char));
        poss_config[0] = 'c';
      }
      /*else if (mines == 0)
      {
        possible = 1;
        poss_config = malloc (rows * cols * sizeof(char));
        memset (poss_config, '.', rows * cols * sizeof(char));
        poss_config[0] = 'c';
      }*/
      else
      {
        for (int i = 1; i < cols; i++)
        {
          int req_cols = i + 1;
          int req_rows = space / req_cols;
          int spare = space % req_cols;

          if(req_rows <= rows && req_rows > 1)
          {
            int free_cols = req_cols < cols;
            int free_rows = req_rows < rows;

            int carry = 0;
            int* quick_map = calloc (rows, sizeof(int));
            for (int j = 0; j < req_rows; j++)
            {
              quick_map[j] = req_cols;
            }
            if (spare == 0)
            {
              possible = 1;
            }
            else if (spare == 1)
            {
              if (req_cols > 2 && req_rows > 2)
              {
                if (free_cols)
                {
                  possible = 1;
                  --quick_map[req_rows - 1];
                  for (int j = 0; j < spare + 1; j++)
                  {
                    ++quick_map[j];
                  }
                }
                else if (free_rows)
                {
                  possible = 1;
                  --quick_map[req_rows - 1];
                  quick_map[req_rows] = spare + 1;
                }
              }
              else if (req_cols > 2 && free_rows)
              {
                carry = req_rows;
                if (req_cols - 1 >= spare + carry)
                {
                  possible = 1;
                  for (int j = 0; j < req_rows; j++)
                  {
                    --quick_map[j];
                  }
                  quick_map[req_rows] = carry + spare;
                }
              }
              else if (req_rows > 2 && free_cols)
              {
                carry = req_cols;
                if (req_rows - 1 >= spare + carry)
                {
                  possible = 1;
                  quick_map[req_rows - 1] = 0;
                  for (int j = 0; j < spare + carry; j++)
                  {
                    ++quick_map[j];
                  }
                }
              }
            }
            else
            {
              if (free_cols && spare <= req_rows)
              {
                possible = 1;
                for (int j = 0; j < spare; j++)
                {
                  ++quick_map[j];
                }
              }
              else if (free_rows && spare <= req_cols)
              {
                possible = 1;
                quick_map[req_rows] = spare;
              }
            }

            if (possible)
            {
              poss_config = malloc (rows * cols * sizeof(char));
              for (int j = 0; j < rows; j++)
              {
                for (int k = 0; k < quick_map[j]; k++)
                {
                  poss_config[j * cols + k] = '.';
                }
                for (int k = quick_map[j]; k < cols; k++)
                {
                  poss_config[j * cols + k] = '*';
                }
              }
              poss_config[0] = 'c';
            }
          }
        }
      }
    }

    printf("Case #%d: \n", t + 1);
    if (possible)
    {
      for (int i = 0; i < rows; i++)
      {
        for (int j = 0; j < cols; j++)
        {
          printf("%c", poss_config[i * cols + j]);
        }
        printf("\n");
      }
    }
    else
    {
      printf("Impossible\n");
    }
  }
}
