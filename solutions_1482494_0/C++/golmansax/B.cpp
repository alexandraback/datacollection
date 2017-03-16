#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct level {
  int idx, one, two;
};
typedef struct level level_t;

bool ones_cmp (level_t l1, level_t l2) {
  return l1.one < l2.one ||
         (l1.one == l2.one && l1.two > l2.two);
}
bool twos_cmp (level_t l1, level_t l2) {
  return l1.two < l2.two;
}

int main() {
  int n_test;
  cin >> n_test;
  for (int i_test = 0; i_test < n_test; i_test++) {
    int n;
    cin >> n;

    level_t ones[n], twos[n];
    for (int i = 0; i < n; i++) {
      level_t tmp;
      int one, two;
      cin >> one >> two;

      tmp.idx = i;
      tmp.one = one;
      tmp.two = two;
      ones[i] = tmp;
      twos[i] = tmp;
    }
    int done[n];
    memset (done, 0, sizeof(int)*n);
    sort (ones, ones+n, ones_cmp);
    sort (twos, twos+n, twos_cmp);
    //for (int i = 0; i < n; i++) printf ("two %d\n", twos[i].two);

    bool stuck = false;
    int c_one = 0, c_two = 0, ans = 0, stars = 0;
    while (!stuck && c_two < n) {
      stuck = true;
      // try two-level first
      while (c_two < n && twos[c_two].two <= stars) {
        stuck = false;
        stars += (2 - done[twos[c_two].idx]);
        //printf ("%d %d %d\n", twos[c_two].idx, twos[c_two].two, stars);
        done[twos[c_two].idx] = 2;
        c_two++;
        ans++;
      }
      //printf ("break %d %d %d\n", c_two, twos[c_two].two, stars);

      // then try one-level
      while (c_one < n && done[ones[c_one].idx] != 0) c_one++;
      int max_two = -1, find = c_one, best = 0;
      while (ones[find].one <= stars && find < n) {
        if (done[ones[find].idx] != 0) goto finish;

        if (ones[find].two > max_two) {
          max_two = ones[find].two;
          best = find;
        }

finish:
        find++;
      }
      if (max_two >= 0) {
        //printf ("%d %d %d\n", ones[c_one].idx, ones[c_one].one, stars);
        stuck = false;
        stars++;
        done[ones[best].idx] = 1;
        ans++;
      }
    }
    printf ("Case #%d: ", i_test+1);
    if (stuck) printf ("Too Bad\n");
    else printf ("%d\n", ans);
  }
}
