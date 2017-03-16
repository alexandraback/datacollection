
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

#define ITER(_i, _o) for(typeof((_o)->begin()) _i = (_o)->begin(); _i != (_o)->end(); ++_i)
#define FIND(_i, _o, _key) typeof((_o)->begin()) _i = (_o)->find(_key)

enum Status
{
  FAILURE = -1,
  SUCCESS = 0
};


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

int comp(const void *v1, const void *v2)
{
  long *l1 = (long *)v1;
  long *l2 = (long *)v2;
  return *l1 - * l2;
}

//  qsort(board, 512, sizeof(board[0]), comp);

typedef unsigned long long u64;

u64 A, N;
u64 M[100];

int read_test_case(long tc_id)
{
  fscanf(ifile, "%llu %llu", &A, &N);
  for (u64 i = 0; i < N; ++i) {
    fscanf(ifile, "%llu", &M[i]);
  } /* 'i' for loop */
  return 0;
} /* read_test_case */

u64 doubler(u64 a, u64 b, u64 *f)
{
  if (a <= 1) return ~0LLU;
  u64 moves = 0;
  while (a <= b) {
    moves ++;
    a *= 2;
    a--;
  }
  *f = a;
  return moves;
}

u64 helper(u64 a, u64 begin)
{
  if (begin >= N) return ~0LLU;
  u64 i = begin;
  for (i = begin; i < N && a > M[i]; ++i) {
    a += M[i];
  } /* 'i' for loop */
  u64 ditch = N - i;
  if (a <= 1) return ditch;
  u64 newa = 0;
  u64 motes = doubler(a, M[i], &newa);
  u64 x = helper(newa, i);
  motes += x;
  return min(ditch, motes);
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
  sort(&M[0], &M[N]);

  u64 ans = helper(A, 0);
  strid += sprintf(&result_str[strid], "%llu\n", ans);

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
