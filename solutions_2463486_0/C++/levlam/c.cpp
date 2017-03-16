#include <cassert>
#include <cstdio>
#include <map>
#include <set>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool is_pal (long long x) {
  int y = x, xx = 0;
  while (y > 0) {
    xx = xx * 10 + y % 10;
    y /= 10;
  }
  return xx == x;
}

int main(void) {
  int tn, nt;
  scanf("%d", &nt);

  vector <long long> v;

  for (int i = 1; i <= 10000000; i++) {
    if (is_pal (i) && is_pal ((long long)i * i)) {
      v.push_back ((long long)i * i);
    }
  }

  for (tn=1; tn<=nt; tn++) {
    printf ("Case #%d: ", tn);
    fprintf (stderr, "Case #%d: \n", tn);

    long long a, b;
    cin >> a >> b;

    int res = 0;
    for (int i = 0; i < (int)v.size(); i++)
      if (a <= v[i] && v[i] <= b) {
        res++;
      }

    printf ("%d\n", res);
  }

  return 0;
}
