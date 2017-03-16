
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <stdint.h>
#include <map>
#include <vector>
#include <list>
#include <unordered_set>
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

#define MULT(_x, _y) (((_x) * (_y)))

struct TestCase                 // struct to hold one test case
{
  int64_t tc_id;
  int64_t A;
  int64_t B;
  long double cp[100000];
  long double rp[100000];
} TC;

int read_test_case(int64_t tc_id)
{
  TC.tc_id = tc_id;
  fscanf(ifile, "%lld %lld\n", &TC.A, &TC.B);
  long double f;
  for (int64_t i = 0; i < TC.A; ++i) {
    fscanf(ifile, "%Lf", &f);
    TC.cp[i] = f;
  } /* 'i' for loop */
  return 0;
} /* read_test_case */

static inline void compute_rp()
{
  TC.rp[0] = TC.cp[0];
  for (int64_t i = 1; i < TC.A; ++i) {
    TC.rp[i] = MULT(TC.rp[i - 1], TC.cp[i]);
  } /* 'i' for loop */
}

char *solve(int64_t tc_id)
{
  int64_t strid = 0;
  static char result_str[65535];

  assert(!feof(ifile));
  tc_id++; // increment tc_id so that Case # will start from 1
  read_test_case(tc_id);

  strid += sprintf(&result_str[strid], "Case #%lld: ", tc_id);

  /* SOLVE HERE */

  compute_rp();

  int64_t B1 = TC.B + 1;
  int64_t Tcorr = B1 - TC.A;
  int64_t Tincorr = Tcorr + B1;
  int64_t Bcorr = TC.A + B1;
  int64_t Bincorr = Bcorr + B1;
  long double exp = (TC.rp[TC.A - 1] * Tcorr) + ((1 - TC.rp[TC.A - 1]) * Tincorr);
  long double cexp;
  for (int64_t i = 0; i < TC.A - 1; ++i) {
    cexp = TC.rp[i] * (Bcorr - (2 * (i + 1))) + (1 - TC.rp[i]) * (Bincorr - (2 * (i + 1)));
    exp = min(exp, cexp);
  } /* 'i' for loop */
  exp = min(exp, (long double)(TC.B + 2));

  strid += sprintf(&result_str[strid], "%0.6Lf\n", exp);
  /*  int64_t x = sprintf(&result_str[strid], "%lld", exp % W);
  if (x >= 7) {
    result_str[strid + 6] += result_str[strid + 7] > 4 ? 1 : 0;
  } else {
    for (int64_t i = x; i < 6; ++i) {
      result_str[strid + i] = '0';
    }
  }
  result_str[strid + 6] = '\n';
  result_str[strid + 7] = '\0';
*/
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
