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

int main()
{
  int T;
  scanf("%d", &T);

  for(int t = 0; t < T; ++t) {
    printf("Case #%d: ", t+1);

    int n;
    scanf("%d", &n);

    vector<int> bff(n);
    for (int i = 0; i < n; ++i) {
      int r;
      scanf("%d", &r);
      bff[i] = r - 1;
    }

    vector<int> num;
    vector<int> chain(n, 0);

    int best = -1;

    set<pair<int, int>> pairs;

    for (int i = 0; i < n; ++i) {
      num = vector<int>(n, -1);
      int pos = i;
      int move = 0;
      num[pos] = 0;
      while(num[bff[pos]] < 0) {
        chain[pos] = max(chain[pos], move);
        pos = bff[pos];
        num[pos] = ++move;
      }
      int len = move + 1 - num[bff[pos]];
      if(len > best) {
        best = len;
      }
      if(len == 2) {
        if(pos < bff[pos]) {
          pairs.insert({pos, bff[pos]});
        } else {
          pairs.insert({bff[pos], pos});
        }
      }

    }

//    for(pair<int, int> p : pairs) {
//      printf("\n%d %d %d %d\n", p.first + 1, chain[p.first], p.second + 1, chain[p.second]);
//    }

    if(pairs.size() > 0) {
      int val = 0;
      for(pair<int, int> p : pairs) {
        val += chain[p.first] + chain[p.second] + 2;
      }

      best = max(best, val);

    }


    printf("%d\n", best);
  }

  return 0;
}
