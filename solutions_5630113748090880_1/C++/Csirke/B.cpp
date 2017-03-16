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
    printf("Case #%d:", t+1);

    int n;

    scanf("%d", &n);

    vector<int> count = vector<int>(2520, 0);

    int height;
    for (int i = 0; i < 2*n-1; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%d", &height);
        ++count[height];
      }
    }

    for (int i = 0; i < 2510; ++i) {
      if(count[i] % 2) {
        printf(" %d", i);
      }
    }

    printf("\n");
  }

  return 0;
}
