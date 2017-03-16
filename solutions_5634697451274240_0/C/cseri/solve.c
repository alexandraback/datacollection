// Compile with: gcc -Wall -Werror -ansi -pedantic -std=c11 solve.c -o solve-c

#include <stdio.h>
#include <string.h>


int solve(char* line)
{
  int sol = 0;
  int n = strlen(line);

  for (int i = 1; i < n; ++i) {
    if (line[i] != line[i - 1]) {
      // invert(line, i);
      ++sol;
    }
  }
  return sol;
}


#define LINE_SIZE 200
char line[LINE_SIZE] = {0};

int main() {
  FILE* infile = fopen("input.txt", "r");
  if (infile == 0) {
    fprintf(stderr, "Error opening file.\n");
    return 1;
  }

  if (fgets(line, LINE_SIZE, infile) == NULL) {
    fprintf(stderr, "Error reading file.\n");
    return 1;
  }

  int tn = -1;
  sscanf(line, "%d", &tn);
  if (tn < 0) {
    fprintf(stderr, "Invalid tn.\n");
    return 1;
  }

  for (int ti = 0; ti < tn; ++ti) {
    if (fgets(line, LINE_SIZE, infile) == NULL) {
      fprintf(stderr, "Error reading testcase %d.\n", ti);
      return 1;
    }
    line[strlen(line)-1] = '+';

    int sol = solve(line);

    printf("Case #%d: %d\n", ti + 1, sol);
  }

  return 0;
}
