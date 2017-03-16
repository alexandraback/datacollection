
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

struct ToyBox
{
  long count;
  long id;
};

long N, M;

ToyBox toys[100];
ToyBox boxs[100];

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
  fscanf(ifile, "%ld %ld\n", &N, &M);
  memset(toys, 0, sizeof(toys));
  memset(boxs, 0, sizeof(boxs));
  for (long i = 0; i < N; ++i) {
    fscanf(ifile, "%ld %ld", &boxs[i].count, &boxs[i].id);
  } /* 'i' for loop */
  for (long i = 0; i < M; ++i) {
    fscanf(ifile, "%ld %ld", &toys[i].count, &toys[i].id);
  } /* 'i' for loop */

  return 0;
} /* read_test_case */

long ans(long b, long bct, long t, long tct, long ct)
{
 repeat:
  if (t >= M || b >= N) return ct;

  if (!bct) bct = boxs[b].count;
  if (!tct) tct = toys[t].count;

  if (toys[t].id == boxs[b].id) {
    long x = min(tct, bct);
    //    printf("munching %ld ct = %ld id = %ld t[%ld] b[%ld]\n", x, ct, toys[t].id, t, b);
    ct += x;
    if (tct == x) {t++; tct = 0;
    }
    else tct -= x;
    if (bct == x) {b++; bct = 0;
    }
    else bct -= x;
    goto repeat;
  } else {
    long bh = ans(b + 1, 0, t, tct, ct);
    long th = ans(b, bct, t + 1, 0, ct);
    ct = max(bh, th);
  }
  return ct;
}

char *solve(long tc_id)
{
  long strid = 0;
  static char result_str[65535];

  assert(!feof(ifile));
  tc_id++; // increment tc_id so that Case # will start from 1
  read_test_case(tc_id);

  strid += sprintf(&result_str[strid], "Case #%ld: ", tc_id);

  /* SOLVE HERE */
  long z = ans(0, 0, 0, 0, 0);

  strid += sprintf(&result_str[strid], "%ld\n", z);

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
