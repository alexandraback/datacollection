#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxlen = 1000010;
char buf[maxlen];


void run() {
  int x, y;
  scanf ("%d%d", &x, &y);
  while (x > 0) {
    printf ("WE");
    x--;
  }
  while (x < 0) {
    printf ("EW");
    x++;
  }
  while (y > 0) {
    printf ("SN");
    y--;
  }
  while (y < 0) {
    printf ("NS");
    y++;
  }
  printf ("\n");
}

int main (void) {
  int test_n;
  scanf ("%d", &test_n);
  for (int test_i = 0; test_i < test_n; test_i++) {
    fprintf (stderr, "%d\n", test_i);
    printf ("Case #%d: ", test_i + 1);
    run();
  }

  return 0;
}
