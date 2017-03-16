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


lglg euclid(lglg a, lglg b) {
  lglg t;
  while(b) {
    t = a % b;
    a = b;
    b = t;


  }

  return a;
}

void solve() {
  lglg p, q;
  scanf("%I64d/%I64d", &p, &q);

  lglg div = euclid(p, q);

  p /= div;
  q /= div;

  int qlog = 0, plog = 0;

  while(q > 0) {
    if(q > 1 && (q & 1)) {
      printf("impossible\n");
      return;
    }

    ++qlog;

    q /= 2ll;
  }

  while(p > 0) {
    ++plog;
    p /= 2ll;
  }

  printf("%d\n", qlog-plog);
}

int main()
{
  int T;
  scanf("%d", &T);

  for(int t = 0; t < T; ++t) {
    printf("Case #%d: ", t+1);

    solve();
  }

  return 0;
}
