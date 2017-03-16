#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

int main() {
  int n_tests;
  cin >> n_tests;
  for (int i_test = 0; i_test < n_tests; i_test++) {
    long long a, n;
    cin >> a >> n;

    long long mote[n];
    for (int i = 0; i < n; i++) cin >> mote[i];
    sort(mote, mote + n);

    if (a == 1) {
      long long ans = n;
      printf("Case #%d: %lld\n", i_test+1, ans);
      continue;
    }

    // choices[i][0] => adding, choices[i][1] => subtract
    long long choices[n][2];

    long long ans = n;
    for (int i = 0; i < n; i++) {
      long long tmp = mote[i];

      // add
      long long add = 0;
      while (tmp >= a) {
        a += a - 1;
        add++;
      }
      a += tmp;

      if (i == 0) choices[i][0] = add;
      else choices[i][0] = add + choices[i - 1][0];

      // subtract
      if (i == 0) choices[i][1] = n;
      else choices[i][1] = n - i + choices[i - 1][0];

      ans = MIN(ans, choices[i][1]);
    }
    ans = MIN(ans, choices[n - 1][0]);

    printf("Case #%d: %lld\n", i_test+1, ans);
  }
}
