#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
  // Basic Case Information
  int casenumber;
  char *result;

  // Custom Data
  int number;

} Case;

int *prices;

// Basic custom functions
void readCase(FILE *, int, Case *);
void printCase(Case *);
void freeCase(Case *);
void processCase(Case *);

// Custom functions
int price(int number);
int reverse(int number);

// Basic static I/O functions
void readFile(const char *, Case **, int *);
void freeCases(Case *, int);
void writeResults(const char *, Case *, int);

int main(int argc, char const *argv[]) {
  Case *cases = NULL;
  int n;
  const char *filename;
  if (argc < 2) {
    filename = "min-sample.in";
    printf("Warning: No File specified. Using %s\n", filename);
    // exit(EXIT_FAILURE);
  } else {
    filename = argv[1];
  }
  readFile(filename, &cases, &n);
  for (int i = 0; i < n; i++) {
    printCase(cases + i);
    processCase(cases + i);
  }
  writeResults(filename, cases, n);
  freeCases(cases, n);
  return 0;
}

// #############################################################################
// #                          Basic custom functions                           #
// #############################################################################

void readCase(FILE *file, int casenumber, Case *c) {
  c->casenumber = casenumber;

  fscanf(file, "%d", &(c->number));
}
void printCase(Case *c) {
  printf("Case %d number: %d\n", c->casenumber, c->number);
}
void freeCase(Case *c) { free(c->result); }

void processCase(Case *c) {
  if (c->casenumber == 1) {
    const int MAX = 10e6;
    prices = (int *)malloc(MAX * sizeof(int));
    for (int i = 0; i < MAX; i++) {
      prices[i] = i;
    }
    for (int i = 1; i < MAX; i++) {
      int rev = reverse(i);
      if (reverse(rev) != i) {
        prices[i] = prices[i - 1] + 1;
        continue;
      }
      int a = prices[rev] + 1;
      int b = prices[i - 1] + 1;
      if (a < b) {
        prices[i] = a;
      } else {
        prices[i] = b;
      }
    }
    for (int i = 0; i < 100; i++) {
      printf("%d ", prices[i]);
    }
    printf("\n");
  }

  c->result = (char *)malloc(10 * sizeof(char));
  printf("%d\n", prices[c->number]);

  sprintf(c->result, "%d", prices[c->number]);
}

// #############################################################################
// #                          Custom functions                                 #
// #############################################################################

int reverse(int number) {
  int reverse = 0;
  while (number > 0) {
    reverse = reverse * 10 + number % 10;
    number = number / 10;
  }
  return reverse;
}

// #############################################################################
// #                          Basic I/O functions                              #
// #############################################################################

void readFile(const char *filename, Case **result, int *n) {
  FILE *file;
  file = fopen(filename, "r");
  if (file) {
    fscanf(file, "%d", n);
    Case *cases = (Case *)malloc(*n * sizeof(Case));
    for (int i = 0; i < *n; i++) {
      readCase(file, i + 1, cases + i);
    }
    fclose(file);
    *result = cases;
  } else {
    printf("Error opening file\n");
    exit(EXIT_FAILURE);
  }
}
void freeCases(Case *cases, int n) {
  for (int i = 0; i < n; i++) {
    freeCase(cases + i);
  }
  free(cases);
}
void writeResults(const char *filename, Case *cases, int n) {
  FILE *file;
  char outfilename[200];
  sprintf(outfilename, "%s.out", filename);
  file = fopen(outfilename, "w");
  if (file) {
    for (int i = 0; i < n; i++) {
      fprintf(file, "Case #%d: %s\n", cases[i].casenumber, cases[i].result);
    }
    fclose(file);
  } else {
    printf("Error writing file\n");
    exit(EXIT_FAILURE);
  }
}
