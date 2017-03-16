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

    int m;
    scanf("%d ", &m);

    int need = 0;
    int have = 0;
    for(int i = 0; i <= m; ++i) {
      char ch;
      scanf("%c", &ch);
      int num = ch - '0';
//      printf("\nnum %d : %d\n", i, num);
      if(have < i) {
        ++need;
        ++have;
      }

      have += num;
    }
    printf("%d\n", need);
  }

  return 0;
}

