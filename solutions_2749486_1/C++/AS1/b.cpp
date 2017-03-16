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

typedef pair <int, int> pnt;
#define x first
#define y second
int was[5000002];
int main (void) {

  vector <int> v;
  v.push_back (0);
  int left = 5000001;
  for (int d = 1; left > 0; d++) {
    fprintf (stderr, "%d\n", left);
    for (int i = 0; i < (int)v.size(); i++) {
      int x = v[i];
      if (x >= 0 && x <= 5000000) {
        if (!was[x]) {
          was[x] = d;
          left--;
        }
      }
    }

    vector <int> nv;
    for (int i = 0; i < (int)v.size(); i++) {
      int x = v[i];
      nv.push_back (x + d);
      nv.push_back (x - d);
    }
    sort (nv.begin(), nv.end());
    nv.erase (unique (nv.begin(), nv.end()), nv.end());
    v = nv;
  }
  for (int i = 0; i <= 5000000; i++) {
    printf ("%d\n", was[i] - 1);
  }
  return 0;

  int test_n;
  scanf ("%d", &test_n);
  for (int test_i = 0; test_i < test_n; test_i++) {
    fprintf (stderr, "%d\n", test_i);
    printf ("Case #%d: ", test_i + 1);
    run();
  }

  return 0;
}
