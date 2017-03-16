
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

long X, Y;
long x, y;
char path[501];
long pidx;
long jmp;

int read_test_case(long tc_id)
{
  fscanf(ifile, "%ld %ld", &X, &Y);
  //  for (long i = 0; i < 501; i++) path[i] = '\0';
  x = y = jmp = pidx = 0;
  return 0;
} /* read_test_case */

void movex()
{
  long m = 0;
  if (X > 0) {
    m = X - x;
    for (long i = 0; i < m; i++) {
      path[pidx++] = 'W';
      path[pidx++] = 'E';
      x++;
    }
  } else {
    m = x - X;
    for (long i = 0; i < m; i++) {
      path[pidx++] = 'E';
      path[pidx++] = 'W';
      x--;
    }
  }
}

void movey()
{
  long m = 0;
  if (Y > 0) {
    m = Y - y;
    for (long i = 0; i < m; i++) {
      path[pidx++] = 'S';
      path[pidx++] = 'N';
      y++;
    }
  } else {
    m = y - Y;
    for (long i = 0; i < m; i++) {
      path[pidx++] = 'N';
      path[pidx++] = 'S';
      y--;
    }
  }
}

long move()
{
  jmp++;
  if (x != X) {
    if (x + jmp <= X) {
      x += jmp;
      path[pidx++] = 'E';
      return jmp;
    }
    if (x - jmp >= X) {
      x -= jmp;
      path[pidx++] = 'W';
      return jmp;
    }
  }
  if (y != Y) {
    if (y + jmp <= Y) {
      y += jmp;
      path[pidx++] = 'N';
      return jmp;
    }
    if (y - jmp >= Y) {
      y -= jmp;
      path[pidx++] = 'S';
      return jmp;
    }
  }
  movex();
  assert(x == X);
  movey();
  assert(y == Y);
  return 0;
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
  while (move());
  path[pidx] = '\0';
  strid += sprintf(&result_str[strid], "%s\n", path);

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
