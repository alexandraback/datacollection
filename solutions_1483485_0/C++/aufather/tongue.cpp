
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
  fscanf(ifile, "%lld\n", &T);
  return 0;
} /* read_input */

struct TestCase                 // struct to hold one test case
{
  int64_t tc_id;
  char g[1000];
} TC;

static char *key = "yhesocvxduiglbkrztnwjpfmaq";

int read_test_case(int64_t tc_id)
{
  TC.tc_id = tc_id;
  fgets(TC.g, sizeof(TC.g), ifile);
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

  for (char *g = TC.g; *g; ++g) {
    char t = *g;
    if (*g >= 'a' && *g <= 'z') t = key[*g - 'a'];
    strid += sprintf(&result_str[strid], "%c", t);
  } /* 'g' for loop */

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
