#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()

using namespace std;
typedef pair<int, int> pii;

void test_case(int test_no) {
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", &a[i], &b[i]);

  vector<int> stars(n, 0);
  int ans = 0, total_stars = 0;
  while (true) {
    bool done_2stars = false;
    for (int i = 0; i < n; ++i) {
      if (stars[i] < 2 && total_stars >= b[i]) {
        done_2stars = true;
        ++ans;
        total_stars += 2 - stars[i];
        stars[i] = 2;
        //cerr << "star: " << i << " get: 2\n";
        break;
      }
    }
    if (done_2stars) {
      continue;
    }
    int besti = -1;
    for (int i = 0; i < n; ++i) {
      if (stars[i] == 0 && total_stars >= a[i] && (besti == -1 || (b[besti] < b[i]))) {
        besti = i;
      }
    }
    if (besti == -1)
      break;
    //cerr << "star: " << besti << " get: 1\n";
    stars[besti] = 1;
    ++ans;
    ++total_stars;
  }

  printf ("Case #%d: ", test_no);
  if (total_stars != 2 * n) {
    printf ("Too Bad\n");
  } else {
    printf ("%d\n", ans);
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int ti = 0; ti < T; ++ti) {
    test_case(ti + 1);
  }
  return 0;
}
