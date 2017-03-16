
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <stdint.h>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

FILE *ifile, *ofile;

int64_t T;                          // num test cases

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
  fscanf(ifile, "%lld", &T);
  return 0;
} /* read_input */

struct TestCase                 // struct to hold one test case
{
  int64_t tc_id;
  int64_t N;
  int64_t surprise;
  int64_t min_score;
  int64_t tot_score[101];
} TC;

int read_test_case(int64_t tc_id)
{
  TC.tc_id = tc_id;
  fscanf(ifile, "%lld %lld %lld", &TC.N, &TC.surprise, &TC.min_score);
  for (int64_t i = 0; i < TC.N; ++i) {
    fscanf(ifile, "%lld", &TC.tot_score[i]);
  } /* 'i' for loop */

  return 0;
} /* read_test_case */

char *solve(int64_t tc_id)
{
  int64_t strid = 0;
  static char result_str[65535];

  assert(!feof(ifile));
  tc_id++; // increment tc_id so that Case # will start from 1
  read_test_case(tc_id);

  strid += sprintf(&result_str[strid], "Case #%lld: ", tc_id);

  /* SOLVE HERE */
  int64_t max_best = TC.min_score * 3;
  int64_t def = 0, sur = 0, nope = 0;
  for (int64_t i = 0; i < TC.N; ++i) {
    if (TC.tot_score[i] == 0 && TC.min_score > 0) {
      nope++;
      continue;
    }
    int64_t diff = max_best - TC.tot_score[i];
    if (diff <=2) {
      def++;
    } else if (diff <= 4) {
      sur++;
    } else {
      nope++;
    }
  } /* 'i' for loop */

  int64_t res = def + min(sur, TC.surprise);
  strid += sprintf(&result_str[strid], "%lld\n", res);

  return result_str;
} /* solve */

int main(int argc, char *argv[])
{
  char *str;
  read_input(argc > 1 ? argv[1] : "Sample");
  for (int64_t i = 0; i < T; ++i) {
    str = solve(i);
    fprintf(ofile, "%s", str);
    fprintf(stderr, "%s", str);
  }
  return 0;
}
