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

    vector<int> plates;
    for(int i = 0; i < n; ++i) {
      int p;
      scanf("%d", &p);
      plates.push_back(p);
    }

    int biggest = *max_element(plates.begin(), plates.end());
    int best = biggest;
    for(int S = 1; S < biggest; ++S){
      int steps = 0;
      for(int p : plates) {
        steps += (p - 1) / S;
      }
      best = min(best, steps + S);
    }

    printf("%d\n", best);

  }

  return 0;
}
