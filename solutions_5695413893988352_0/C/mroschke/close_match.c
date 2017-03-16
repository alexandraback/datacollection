// MAX ROSCHKE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_LENGTH 25

// -- UTILITY

// get the next integer input
int next_int() {
  int ret = 0;
  scanf("%d", &ret);
  return ret;
}

// get the next string input
void next_string(char* out) {
  scanf("%s", out);
}

// -- REAL FUNCTIONS

// -- recusive solver
#define EQUAL_FLAG 01
#define C_FLAG     02
#define J_FLAG     04
void tree_search(
  char* c_score, char* j_score, int flag, int i, int n,
  char* best_c, char* best_j, int* best_diff
) {
  // if base depth reached, check best solution
  if(i >= n) {
    // get absolute difference
    int diff = atoi(c_score) - atoi(j_score);
    diff = (diff < 0) ? -diff : diff;

    // update if needed
    if(*best_diff > diff) {
      *best_diff = diff;
      strncpy(best_c, c_score, n + 1);
      strncpy(best_j, j_score, n + 1);
    }

    // stop
    return;
  }

  // check if we have any option
  if(c_score[i] != '?' && j_score[i] != '?') {
    tree_search(c_score, j_score, flag, i + 1, n, best_c, best_j, best_diff);
  } else if(c_score[i] == '?' && j_score[i] == '?') {
    // only 01, 00, 10, 09, 90 possible
    c_score[i] = '0';
    j_score[i] = '0';
    tree_search(c_score, j_score, flag, i + 1, n, best_c, best_j, best_diff);
    c_score[i] = '0';
    j_score[i] = '1';
    tree_search(c_score, j_score, flag, i + 1, n, best_c, best_j, best_diff);
    c_score[i] = '0';
    j_score[i] = '9';
    tree_search(c_score, j_score, flag, i + 1, n, best_c, best_j, best_diff);
    c_score[i] = '1';
    j_score[i] = '0';
    tree_search(c_score, j_score, flag, i + 1, n, best_c, best_j, best_diff);
    c_score[i] = '9';
    j_score[i] = '0';
    tree_search(c_score, j_score, flag, i + 1, n, best_c, best_j, best_diff);
    c_score[i] = '?';
    j_score[i] = '?';
  } else if(c_score[i] == '?') {
    // must be within 1 of j
    int a = '0' + ((j_score[i] - '0' + 1) % 10);
    int b = '0' + ((j_score[i] - '0' + 9) % 10);

    if(a < b) {
      c_score[i] = a;
      tree_search(c_score, j_score, flag, i + 1, n, best_c, best_j, best_diff);
      c_score[i] = j_score[i];
      tree_search(c_score, j_score, flag, i + 1, n, best_c, best_j, best_diff);
      c_score[i] = b;
      tree_search(c_score, j_score, flag, i + 1, n, best_c, best_j, best_diff);
    } else {
      c_score[i] = b;
      tree_search(c_score, j_score, flag, i + 1, n, best_c, best_j, best_diff);
      c_score[i] = j_score[i];
      tree_search(c_score, j_score, flag, i + 1, n, best_c, best_j, best_diff);
      c_score[i] = a;
      tree_search(c_score, j_score, flag, i + 1, n, best_c, best_j, best_diff);
    }

    c_score[i] = '?';
  } else {
    // must be within 1 of c
    int a = '0' + ((c_score[i] - '0' + 1) % 10);
    int b = '0' + ((c_score[i] - '0' + 9) % 10);

    if(a < b) {
      j_score[i] = a;
      tree_search(c_score, j_score, flag, i + 1, n, best_c, best_j, best_diff);
      j_score[i] = c_score[i];
      tree_search(c_score, j_score, flag, i + 1, n, best_c, best_j, best_diff);
      j_score[i] = b;
      tree_search(c_score, j_score, flag, i + 1, n, best_c, best_j, best_diff);
    } else {
      j_score[i] = b;
      tree_search(c_score, j_score, flag, i + 1, n, best_c, best_j, best_diff);
      j_score[i] = c_score[i];
      tree_search(c_score, j_score, flag, i + 1, n, best_c, best_j, best_diff);
      j_score[i] = a;
      tree_search(c_score, j_score, flag, i + 1, n, best_c, best_j, best_diff);
    }

    j_score[i] = '?';
  }
}

// instance solver
void solve_instance(char* c_score, char* j_score) {
  // get the length of the scores
  int len = strlen(c_score);

  // temp storage
  char best_c[MAX_LENGTH];
  char best_j[MAX_LENGTH];
  int best_diff = INT_MAX;

  // run the recursive solver, passing down allowable options
  tree_search(c_score, j_score, EQUAL_FLAG, 0, len, best_c, best_j, &best_diff);

  // print out the solution
  printf("%s %s", best_c, best_j);
}

// main function
int main(int argc, char* argv[]) {
  // number of test cases
  int t = next_int();

  // storage for strings
  char c_score[MAX_LENGTH];
  char j_score[MAX_LENGTH];

  // iterate over test cases
  for(int i = 1; i <= t; i++) {
    // read input strings
    next_string(c_score);
    next_string(j_score);

    // print prefix
    printf("Case #%d: ", i);

    // solve instance
    solve_instance(c_score, j_score);

    // print suffix
    printf("\n");
  }
}

