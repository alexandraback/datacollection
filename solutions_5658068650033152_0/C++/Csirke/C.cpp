#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long lglg;

int limitABnot[1002], limitBC[1002];

void solve() {
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);

  if(n > m) swap(n, m);

  // narrow
  if(n <= 2 || k < 5) {
    printf("%d\n", k);
    return;
  }

  int t = n * m;

  int res;
  int cover;

  if(k <= limitBC[n]) { // C
    res = 4;
    cover = 5;
    if(cover == k - 1) {
      ++res;
      ++cover;
    }
    for(int i = 4; cover < k; ++i) {
      cover += ((i-1) / 2) * 2 + 1;
      res += 2;
      if(cover == k - 1) {
        ++res;
        ++cover;
      }
    }
  } else if (k < t - limitABnot[n]) { // B
    res = 2 * n - 2;
    cover = limitBC[n];
    if(cover == k - 1) {
      ++res;
      ++cover;
    }
    while(cover < k) {
      res += 2;
      cover += n;
      if(cover == k - 1) {
        ++res;
        ++cover;
      }
    }


  } else { // A
    cover = t;
    res = 2 * n + 2 * m - 4;

    for(int i = 0; cover >= k; ++i) {
      --res;
      cover -= (i/4) + 1;
    }

    ++res;
  }

  printf("%d\n", res);

}

int main()
{
  limitBC[3] = 5;
  for(int i = 4; i <= 1000; ++i) {
    limitBC[i] = limitBC[i-1] + ((i-1) / 2) * 2 + 1;
  }

  limitABnot[3] = 4;
  for(int i = 4; i <= 1000; ++i) {
    limitABnot[i] = limitABnot[i-1] + (i / 2) * 2;
  }


  int T;
  scanf("%d", &T);

  for(int t = 0; t < T; ++t) {
    printf("Case #%d: ", t+1);

    solve();
  }

  return 0;
}
