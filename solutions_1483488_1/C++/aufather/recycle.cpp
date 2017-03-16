
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
  int64_t lb;
  int64_t ub;
} TC;

int read_test_case(int64_t tc_id)
{
  TC.tc_id = tc_id;
  fscanf(ifile, "%lld %lld\n", &TC.lb, &TC.ub);
  return 0;
} /* read_test_case */

static inline
int64_t rotate(char *s, int64_t sz)
{
  char ld = s[sz - 1];
  for (int64_t i = sz - 1; i; --i) {
    s[i] = s[i - 1];
  } /* 'i' for loop */
  s[0] = ld;
  if (ld == 0) return -1;
  return strtoll(s, NULL, 10);
}

static int64_t ramp[2000001] = {0};
static char s[10];
static char k[10];
static inline

int64_t rid(int64_t num)
{
  int64_t min = ramp[num];
  if (min > 0) return min;

  min = num;
  int64_t sz = sprintf(s, "%lld", num);
  for (int64_t i = 0; i < sz; ++i) {
    int64_t n = rotate(s, sz);
    if (n > 0 && n < min) min = n;
  } /* 'i' for loop */
  ramp[num] = min;
  return min;
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
  map<int64_t, int64_t> rmap;
  for (int64_t i = TC.lb; i <= TC.ub; ++i) {
    int64_t rec_id = rid(i);
    map<int64_t, int64_t>::iterator it = rmap.find(rec_id);
    if (it == rmap.end()) {
      rmap.insert(make_pair(rec_id, 0));
    } else {
      it->second++;
    }
  } /* 'i' for loop */

  int64_t res = 0;
  for (map<int64_t, int64_t>::iterator i = rmap.begin(); i != rmap.end(); ++i) {
    if (!i->second) continue;
    res += (i->second * (i->second + 1)) >> 1;
  } /* 'i' for loop */

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
