
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <map>
#include <vector>
#include <list>
#include <unordered_set>
#include <algorithm>

using namespace std;

FILE *ifile, *ofile;

long T;                          // num test cases

int read_input(const char *fbase="Sample")
{
  char fname[2048];

  // open input file with extension .in
  strncpy(fname, fbase, sizeof(fname) - 5);
  int fbase_idx = strlen(fname);
  strcpy(&fname[fbase_idx], ".in");
  ifile = fopen(fname, "r");
  assert(ifile);

  // open output file with extension .out
  strcpy(&fname[fbase_idx], ".out");
  ofile = fopen(fname, "w");
  assert(ofile);

  // scan the number of test cases
  fscanf(ifile, "%ld", &T);
  return 0;
} /* read_input */

struct TestCase                 // struct to hold one test case
{
  long tc_id;
} TC;

long N;
long jps[200];
long X;
long h1, h2;
long double ans[200];

int comp(const void *v1, const void *v2)
{
  long *l1 = (long *)v1;
  long *l2 = (long *)v2;
  return *l1 - * l2;
}

//  qsort(board, 512, sizeof(board[0]), comp);

int read_test_case(long tc_id)
{
  TC.tc_id = tc_id;
  X = 0;
  h1 = h2 = 1000000;
  fscanf(ifile, "%ld", &N);
  for (long i = 0; i < N; ++i) {
    fscanf(ifile, " %ld", &jps[i]);
    X += jps[i];
    if (jps[i] < h1) {
      h2 = h1;
      h1 = jps[i];
    } else if (jps[i] < h2) {
      h2 = jps[i];
    }
  } /* 'i' for loop */

  return 0;
} /* read_test_case */

char *solve(long tc_id)
{
  long strid = 0;
  static char result_str[65535];

  assert(!feof(ifile));
  tc_id++; // increment tc_id so that Case # will start from 1
  read_test_case(tc_id);

  strid += sprintf(&result_str[strid], "Case #%ld: ", tc_id);

  /* SOLVE HERE */
  long double neg = 0;
  long negct = N;
  for (long i = 0; i < N; ++i) {
    long num = jps[i];
    ans[i] = ((long double)((((2 * X) - (N * num)) * 100))) / ((long double)(N * X));
    if (ans[i] < 0) {
      neg += ans[i];
      negct--;
    }
  } /* 'i' for loop */
  if (neg < 0) {
    neg /= negct;
    for (long i = 0; i < N; ++i) {
      if (ans[i] < 0) ans[i] = 0;
      else ans[i] += neg;
    } /* 'i' for loop */
  }
  for (long i = 0; i < N; ++i) {
    strid += sprintf(&result_str[strid], " %Lf", ans[i]);
  } /* 'i' for loop */

  strid += sprintf(&result_str[strid], "\n");

  return result_str;
} /* solve */

int main(int argc, char *argv[])
{
  char *str;
  read_input(argc > 1 ? argv[1] : "Sample");
  for (long i = 0; i < T; ++i) {
    str = solve(i);
    fprintf(ofile, "%s", str);
    fprintf(stderr, "%s", str);
  }
  return 0;
}
